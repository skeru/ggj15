// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "GameFramework/Actor.h"
#include "DestructibleProp.generated.h"

/**
 * 
 */
UCLASS()
class HLIF3_API ADestructibleProp : public AActor
{
	GENERATED_BODY()

private:
	/** Maximun Level of Destructibility*/
	float m_maxDestructionLevel = 3;

public:
	/** Actual Level of Destructibility*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = DestructibleProp)
	float DestructionLevel;

	ADestructibleProp(const FObjectInitializer& ObjectInitializer);

	/** called when something enters the sphere component */
	UFUNCTION(BlueprintImplementableEvent, Category = Gameplay)
		void OnDestroyLevelUpdate();

	/** Add up to Level Corruption*/
	UFUNCTION(BlueprintCallable, Category = Gameplay)
		void DestroyPartially(float Value);

	/** Add up to Level Corruption*/
	UFUNCTION(BlueprintCallable, Category = Gameplay)
		void DestroyTotally();

	/** Add up to Level Corruption*/
	UFUNCTION(BlueprintCallable, Category = Gameplay)
		bool IsDestroyed();	
	
};
