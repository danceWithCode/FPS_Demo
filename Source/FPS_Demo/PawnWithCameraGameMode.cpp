// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnWithCameraGameMode.h"

void APawnWithCameraGameMode::StartPlay()
{
    Super::StartPlay();

    check(GEngine != nullptr);

    GEngine->AddOnScreenDebugMessage(-1, 5.0F, FColor::Yellow, TEXT("PawnWithCameraGameMode StartPlay."));
}