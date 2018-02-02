// Copyright David Tootell 2018

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG( LogTemp, Warning, TEXT( "TankAIController not possesing a tank" ) );
	}
	else
	{
		UE_LOG( LogTemp, Warning, TEXT( "TankAIController: %s" ), *(ControlledTank->GetName()) );
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>( GetPawn() );
}


