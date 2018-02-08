// Copyright David Tootell 2018

#include "Tank.h"
#include "Projectile.h"
#include "Engine/World.h"
#include "TankBarrel.h"
#include "TankAimingComponent.h"



// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Adds subobject to tank BP
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>( FName( "Aiming Component" ) );

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
}

void ATank::AimAt( FVector HitLocation )
{
	TankAimingComponent->AimAt( HitLocation, LaunchSpeed );
}

void ATank::SetBarrelReference( UTankBarrel * BarrelToSet )
{
	TankAimingComponent->SetBarrelReference( BarrelToSet );
	Barrel = BarrelToSet;
}

void ATank::SetTurretReference( UTankTurret* TurretToSet )
{
	TankAimingComponent->SetTurretReference( TurretToSet );
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::Fire()
{
	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;
	
	if (Barrel && isReloaded) 
	{ 
		// Spawn a projectile at the socket location on barrel
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			Barrel->GetSocketLocation( FName( "Projectile" ) ),
			Barrel->GetSocketRotation( FName( "Projectile" ) )
			);

		Projectile->LaunchProjectile( LaunchSpeed );
		LastFireTime = FPlatformTime::Seconds();
	}

}

