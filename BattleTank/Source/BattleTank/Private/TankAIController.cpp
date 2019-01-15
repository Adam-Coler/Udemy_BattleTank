// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "BattleTank.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("TankAIController: No AI Tank Possesed"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("TankAIController: AI Tank Possesed %s"), *(ControlledTank->GetName()));
	}

}

ATank* ATankAIController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}