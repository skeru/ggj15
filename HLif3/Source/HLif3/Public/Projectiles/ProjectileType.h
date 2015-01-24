// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CustomUtils/DebugUtils.h"
#include "ProjectileType.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EProjectileType : uint8
{
	Type1		UMETA(DisplayName = "Type 1"),
	Type2		UMETA(DisplayName = "Type 2")
};

//#define PathMesh1 "StaticMesh'/Game/Meshes/TemplateCube_Rounded.TemplateCube_Rounded'"
//#define PathMesh2 "StaticMesh'/Game/Meshes/TemplateCube_Rounded.TemplateCube_Rounded'"
////#define PathMesh3 ""
////#define PathMesh4 ""
////#define PathMesh5 ""
////#define PathMesh6 ""
////#define PathMesh7 ""
////#define PathMesh8 ""
//#ifdef PathMesh1
//static ConstructorHelpers::FObjectFinder <UStaticMesh>StaticMesh1(TEXT(PathMesh1));
//#endif
//#ifdef PathMesh2
//static ConstructorHelpers::FObjectFinder <UStaticMesh>StaticMesh2(TEXT(PathMesh2));
//#endif
//#ifdef PathMesh3
//static ConstructorHelpers::FObjectFinder <UStaticMesh>StaticMesh3(TEXT(PathMesh3));
//#endif
//#ifdef PathMesh4
//static ConstructorHelpers::FObjectFinder <UStaticMesh>StaticMesh4(TEXT(PathMesh4));
//#endif
//#ifdef PathMesh5
//static ConstructorHelpers::FObjectFinder <UStaticMesh>StaticMesh5(TEXT(PathMesh5));
//#endif
//#ifdef PathMesh6
//static ConstructorHelpers::FObjectFinder <UStaticMesh>StaticMesh6(TEXT(PathMesh6)); 
//#endif
//#ifdef PathMesh7
//static ConstructorHelpers::FObjectFinder <UStaticMesh>StaticMesh7(TEXT(PathMesh7));
//#endif
//#ifdef PathMesh8
//static ConstructorHelpers::FObjectFinder <UStaticMesh>StaticMesh8(TEXT(PathMesh8));
//#endif
//
//
//static UStaticMesh* GetMesh(EProjectileType type)
//{
//	switch (type)
//	{
//#define _CASE_MESH(staticmesh){\
//	if (!(staticmesh).Object) {\
//		DebugUtils::LogString(FString("Static Mesh not found"));\
//		return nullptr;\
//	}\
//	else {\
//		return (staticmesh).Object;\
//	}\
//	}
//#ifdef PathMesh1
//	case EProjectileType::Type1:
//		_CASE_MESH(StaticMesh1)
//		break;
//#endif
//#ifdef PathMesh2
//	case EProjectileType::Type2:
//		_CASE_MESH(StaticMesh2)
//		break;
//#endif
//	default:
//		DebugUtils::LogString("Projectile-Mesh Mapping:: invalid type");
//		return nullptr;
//	}
//}
