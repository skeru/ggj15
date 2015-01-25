// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "DestructibleProp.h"
#include "CorruptionManager.generated.h"


/**
 * 
 */
UCLASS()
class HLIF3_API ACorruptionManager : public AActor
{
	GENERATED_BODY()

public:

	/** Maximun Level of Corruption*/
	UPROPERTY(BlueprintReadWrite)
	float MaxCorruption = 100;

	ACorruptionManager(const FObjectInitializer& ObjectInitializer);

	/** Level Corruption */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		float CorruptionLevel;

	/** Destructible Index */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		float DestructibleIndex;

	/** Destructibles Lenght */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		float DestructiblesLenght;

	/** Demux Index */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		float DemuxIndex;

	/** Demux Lenght */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		float DemuxLenght;

	/** Demux Levels */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		int32 DemuxLevels[5];


	/** Add up to Level Corruption*/
	UFUNCTION(BlueprintCallable, Category = Gameplay)
		void OnCorruptionIncrease(float value);

	/** Add up to Level Corruption*/
	UFUNCTION(BlueprintCallable, Category = Gameplay)
		bool CanDestroy();
	
	/** called when something enters the sphere component */
	UFUNCTION(BlueprintImplementableEvent, Category = Gameplay)
		void OnCorruptionUpdate();

	/** called when something enters the sphere component */
	UFUNCTION(BlueprintImplementableEvent, Category = Gameplay)
		void ApplyDemux(float Value);

	/** called when something enters the sphere component */
	UFUNCTION(BlueprintImplementableEvent, Category = Gameplay)
		void StopDemux(float Value);

	/** Ends The Game*/
	UFUNCTION(BlueprintImplementableEvent, Category = Gameplay)
		void OnGameEnd();

protected:
	/** Checks Level Corruption if it's over a value*/
	bool IsCorruptionOver(float Value);
	/** Checks if Level Corruption should cause Demux*/
	bool ShouldApplyDemux();
	/** Checks if Level Corruption should stop Demux*/
	bool ShouldStopDemux();

};
