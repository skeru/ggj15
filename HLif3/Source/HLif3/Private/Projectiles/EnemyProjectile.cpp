// Fill out your copyright notice in the Description page of Project Settings.

#include "HLif3.h"
#include "EnemyProjectile.h"

#define _DefaultMesh "StaticMesh'/Game/Meshes/TemplateCube_Rounded.TemplateCube_Rounded'"

AEnemyProjectile::AEnemyProjectile(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	Type = EProjectileType::Type1;
	mesh = ObjectInitializer.CreateAbstractDefaultSubobject<UStaticMeshComponent>(this, "ball mesh");
#ifdef _DefaultMesh
	static ConstructorHelpers::FObjectFinder <UStaticMesh>StaticMesh(TEXT(_DefaultMesh));
	if (!StaticMesh.Object) {
		DebugUtils::LogString(FString("Static Mesh not found"));
	}
	else {
		mesh->SetStaticMesh(StaticMesh.Object);
	}
	mesh->SetRelativeScale3D(FVector(25, 25, 25));
#endif
	RootComponent = mesh;

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
	UStaticMesh* m = GetMesh(Type);
	if (m) {
		mesh->SetStaticMesh(m);
	}
}