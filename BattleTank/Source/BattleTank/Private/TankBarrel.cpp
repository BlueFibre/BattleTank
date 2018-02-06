// Copyright David Tootell 2018

#include "TankBarrel.h"

void UTankBarrel::Elevate( float DegPerSecond )
{
	//Move the barrel the right amount this frame, given a max elevation speed + DeltaTime
	UE_LOG( LogTemp, Warning, TEXT( "Barrel->Elevate() called at speed %f" ), DegPerSecond );
}


