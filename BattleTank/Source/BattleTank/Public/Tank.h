// Copyright David Tootell 2018

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankTurret;
class UTankAimingComponent;
class AProjectile;

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

	/* SETTERS */
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference( UTankBarrel* BarrelToSet );

	UFUNCTION( BlueprintCallable, Category = Setup )
	void SetTurretReference( UTankTurret* TurretToSet );

	UPROPERTY( EditAnywhere, Category = Setup )
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY( EditAnywhere, Category = Firing )
	float LaunchSpeed = 4000.0f; 

	/***********/

	void AimAt( FVector HitLocation );

	UFUNCTION( BlueprintCallable, Category = Firing )
		void Fire();

private:
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Local barrel reference for spawning projectile.
	UTankBarrel* Barrel = nullptr;
		
};
