// Copyright David Tootell 2018

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "TankPlayerController.generated.h"

class ATank;

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

	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector& OutHitLocation) const; // Returns an OUT parameter, true if landscape hit

	UPROPERTY( EditDefaultsOnly )
	float CrosshairXLocation = 0.5f;

	UPROPERTY( EditDefaultsOnly )
	float CrosshairYLocation = 0.33333f;

	bool ATankPlayerController::GetLookDirection( FVector2D ScreenLocation, FVector& LookDirection ) const;
	
	UPROPERTY( EditDefaultsOnly )
	float LineTraceRange = 1000000.0f;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

};

