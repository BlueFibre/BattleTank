// Copyright David Tootell 2018

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS( meta = (BlueprintSpawnableComponent), hidecategories = ("Collision") )
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate( float DegPerSecond );

private:
	// Sets the maximum degrees per second the barrel can move.
	UPROPERTY( EditAnywhere, Category = Setup )
		float MaxDegPerSecond = 20.0f; 

	// Sets the maximum elevation the barrel can reach.
	UPROPERTY( EditAnywhere, Category = Setup )
		float MaxElevationDeg = 40.0f;

	// Sets the minimum elevation the barrel can reach.
	UPROPERTY( EditAnywhere, Category = Setup )
		float MinElevationDeg = 0.0f;
	
};
