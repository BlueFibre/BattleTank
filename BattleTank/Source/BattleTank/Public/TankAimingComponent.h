// Copyright David Tootell 2018

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "TankAimingComponent.generated.h"

// Forward Declaration
class UTankBarrel; 

// Holds barrel's properties
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void SetBarrelReference( UTankBarrel* BarrelToSet );

	void AimAt( FVector HitLocation, float LaunchSpeed );

private:

	UTankBarrel* Barrel = nullptr;

	void MoveBarrelTowards(FVector AimDirection);
	
};
