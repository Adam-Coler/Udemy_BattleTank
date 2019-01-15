// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "BattleTank.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	auto PlayerTank = GetPlayerTank();
	if (!ControlledTank || !PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("TankAIController: Either Player tank not found or Controlled tank not found."));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("TankAIController: AI Tank Possesed %s, Player Tank found: %s"), *(ControlledTank->GetName()), *(PlayerTank->GetName()));
	}

}

ATank* ATankAIController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const {
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerTank) { return nullptr; }
	return Cast<ATank>(PlayerTank);
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

}