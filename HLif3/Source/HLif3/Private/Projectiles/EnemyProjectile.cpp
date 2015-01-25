// Fill out your copyright notice in the Description page of Project Settings.

#include "HLif3.h"
#include "EnemyProjectile.h"

#define _DefaultMesh 0
#define _Mesh_Type0 0.0
#define _Mesh_Type1 1.0
#define _Mesh_Type2 2.0
#define _Mesh_Type3 3.0
#define _Mesh_Type4 4.0
#define _Mesh_Type5 5.0
#define _Mesh_Type6 6.0
#define _Mesh_Type7 7.0

AEnemyProjectile::AEnemyProjectile(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	Type = EProjectileType::Type1;
	ActualMesh = ObjectInitializer.CreateAbstractDefaultSubobject<USkeletalMeshComponent>(this, "enemy mesh");
	RootComponent = ActualMesh;
	Monsters = TArray<USkeletalMesh*>();
}

void AEnemyProjectile::SetProperties(uint32 NewId, EProjectileType NewType)
{
	Id = NewId;
	Type = NewType;
	UpdateMesh();
	Descriptor = GetDefaultDescriptor(NewType);
}

uint32 AEnemyProjectile::GetId()
{
	return Id;
}

void AEnemyProjectile::UpdateMesh()
{
	USkeletalMesh* m = nullptr;
	switch (Type)
	{
	case EProjectileType::Type1:
		if (Monsters.IsValidIndex(_Mesh_Type0)) {
			m = Monsters[_Mesh_Type0];
		}
		break;
	case EProjectileType::Type2:
		if (Monsters.IsValidIndex(_Mesh_Type1)) {
			m = Monsters[_Mesh_Type1];
		}
		break;
	case EProjectileType::Type3:
		if (Monsters.IsValidIndex(_Mesh_Type2)) {
			m = Monsters[_Mesh_Type2];
		}
		break;
	case EProjectileType::Type4:
		if (Monsters.IsValidIndex(_Mesh_Type3)) {
			m = Monsters[_Mesh_Type3];
		}
		break;
	case EProjectileType::Type5:
		if (Monsters.IsValidIndex(_Mesh_Type4)) {
			m = Monsters[_Mesh_Type4];
		}
		break;
	case EProjectileType::Type6:
		if (Monsters.IsValidIndex(_Mesh_Type5)) {
			m = Monsters[_Mesh_Type5];
		}
		break;
	case EProjectileType::Type7:
		if (Monsters.IsValidIndex(_Mesh_Type6)) {
			m = Monsters[_Mesh_Type6];
		}
		break;
	default:
		if (Monsters.Num() > _DefaultMesh && Monsters[_DefaultMesh]) {
			m = Monsters[_DefaultMesh];
		}
		break;
	}
	if (m != nullptr) {
		ActualMesh->SetSkeletalMesh(m);
	}
}

FEnemyDescriptor AEnemyProjectile::GetDefaultDescriptor(EProjectileType Type)
{
	FEnemyDescriptor d = FEnemyDescriptor();	//default values
	switch (Type)
	{
	case EProjectileType::Type1:	//SPAM can
		d.Health = 3;
		d.Speed = 1.0f;
		d.Movement = EMovementType::Flying;
		d.Target = EEnemyTarget::Environment;
		d.Attak = EEnemyAttakType::Kamikaze;
		break;
	case EProjectileType::Type2:	//DickTits
		d.Health = 3;
		d.Speed = 1.0f;
		d.Movement = EMovementType::Walking;
		d.Target = EEnemyTarget::Environment;
		d.Attak = EEnemyAttakType::PhisicalDamage;
		break;
	case EProjectileType::Type3:	//loadingIcon
		d.Health = 1;
		d.Speed = 0.9f;
		d.Movement = EMovementType::Flying;
		d.Target = EEnemyTarget::Player;
		d.Attak = EEnemyAttakType::Kamikaze;
		break;
	case EProjectileType::Type4:	//pedobear
		d.Health = 20;
		d.Speed = 1.0f;
		d.Movement = EMovementType::Walking;
		d.Target = EEnemyTarget::Environment;
		d.Attak = EEnemyAttakType::Fire;
		break;
	case EProjectileType::Type5:	//pony
		d.Health = 1;
		d.Speed = 1.0f;
		d.Movement = EMovementType::Walking;
		d.Target = EEnemyTarget::Enemies;
		d.Attak = EEnemyAttakType::Buff;
		break;
	case EProjectileType::Type6:	//dolphin
		d.Health = 1;
		d.Speed = 1.0f;
		d.Movement = EMovementType::Walking;
		d.Target = EEnemyTarget::EnemiesOrPlayer;
		d.Attak = EEnemyAttakType::Debuf;
		break;
	case EProjectileType::Type7:
		
		break;
	default:
		
		break;
	}
	return d;
}