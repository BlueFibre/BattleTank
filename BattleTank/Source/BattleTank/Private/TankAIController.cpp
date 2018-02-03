// Copyright David Tootell 2018

#include "TankAIController.h"
#include "Runtime/Engine/Classes/Engine/World.h"

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

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>( GetPawn() );
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	return Cast<ATank>( PlayerPawn );
}


