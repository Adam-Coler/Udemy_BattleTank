// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurrent.h"

void UTankTurrent::Rotate(float RelativeSpeed) {
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto Rotation = RelativeRotation.Yaw + RotationChange;

	SetRelativeRotation(FRotator(0, Rotation, 0));

	//UE_LOG(LogTemp, Warning, TEXT("Report"));


}