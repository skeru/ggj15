// Fill out your copyright notice in the Description page of Project Settings.

#include "HLif3.h"
#include "SoundManager.h"



//////////////////////////////////////////////////////////////////////////
// SoundManager

ASoundManager::ASoundManager(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}


void ASoundManager::CallNextSong()
{
	NextSong();
}

void ASoundManager::CallPreviousSong()
{
	PreviousSong();
}

