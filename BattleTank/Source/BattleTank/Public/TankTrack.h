// Copyright David Tootell 2018

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 *  Tank Track is used to set maximum driving force, and apply forces to the tank.
 */
UCLASS( meta = (BlueprintSpawnableComponent) )
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle( float Throttle );

	// This is max force (per track) in Newtons
	UPROPERTY( EditDefaultsOnly, Category = Setup )
		float TrackMaxDrivingForce = 400000.0f; // Assume 40t tank and 1G accelleration (10m/s)
	
};
