// Fill out your copyright notice in the Description page of Project Settings.

#include "HLif3.h"
#include "ScoreBoard.h"

//////////////////////////////////////////////////////////////////////////
// ScoreBoard

AScoreBoard::AScoreBoard(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	Points = 0.f;
}

void AScoreBoard::AddPoints(float Value)
{
	Points += Value;
}
