// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnWithCamera.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
// Sets default values
APawnWithCamera::APawnWithCamera()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootSceneComponent"));
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMeshComp->SetupAttachment(RootComponent);
	
	SprintArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SprintArmComp->SetupAttachment(StaticMeshComp);

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponet"));
	CameraComp->SetupAttachment(SprintArmComp, USpringArmComponent::SocketName);

	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void APawnWithCamera::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APawnWithCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    
    FRotator NewRotation = GetActorRotation();
    NewRotation.Yaw += CameraInput.X;
    SetActorRotation(NewRotation);
    

// 旋转摄像机的俯仰角度，但对其进行限制，确保我们始终朝下看
    
    FRotator NewArmRotation = SprintArmComp->GetComponentRotation();
    NewArmRotation.Pitch = FMath::Clamp(NewArmRotation.Pitch + CameraInput.Y, -80.0f, -15.0f);
    SprintArmComp->SetWorldRotation(NewArmRotation);
    

// 根据"MoveX"和"MoveY"的处理移动
    
    if (!MovementInput.IsZero())
    {
        //Scale our movement input axis values by 100 units per second
        MovementInput = FVector2D(MovementInput.X* 100.0f, MovementInput.Y * 100.0f);
        FVector NewLocation = GetActorLocation();
        NewLocation += GetActorForwardVector() * MovementInput.X * DeltaTime;
        NewLocation += GetActorRightVector() * MovementInput.Y * DeltaTime;
        SetActorLocation(NewLocation);
    }    
}

// Called to bind functionality to input
void APawnWithCamera::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
    // 分别为四个方向轴的移动事件绑定函数
    InputComponent->BindAxis("MoveForward", this, &APawnWithCamera::MoveForward);
    InputComponent->BindAxis("MoveRight", this, &APawnWithCamera::MoveRight);
    InputComponent->BindAxis("LookUp", this, &APawnWithCamera::PitchCamera);
    InputComponent->BindAxis("Turn", this, &APawnWithCamera::YawCamera);
}

// 输入函数
void APawnWithCamera::MoveForward(float AxisValue)
{
    MovementInput.X = FMath::Clamp<float>(AxisValue, -1.0f, 1.0f);
}

void APawnWithCamera::MoveRight(float AxisValue)
{
    MovementInput.Y = FMath::Clamp<float>(AxisValue, -1.0f, 1.0f);
}

void APawnWithCamera::PitchCamera(float AxisValue)
{
    CameraInput.Y = -AxisValue;
}

void APawnWithCamera::YawCamera(float AxisValue)
{
    CameraInput.X = AxisValue;
}
