// Copyright David Tootell 2018

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class ATank;


/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:
	// Called every frame
	virtual void Tick( float DeltaTime ) override;

private:

	virtual void BeginPlay() override;

	// How close can the AI tank get to the player.
	float AcceptanceRadius = 3000;
};
