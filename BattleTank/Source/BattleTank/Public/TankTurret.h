// Copyright David Tootell 2018

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS( meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()

public:

	void Rotate( float RelativeSpeed );

private:
	// Sets the maximum degrees per second the barrel can move.
	UPROPERTY( EditAnywhere, Category = Setup )
		float MaxDegPerSecond = 25.0f;
	
	
	
};
