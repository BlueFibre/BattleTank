// Copyright David Tootell 2018

#include "TankTurret.h"
#include "Engine/World.h"

void UTankTurret::Rotate( float RelativeSpeed )
{
	//Clamp RelativeSpeed between -1 and 1.
	RelativeSpeed = FMath::Clamp<float>( RelativeSpeed, -1.0f, 1.0f );

	auto RotationChange = RelativeSpeed * MaxDegPerSecond * GetWorld()->DeltaTimeSeconds; // error here
	auto NewRotation = RelativeRotation.Yaw + RotationChange;

	SetRelativeRotation( FRotator( 0, NewRotation, 0 ) );
}


