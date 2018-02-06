// Copyright David Tootell 2018

#include "TankAimingComponent.h"
#include "Tank.h"
#include "TankBarrel.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true; //TODO Should this tick?

	// ...
}


void UTankAimingComponent::SetBarrelReference( UTankBarrel* BarrelToSet )
{
	Barrel = BarrelToSet;
}

void UTankAimingComponent::AimAt( FVector HitLocation, float LaunchSpeed )
{
	if (!Barrel) { return; }

	auto LogTime = GetWorld()->GetTimeSeconds();
	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation( FName( "Projectile" ) );
	
	// Calculate the OutLaunchVelocity
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity
	(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);
	
	if(bHaveAimSolution)
	{
		FVector AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
		UE_LOG( LogTemp, Warning, TEXT( "%f: Aim solution found." ), LogTime );
	}

	
	UE_LOG( LogTemp, Error, TEXT ("%f: No aiming solution found."), LogTime );
	// If no solution found do nothing
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	FRotator BarrelRotator = Barrel->GetForwardVector().Rotation();
	FRotator AimAsRotator = AimDirection.Rotation();
	FRotator DeltaRotator = (AimAsRotator - BarrelRotator);

	Barrel->Elevate( 5 ); // TODO remove magic number
}


