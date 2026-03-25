// Fill out your copyright notice in the Description page of Project Settings.

#include "MyActor.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/Engine.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	for (int i = 0; i < 10; i++)
	{
		float RandomDistance = FMath::FRandRange(100.f, 500.f);
		float RandomAngle = FMath::FRandRange(-180.f, 180.f);

		Move(RandomDistance);
		Turn(RandomAngle);
	}
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyActor::Move(float Distance)
{
	FVector CurrentLocation = GetActorLocation();

	FVector ForwardVector = GetActorForwardVector();
	FVector NewLocation = CurrentLocation + (ForwardVector * Distance);

	SetActorLocation(NewLocation);

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(
			-1,
			2.0f,
			FColor::Green,
			FString::Printf(TEXT("Location: X=%.2f Y=%.2f Z=%.2f"),
				NewLocation.X, NewLocation.Y, NewLocation.Z)
		);
	}
}

void AMyActor::Turn(float Angle)
{
	FRotator CurrentRotation = GetActorRotation();

	FRotator NewRotation = CurrentRotation;
	NewRotation.Yaw += Angle;

	SetActorRotation(NewRotation);

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(
			-1,
			2.0f,
			FColor::Yellow,
			FString::Printf(TEXT("Rotation Yaw: %.2f"), NewRotation.Yaw)
		);
	}
}