// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankBarrel.h"
#include "TankTurrent.h"
#include "Projectile.h"



// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	//TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
	//TankMovementComponent = CreateDefaultSubobject<UTankMovementComponent>(FName("Movement Component"));

}



//void ATank::AimAt(FVector HitLocation) {
//	if (!ensure(TankAimingComponent)) { return; }
//	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
//
//}

//void ATank::SetBarrelReference(UTankBarrel * BarrelToSet)
//{
//	Barrel = BarrelToSet;
//	TankAimingComponent->SetBarrelReference(BarrelToSet);
//}
//
//void ATank::SetTurrentReference(UTankTurrent * TurrentToSet)
//{
//	TankAimingComponent->SetTurrentReference(TurrentToSet);
//}

// Called when the game starts or when spawned
//void ATank::BeginPlay()
//{
//	Super::BeginPlay();
//	
//}

// Called to bind functionality to input
//void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
//{
//	Super::SetupPlayerInputComponent(PlayerInputComponent);
//
//}