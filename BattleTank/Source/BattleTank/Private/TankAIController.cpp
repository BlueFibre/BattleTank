// Copyright David Tootell 2018

#include "TankAIController.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetControlledTank();
	if (!PlayerTank)
	{
		UE_LOG( LogTemp, Warning, TEXT( "TankAIController cant find player tank" ) );
	}
	else
	{
		UE_LOG( LogTemp, Warning, TEXT( "AIController found player tank: %s" ), *(PlayerTank->GetName()) );
	}
}

void ATankAIController::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	if (GetPlayerTank())
	{
		// Move towards the player

		//Aim towards the player
		GetControlledTank()->AimAt( GetPlayerTank()->GetActorLocation() );

		//Fire if ready
	}
}


ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>( GetPawn() );
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	return Cast<ATank>( PlayerPawn );
}


