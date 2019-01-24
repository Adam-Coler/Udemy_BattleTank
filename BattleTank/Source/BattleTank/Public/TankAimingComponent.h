// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
//#include "TankBarrel.h"
#include "TankAimingComponent.generated.h"

//Enum for aiming state
UENUM()
enum class EFiringStatus : uint8 {
	Reloading,
	Aiming,
	Locked
};

//forward decleration
class UTankBarrel; 
class UTankTurrent;
class AProjectile;

// Hold parametes for barrel
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

protected:

	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringStatus FiringState = EFiringStatus::Reloading;

public:	

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UTankBarrel *BarrelToSet, UTankTurrent *TurrentToSet);

	void AimAt(FVector HitLocation);

	void MoveBarrelTowards(FVector AimDirection);

	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();

	//void SetBarrelReference(UTankBarrel* BarrelToSet);

	//void SetTurrentReference(UTankTurrent* TurrentToSet);

private:
	UTankBarrel* Barrel = nullptr;
	UTankTurrent* Turrent = nullptr;


	UPROPERTY(EditAnywhere, Category = "Firing")
	float LaunchSpeed = 4000; //TODO find sensable default


	UPROPERTY(EditAnywhere, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint; //TODO find sensable default

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3;

	double LastFireTime = ReloadTimeInSeconds * -1;
};
