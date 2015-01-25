// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "SoundManager.generated.h"

/**
 * 
 */
UCLASS()
class HLIF3_API ASoundManager : public AActor
{

	GENERATED_BODY()

public:

	ASoundManager(const FObjectInitializer& ObjectInitializer);

	/**Call Next Song */
	UFUNCTION(BlueprintCallable, Category = Gameplay)
		void CallNextSong();

	/** Call Previous Song */
	UFUNCTION(BlueprintCallable, Category = Gameplay)
		void CallPreviousSong();

	/** Next Song */
	UFUNCTION(BlueprintImplementableEvent, Category = Gameplay)
		void NextSong();
	/** Previous Song */
	UFUNCTION(BlueprintImplementableEvent, Category = Gameplay)
		void PreviousSong();

	
};
