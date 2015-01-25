// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "HLif3.h"
#include "HLif3Character.h"
#include "HLif3Projectile.h"
#include "Character/CharacterDemultiplier.h"
#include "Animation/AnimInstance.h"


//////////////////////////////////////////////////////////////////////////
// AHLif3Character

AHLif3Character::AHLif3Character(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Create a CameraComponent	
	FirstPersonCameraComponent = ObjectInitializer.CreateDefaultSubobject<UCameraComponent>(this, TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->AttachParent = GetCapsuleComponent();
	FirstPersonCameraComponent->RelativeLocation = FVector(0, 0, 64.f); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// Default offset from the character location for projectiles to spawn
	GunOffset = FVector(100.0f, 30.0f, 10.0f);

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	Mesh1P = ObjectInitializer.CreateDefaultSubobject<USkeletalMeshComponent>(this, TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);			// only the owning player will see this mesh
	Mesh1P->AttachParent = FirstPersonCameraComponent;
	Mesh1P->RelativeLocation = FVector(0.f, 0.f, -150.f);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;

	// Note: The ProjectileClass and the skeletal mesh/anim blueprints for Mesh1P are set in the
	// derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

//////////////////////////////////////////////////////////////////////////
// Input

void AHLif3Character::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	// set up gameplay key bindings
	check(InputComponent);

	InputComponent->BindAction("Jump", IE_Pressed, this, &AHLif3Character::ExecuteJump);
	InputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	
	InputComponent->BindAction("Fire", IE_Pressed, this, &AHLif3Character::OnFire);
	InputComponent->BindTouch(EInputEvent::IE_Pressed, this, &AHLif3Character::TouchStarted);

	InputComponent->BindAxis("MoveForward", this, &AHLif3Character::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AHLif3Character::MoveRight);
	
	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	InputComponent->BindAxis("Turn", this, &AHLif3Character::AddYawInput);
	InputComponent->BindAxis("TurnRate", this, &AHLif3Character::TurnAtRate);
	InputComponent->BindAxis("LookUp", this, &AHLif3Character::AddPitchInput);
	InputComponent->BindAxis("LookUpRate", this, &AHLif3Character::LookUpAtRate);
}

void AHLif3Character::OnFire()
{
	if (FireDisabled)
	{
		return;
	}

	// try and fire a projectile
	if (ProjectileClass != NULL)
	{
		const FRotator SpawnRotation = GetControlRotation();
		// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
		const FVector SpawnLocation = GetActorLocation() + SpawnRotation.RotateVector(GunOffset);

		UWorld* const World = GetWorld();
		if (World != NULL)
		{
			// spawn the projectile at the muzzle
			World->SpawnActor<AHLif3Projectile>(ProjectileClass, SpawnLocation, SpawnRotation);
		}
	}

	// try and play the sound if specified
	if (FireSound != NULL)
	{
		UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
	}

	// try and play a firing animation if specified
	if(FireAnimation != NULL)
	{
		// Get the animation object for the arms mesh
		UAnimInstance* AnimInstance = Mesh1P->GetAnimInstance();
		if(AnimInstance != NULL)
		{
			AnimInstance->Montage_Play(FireAnimation, 1.f);
		}
	}

}

void AHLif3Character::TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	// only fire for first finger down
	if (FingerIndex == 0)
	{
		OnFire();
	}
}

void AHLif3Character::MoveForward(float Value)
{
	if (ForwardDisabled)
	{
		return;
	}

	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void AHLif3Character::MoveRight(float Value)
{
	if (SideDisabled)
	{
		return;
	}

	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorRightVector(), Value);
	}
}

void AHLif3Character::ExecuteJump()
{
	if (JumpDisabled)
	{
		return;
	}

	bPressedJump = true;
	JumpKeyHoldTime = 0.0f;
}

void AHLif3Character::TurnAtRate(float Rate)
{
	if (TurnDisabled)
	{
		return;
	}

	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AHLif3Character::LookUpAtRate(float Rate)
{
	if (LookUpDisabled)
	{
		return;
	}

	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void AHLif3Character::ApplyDemultiplier(UCharacterDemultiplier * Demux)
{
	FCharacterDemultiplierItem item;
	item.Demux = Demux;
	item.StartTime = this->GetWorld()->TimeSeconds;

	Demux->StartApply(this);
	Demuxes.Add(item);
}

void AHLif3Character::Tick(float DeltaSeconds)
{
	for (int i = 0; i < Demuxes.Num(); i++)
	{
		float duration = GetWorld()->TimeSeconds - Demuxes[i].StartTime;

		if (Demuxes[i].Demux->OneShot )
		{
			if (Demuxes[i].Demux->DoesEnd)
			{
				Demuxes[i].Demux->StopApply(this);
				Demuxes.RemoveAt(i);
				break;
			}
		}
		else
		{
			Demuxes[i].Demux->Apply(this, duration);

			if (Demuxes[i].Demux->DoesEnd && duration >= Demuxes[i].Demux->Duration)
			{
				Demuxes[i].Demux->StopApply(this);
				Demuxes.RemoveAt(i);
				break;
			}
		}
	}
}

void AHLif3Character::DisableForward(bool Disable)
{
	ForwardDisabled = Disable;
}

void AHLif3Character::DisableSide(bool Disable)
{
	SideDisabled = Disable;
}

void AHLif3Character::DisableJump(bool Disable)
{
	JumpDisabled = Disable;
}

void AHLif3Character::DisableFire(bool Disable)
{
	FireDisabled = Disable;
}

void AHLif3Character::DisableLookUp(bool Disable)
{
	LookUpDisabled = Disable;
}

void AHLif3Character::DisableTurn(bool Disable)
{
	TurnDisabled = Disable;
}

void AHLif3Character::AddYawInput(float Val)
{
	if (TurnDisabled)
	{
		return;
	}

	this->AddControllerYawInput(Val);
}

void AHLif3Character::AddPitchInput(float Val)
{
	if (LookUpDisabled)
	{
		return;
	}

	this->AddControllerPitchInput(Val);
}