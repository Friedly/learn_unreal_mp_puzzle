// Copyright 2021 Julien Saevecke. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PuzzlePlatformGameInstance.generated.h"

UCLASS()
class GAME_API UPuzzlePlatformGameInstance final : public UGameInstance
{
	GENERATED_BODY()
private:
	const FString& HostLevel = "/Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap";

public:
	UPuzzlePlatformGameInstance(const FObjectInitializer& ObjectInitializer);

	virtual void Init() override;

	UFUNCTION(Exec)
	void Host() const;

	UFUNCTION(Exec)
	void Join(const FString& Address) const;
};
