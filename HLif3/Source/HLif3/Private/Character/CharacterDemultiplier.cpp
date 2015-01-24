// Fill out your copyright notice in the Description page of Project Settings.

#include "HLif3.h"
#include "HLif3Character.h"
#include "CharacterDemultiplier.h"

void UCharacterDemultiplier::StartApply(class AHLif3Character * Target)
{
	this->OnStartApply(Target);
}

void UCharacterDemultiplier::Apply(class AHLif3Character * Target, float Time)
{
	this->OnApply(Target,Time);
}

void UCharacterDemultiplier::StopApply(class AHLif3Character * Target)
{
	this->StopApply(Target);
}


