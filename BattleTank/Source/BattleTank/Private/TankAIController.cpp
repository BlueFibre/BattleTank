// Copyright David Tootell 2018

#include "TankAIController.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	auto PlayerTank = Cast<ATank>( GetWorld()->GetFirstPlayerController()->GetPawn() );
	auto ControlledTank = Cast<ATank>( GetPawn() );

	if (PlayerTank)
	{
		// Move towards the player
		MoveToActor( PlayerTank, AcceptanceRadius );

		//Aim towards the player
		ControlledTank->AimAt( PlayerTank->GetActorLocation() );

		//Fire if ready
		ControlledTank->Fire(); //TODO Limit Firing rate
	}
}


