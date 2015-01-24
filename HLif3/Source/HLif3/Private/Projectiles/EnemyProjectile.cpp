// Fill out your copyright notice in the Description page of Project Settings.

#include "HLif3.h"
#include "EnemyProjectile.h"

#define _DefaultMesh 0
#define _Mesh_Type0 0
#define _Mesh_Type1 1
#define _Mesh_Type2 2
#define _Mesh_Type3 3
#define _Mesh_Type4 4
#define _Mesh_Type5 5
#define _Mesh_Type6 6
#define _Mesh_Type7 7

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
		if (!(Monsters.Num() < _Mesh_Type0) && Monsters[_Mesh_Type0]) {
			m = Monsters[_Mesh_Type0];
		}
		break;
	case EProjectileType::Type2:
		if (!(Monsters.Num() < _Mesh_Type1) && Monsters[_Mesh_Type1]) {
			m = Monsters[_Mesh_Type1];
		}
		break;
	case EProjectileType::Type3:
		if (!(Monsters.Num() < _Mesh_Type2) && Monsters[_Mesh_Type2]) {
			m = Monsters[_Mesh_Type2];
		}
		break;
	case EProjectileType::Type4:
		if (!(Monsters.Num() < _Mesh_Type3) && Monsters[_Mesh_Type3]) {
			m = Monsters[_Mesh_Type3];
		}
		break;
	case EProjectileType::Type5:
		if (!(Monsters.Num() < _Mesh_Type4) && Monsters[_Mesh_Type4]) {
			m = Monsters[_Mesh_Type4];
		}
		break;
	case EProjectileType::Type6:
		if (!(Monsters.Num() < _Mesh_Type5) && Monsters[_Mesh_Type5]) {
			m = Monsters[_Mesh_Type5];
		}
		break;
	case EProjectileType::Type7:
		if (!(Monsters.Num() < _Mesh_Type6) && Monsters[_Mesh_Type6]) {
			m = Monsters[_Mesh_Type6];
		}
		break;
	default:
		if (!(Monsters.Num() < _DefaultMesh) && Monsters[_DefaultMesh]) {
			m = Monsters[_DefaultMesh];
		}
		break;
	}
	if (m) {
		ActualMesh->SetSkeletalMesh(m);
	}
}