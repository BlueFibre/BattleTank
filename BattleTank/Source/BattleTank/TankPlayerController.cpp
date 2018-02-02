// Copyright David Tootell 2018

#include "TankPlayerController.h"


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>( GetPawn() );
}
