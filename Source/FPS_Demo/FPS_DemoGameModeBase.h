// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FPS_DemoGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class FPS_DEMO_API AFPS_DemoGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
	virtual void StartPlay() override;
};
