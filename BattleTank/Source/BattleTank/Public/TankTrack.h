// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
*Tank Track IS used to set maximum driving force and to move the tank.
*/

UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	//Set Throttle of track
	UFUNCTION(BluePRintCallable, Category = Input)
	void SetThrottle(float Throttle);

	//Max Force per Track in Newtons
	UPROPERTY(EditDefaultsOnly)
	float TrackMaxDrivingForce = 400000.f;  //assume 40 tonne tank and 1g acceleration

};
