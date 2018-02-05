// Copyright David Tootell 2018

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Tank.h"
#include "TankAIController.generated.h"

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
	ATank* GetControlledTank() const;

	ATank* GetPlayerTank() const;
};
