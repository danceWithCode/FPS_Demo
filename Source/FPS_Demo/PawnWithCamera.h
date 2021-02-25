// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PawnWithCamera.generated.h"

UCLASS()
class FPS_DEMO_API APawnWithCamera : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APawnWithCamera();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
    //  ‰»Î±‰¡ø
    FVector2D MovementInput;
    FVector2D CameraInput;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    void MoveForward(float AxisValue);
    void MoveRight(float AxisValue);
    void PitchCamera(float AxisValue);
    void YawCamera(float AxisValue);
public:
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMeshComp;

    UPROPERTY(EditAnywhere)
	class UCameraComponent* CameraComp;

    UPROPERTY(EditAnywhere)
	class USpringArmComponent* SprintArmComp;

};
