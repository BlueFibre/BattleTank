// Copyright David Tootell 2018

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Tank.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	// Called when game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick( float DeltaTime ) override;
	
private:

	ATank* GetControlledTank() const;

	// Start the tank moving the barrel so that a shot would
	// hit where the corsshair intersects the world.
	void AimTowardsrosshair();

	bool GetSightRayHitLocation(FVector& OutHitLocation) const; // Returns an OUT parameter, true if landscape hit
	
};

