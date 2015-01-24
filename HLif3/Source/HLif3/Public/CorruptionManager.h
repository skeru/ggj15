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

private:
	/** Maximun Level of Corruption*/
	float m_maxCorruption = 100;
	
public:
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

	/** Add up to Level Corruption*/
	UFUNCTION(BlueprintCallable, Category = Gameplay)
		void OnCorruptionIncrease(float value);

	/** Add up to Level Corruption*/
	UFUNCTION(BlueprintCallable, Category = Gameplay)
		bool CanDestroy();
	
	/** called when something enters the sphere component */
	UFUNCTION(BlueprintImplementableEvent, Category = Gameplay)
		void OnCorruptionUpdate();

	/** Ends The Game*/
	UFUNCTION(BlueprintImplementableEvent, Category = Gameplay)
		void OnGameEnd();

protected:
	/** Checks Level Corruption if it's over a value*/
	bool IsCorruptionOver(float Value);

};
