// Copyright 2021 Julien Saevecke. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class GAME_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()

public:
	AMovingPlatform();

	virtual void BeginPlay()override;

	virtual void Tick(float deltaTime)override;

	UPROPERTY(EditAnywhere)
	float Speed = 20.f;

	UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true))
	FVector TargetLocation;

	void AddActiveTrigger();
	void RemoveActiveTrigger();

private:
	FVector GlobalStartLocation;
	FVector GlobalTargetLocation;

	UPROPERTY(EditAnywhere)
	int ActiveTriggers = 1;
};
