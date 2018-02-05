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
		UE_LOG( LogTemp, Warning, TEXT( "Hit Location %s, " ), *HitLocation.ToString() );
		//if hits the landscape
			//TODO aim at this point
	}
}

// Get world location of linetrace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation( FVector& HitLocation ) const
{

	// Find the crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize( ViewportSizeX, ViewportSizeY );
	auto ScreenLocation = FVector2D( ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation );
		
	// De-Project the screen position of the crosshair to a world direction
	FVector LookDirection;
	if (GetLookDirection( ScreenLocation, LookDirection ))
	{
		// line trace along that look direction, and see what we hit (upto max range)
		return GetLookVectorHitLocation( LookDirection, HitLocation );
	}
	return false;
}

bool ATankPlayerController::GetLookDirection( FVector2D ScreenLocation, FVector& LookDirection ) const
{
	FVector CameraWorldLocation; // To be discarded
	return DeprojectScreenPositionToWorld( ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection );
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	FVector StartLocation = PlayerCameraManager->GetCameraLocation();
	FVector EndLocation = StartLocation + (LookDirection * LineTraceRange);

	if( GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECollisionChannel::ECC_Visibility ) )
		{
			HitLocation = HitResult.Location;
			return true;
		}

	return false;
}
