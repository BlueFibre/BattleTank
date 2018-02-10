// Copyright David Tootell 2018

#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::Initialise( UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	if (!LeftTrackToSet || !RightTrackToSet) { return; }
	else
	{
		LeftTrack = LeftTrackToSet;
		RightTrack = RightTrackToSet;
	}
}

void UTankMovementComponent::IntendMoveForward( float Throw )
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle( Throw );
	RightTrack->SetThrottle( Throw );
}

void UTankMovementComponent::IntendTurnRight( float Throw )
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle( Throw );
	RightTrack->SetThrottle( -Throw );
}
