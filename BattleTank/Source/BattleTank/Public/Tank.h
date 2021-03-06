// Copyright David Tootell 2018

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankTurret;
class UTankAimingComponent;
class UTankMovementComponent;
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

	UPROPERTY( BlueprintReadOnly, Category = Movement )
	UTankMovementComponent* TankMovementComponent = nullptr;


public:	


	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference( UTankBarrel* BarrelToSet );

	UFUNCTION( BlueprintCallable, Category = Setup )
	void SetTurretReference( UTankTurret* TurretToSet );

	UPROPERTY( EditDefaultsOnly, Category = Setup )
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY( EditDefaultsOnly, Category = Firing )
	float LaunchSpeed = 4000.0f; 

	UPROPERTY( EditDefaultsOnly, Category = Firing )
		float ReloadTimeInSeconds = 3.0f;

	UFUNCTION( BlueprintCallable, Category = Firing )
		void Fire();

	void AimAt( FVector HitLocation );


private:
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Local barrel reference for spawning projectile.
	UTankBarrel* Barrel = nullptr;

	double LastFireTime = 0;
		
};
