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
}

void AMovingPlatform::Tick(float deltaTime) {
	if (HasAuthority()) {
		Super::Tick(deltaTime);

		FVector location = GetActorLocation();
		location += FVector(Speed * deltaTime, 0.f, 0.f);

		SetActorLocation(location);
	}
}
	