// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CustomUtils.h"

#define ENABLE_DEBUG
#define ENABLE_LOG
//#define ENABLE_ON_SCREEN_DEBUG

/**
 * Just Debug utilities.
 */
namespace DebugUtils{
	inline static void LogString(FString str)
	{
#ifdef ENABLE_LOG
		UE_LOG(LogTemp, Log, TEXT("%s"), *Utils::CustomUnquote(str));
#endif
	}
}

#ifdef ENABLE_DEBUG
#ifdef ENABLE_ON_SCREEN_DEBUG
#define DEBUG(msg) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, (msg));
#else
#define DEBUG(msg) DebugUtils::LogString(FString((msg)));
#endif
#else
#define DEBUG(msg) ;
#endif