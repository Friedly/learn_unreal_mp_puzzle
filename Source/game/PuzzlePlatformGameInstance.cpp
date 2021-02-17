// Copyright 2021 Julien Saevecke. All Rights Reserved.

#include "PuzzlePlatformGameInstance.h"

#include "Blueprint/UserWidget.h"

UPuzzlePlatformGameInstance::UPuzzlePlatformGameInstance(const FObjectInitializer& ObjectInitializer) {
	UE_LOG(LogTemp, Warning, TEXT("GameInstance Constructor"));

	const ConstructorHelpers::FClassFinder<UUserWidget> MainMenuWidgetBP(TEXT("/Game/MenuSystem/WBP_MainMenu")); 

	if(!IsValid(MainMenuWidgetBP.Class)) return;

	MainMenuWidgetClass = MainMenuWidgetBP.Class;
}

void UPuzzlePlatformGameInstance::Init() {
	UE_LOG(LogTemp, Warning, TEXT("Found class %s"), *MainMenuWidgetClass->GetName());
}

void UPuzzlePlatformGameInstance::LoadMenu() const
{
	if(!IsValid(MainMenuWidgetClass)) return;
	
	UUserWidget* MainMenu = CreateWidget<UUserWidget>(GetWorld(), MainMenuWidgetClass);

	if(!IsValid(MainMenu)) return;

	MainMenu->AddToViewport();
}

void UPuzzlePlatformGameInstance::Host() const {
	GEngine->AddOnScreenDebugMessage(0, 5.f, FColor::Green, TEXT("GameInstance Host"));

	UWorld* World = GetWorld();
	if (!IsValid(World)) return;

	World->ServerTravel(HostLevel);
}

void UPuzzlePlatformGameInstance::Join(const FString& Address) const {
	GEngine->AddOnScreenDebugMessage(0, 5.f, FColor::Green, FString::Printf(TEXT("GameInstance Join: %s"), *Address));
}