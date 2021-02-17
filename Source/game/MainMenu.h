// Copyright 2021 Julien Saevecke. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuInterface.h"
#include "MainMenu.generated.h"

UCLASS()
class GAME_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetMenuInterface(IMenuInterface* Interface);

private:
	UPROPERTY(meta = (BindWidget))
	class UButton* HostButton;
	UPROPERTY(meta = (BindWidget))
	class UButton* JoinButton;

	IMenuInterface* MenuInterface;

	UFUNCTION()
	void HostServer();

	UFUNCTION()
	void JoinServer();
	
protected:
	virtual bool Initialize() override;
};
