// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"

/**
 * 
 */
class ProjectileListener
{
public:
	virtual void EventHit(AActor* OtherActor) {};
};
