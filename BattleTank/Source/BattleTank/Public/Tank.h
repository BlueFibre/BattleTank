// Copyright David Tootell 2018

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankAimingComponent;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UTankAimingComponent* TankAimingComponent = nullptr;


public:	

	void AimAt( FVector HitLocation );

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference( UTankBarrel* BarrelToSet );

	UPROPERTY( EditAnywhere, Category = Firing )
	float LaunchSpeed = 8000.0f; // TODO find sensible default

private:
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
