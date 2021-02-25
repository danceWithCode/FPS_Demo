// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PawnWithCameraGameMode.generated.h"

/**
 * 
 */
UCLASS()
class FPS_DEMO_API APawnWithCameraGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual void StartPlay();
};
