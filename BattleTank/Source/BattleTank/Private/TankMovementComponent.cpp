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

void UTankMovementComponent::RequestDirectMove( const FVector& MoveVelocity, bool bForceMaxSpeed )
{
	
	// The normalised vector of the tank's current facing.
	FVector TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	// The normalised vector of the target velocity
	FVector AIForwardIntention = MoveVelocity.GetSafeNormal();

	float ForwardThrow = FVector::DotProduct( TankForward, AIForwardIntention );
	IntendMoveForward( ForwardThrow );

	float RightThrow = FVector::CrossProduct( TankForward, AIForwardIntention ).Z;
	IntendTurnRight( RightThrow );

}