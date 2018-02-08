// Copyright David Tootell 2018

#include "GameFramework/ProjectileMovementComponent.h"
#include "Projectile.h"



// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Adds subobject to ProjectileBP
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>( FName( "Projectile Movement" ) );
	ProjectileMovement->bAutoActivate = false;
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProjectile::LaunchProjectile( float Speed )
{
	UE_LOG( LogTemp, Warning, TEXT( "Projectile fired at: %f" ), Speed )
	ProjectileMovement->SetVelocityInLocalSpace( FVector::ForwardVector * Speed );
	ProjectileMovement->Activate();
}
