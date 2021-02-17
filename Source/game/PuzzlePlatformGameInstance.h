// Copyright 2021 Julien Saevecke. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MenuInterface.h"
#include "PuzzlePlatformGameInstance.generated.h"

UCLASS()
class GAME_API UPuzzlePlatformGameInstance final : public UGameInstance, public IMenuInterface
{
	GENERATED_BODY()
	
private:
	const FString& HostLevel = "/Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap";
	const FString& JoinURL = "";

	TSubclassOf<UUserWidget> MainMenuWidgetClass;

public:
	UPuzzlePlatformGameInstance(const FObjectInitializer& ObjectInitializer);

	virtual void Init() override;

	UFUNCTION(BlueprintCallable, Exec)
	void LoadMenu() const;

	UFUNCTION(Exec)
	virtual void Host() override;

	UFUNCTION(Exec)
	virtual void Join() override;
};
