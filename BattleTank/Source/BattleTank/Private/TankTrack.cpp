// Copyright David Tootell 2018

#include "TankTrack.h"
#include "Components/StaticMeshComponent.h"

void UTankTrack::SetThrottle( float Throttle )
{

	//TODO: Clamp throttle value so player can't over-drive

	FVector ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	FVector ForceLocation = GetComponentLocation();
	UPrimitiveComponent* TankRoot = Cast<UPrimitiveComponent>( GetOwner()->GetRootComponent() );
	
	TankRoot->AddForceAtLocation( ForceApplied, ForceLocation);

}


