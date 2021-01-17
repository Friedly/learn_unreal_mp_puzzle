// Fill out your copyright notice in the Description page of Project Settings.


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
	if (HasAuthority()) {
		Super::Tick(deltaTime);

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
