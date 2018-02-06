// Copyright David Tootell 2018

#include "TankBarrel.h"
#include "Engine/World.h"



void UTankBarrel::Elevate( float RelativeSpeed )
{
	//Clamp RelativeSpeed between -1 and 1.
	RelativeSpeed = FMath::Clamp<float>( RelativeSpeed, -1.0f, 1.0f );
	
	//Move the barrel the right amount this frame, given a max elevation speed + DeltaTime
	auto ElevationChange = RelativeSpeed * MaxDegPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	auto Elevation = FMath::Clamp<float>( RawNewElevation, MinElevationDeg, MaxElevationDeg );

	SetRelativeRotation( FRotator( Elevation, 0, 0 ) );
}


