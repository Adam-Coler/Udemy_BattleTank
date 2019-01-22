// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

//forward declarations
class UTankBarrel;
class UTankTurrent;
class UTankAimingComponent;
class UTankMovementComponent;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);


	UFUNCTION(BlueprintCallable, Category = "Setup")
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void SetTurrentReference(UTankTurrent* TurrentToSet);

	UFUNCTION(BlueprintCallable)
	void Fire();


protected:
	UTankAimingComponent* TankAimingComponent = nullptr;

	UPROPERTY(BlueprintReadOnly)
	UTankMovementComponent* TankMovementComponent = nullptr;


private:	

	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category = "Firing")
	float LaunchSpeed = 4000; //TODO find sensable default

	UPROPERTY(EditAnywhere, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint; //TODO find sensable default

	UTankBarrel* Barrel = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3;

	double LastFireTime = ReloadTimeInSeconds * -1;
};
