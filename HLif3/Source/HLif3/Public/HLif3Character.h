// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/Character.h"
#include "Array.h"
#include "HLif3Character.generated.h"

class UCharacterDemultiplier;

USTRUCT()
struct FCharacterDemultiplierItem
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	class UCharacterDemultiplier * Demux;

	UPROPERTY()
	float StartTime;
};

UCLASS(config=Game)
class AHLif3Character : public ACharacter
{
	GENERATED_BODY()

	/** Pawn mesh: 1st person view (arms; seen only by self) */
	UPROPERTY(VisibleDefaultsOnly, Category=Mesh)
	class USkeletalMeshComponent* Mesh1P;

	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FirstPersonCameraComponent;

	UPROPERTY()
	TArray<FCharacterDemultiplierItem> Demuxes;

public:
	AHLif3Character(const FObjectInitializer& ObjectInitializer);



	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

	/** Gun muzzle's offset from the characters location */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Gameplay)
	FVector GunOffset;

	/** Projectile class to spawn */
	UPROPERTY(EditDefaultsOnly, Category=Projectile)
	TSubclassOf<class AHLif3Projectile> ProjectileClass;

	/** Sound to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Gameplay)
	class USoundBase* FireSound;

	/** AnimMontage to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	class UAnimMontage* FireAnimation;

	UFUNCTION(BlueprintCallable, Category = "Input Modifier")
	void DisableForward(bool Disable);

	UFUNCTION(BlueprintCallable, Category = "Input Modifier")
	void DisableSide(bool Disable);

	UFUNCTION(BlueprintCallable, Category = "Input Modifier")
	void DisableJump(bool Disable);

	UFUNCTION(BlueprintCallable, Category = "Input Modifier")
	void DisableFire(bool Disable);

	UFUNCTION(BlueprintCallable, Category = "Input Modifier")
	void DisableLookUp(bool Disable);

	UFUNCTION(BlueprintCallable, Category = "Input Modifier")
	void DisableTurn(bool Disable);

protected:

	/** Handler for a touch input beginning. */
	void TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location);

	/** Fires a projectile. */
	void OnFire();

	/** Handles moving forward/backward */
	void MoveForward(float Val);

	/** Handles stafing movement, left and right */
	void MoveRight(float Val);

	void AddYawInput(float Val);

	void AddPitchInput(float Val);

	/**
	 * Called via input to turn at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	void ExecuteJump();

	/**
	 * Called via input to turn look up/down at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	bool ForwardDisabled;

	bool SideDisabled;

	bool FireDisabled;

	bool JumpDisabled;

	bool LookUpDisabled;

	bool TurnDisabled;

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	// End of APawn interface

	virtual void Tick(float DeltaSeconds) override;

public:
	/** Returns Mesh1P subobject **/
	FORCEINLINE class USkeletalMeshComponent* GetMesh1P() const { return Mesh1P; }
	/** Returns FirstPersonCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }

	UFUNCTION(BlueprintCallable, Category = "Malus")
	void ApplyDemultiplier(UCharacterDemultiplier * Demux);
};

