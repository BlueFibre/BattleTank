// Copyright David Tootell 2018

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG( LogTemp, Warning, TEXT( "PlayerController not possesing a tank" ) );
	}
	else
	{
		UE_LOG( LogTemp, Warning, TEXT( "PlayerController: %s" ), *(ControlledTank->GetName()) );
	}
}

void ATankPlayerController::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	AimTowardsrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>( GetPawn() );
}

void ATankPlayerController::AimTowardsrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation; // Out parameter
	if (GetSightRayHitLocation( HitLocation )) // Has a side effect
	{
		UE_LOG( LogTemp, Warning, TEXT( "Hitlocation %s, " ), *HitLocation.ToString() );
		//if hits the landscape
			//TODO aim at this point
	}
}

// Get world location of linetrace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation( FVector& OutHitLocation ) const
{
	//RayCast through crosshair
		// if hit terrain 
			//OUT PARAM location
			//return true
		//else return false

	OutHitLocation = FVector( 1.0 ); // TEMP Returns 1,1,1 as a vector for debugging
	return true;
}

