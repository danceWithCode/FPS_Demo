// Copyright Epic Games, Inc. All Rights Reserved.


#include "FPS_DemoGameModeBase.h"

void AFPS_DemoGameModeBase::StartPlay()
{
    Super::StartPlay();

    check(GEngine != nullptr);

    // ��ʾ������Ϣ���롣 
    // �����е�-1"��"ֵ���Ͳ����ܷ�ֹ����Ϣ�����»�ˢ�¡�
    GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Hello World, this is FPSGameMode!"));

}