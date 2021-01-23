// Copyright 2021 Julien Saevecke. All Rights Reserved.

#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform() {
	PrimaryActorTick.bCanEverTick = true;

	SetMobility(EComponentMobility::Movable);
}


void AMovingPlatform::BeginPlay() {
	Super::BeginPlay();

	if (HasAuthority()) {
		SetReplicates(true);
		SetReplicateMovement(true);
	}

	GlobalStartLocation = GetActorLocation();
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
}

void AMovingPlatform::Tick(float deltaTime) {
	Super::Tick(deltaTime);

	if (ActiveTriggers > 0) {
		if (HasAuthority()) {
			FVector location = GetActorLocation();
			float journeyLength = (GlobalTargetLocation - GlobalStartLocation).Size();
			float journeyTravelled = (location - GlobalStartLocation).Size();

			if (journeyTravelled >= journeyLength) {
				FVector swap = GlobalStartLocation;
				GlobalStartLocation = GlobalTargetLocation;
				GlobalTargetLocation = swap;
			}

			location += (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal() * Speed * deltaTime;

			SetActorLocation(location);
		}
	}
}

void AMovingPlatform::AddActiveTrigger() {
	ActiveTriggers++;
}
void AMovingPlatform::RemoveActiveTrigger() {
	if (ActiveTriggers > 0) {
		ActiveTriggers--;
	}
}
