// Copyright David Tootell 2018

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"


/**
 * 
 */
UCLASS( meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 is max downwards movement, +1 is max upwards movement
	void Elevate( float RelativeSpeed );

private:
	// Sets the maximum degrees per second the barrel can move.
	UPROPERTY( EditDefaultsOnly, Category = Setup )
		float MaxDegPerSecond = 10.0f; 

	// Sets the maximum elevation the barrel can reach.
	UPROPERTY( EditDefaultsOnly, Category = Setup )
		float MaxElevationDeg = 40.0f;

	// Sets the minimum elevation the barrel can reach.
	UPROPERTY( EditDefaultsOnly, Category = Setup )
		float MinElevationDeg = 0.0f;
	
};
