// Copyright 2021 Julien Saevecke. All Rights Reserved.

#include "PuzzlePlatformGameInstance.h"

#include "Blueprint/UserWidget.h"
#include "MainMenu.h"

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
	
	UMainMenu* MainMenu = CreateWidget<UMainMenu>(GetWorld(), MainMenuWidgetClass);

	if(!IsValid(MainMenu)) return;

	MainMenu->AddToViewport();

	APlayerController* PlayerController = GetFirstLocalPlayerController();
	if(!IsValid(PlayerController)) return;

	FInputModeUIOnly InputModeUIOnly;
	InputModeUIOnly.SetWidgetToFocus(MainMenu->TakeWidget());
	InputModeUIOnly.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	
	PlayerController->SetInputMode(InputModeUIOnly);
	PlayerController->SetShowMouseCursor(true);

	MainMenu->SetMenuInterface(Cast<IMenuInterface>(GetWorld()->GetGameInstance()));
}

void UPuzzlePlatformGameInstance::Host()
{
	GEngine->AddOnScreenDebugMessage(0, 5.f, FColor::Green, TEXT("GameInstance Host"));

	UWorld* World = GetWorld();
	if (!IsValid(World)) return;

	World->ServerTravel(HostLevel);

	APlayerController* PlayerController = GetFirstLocalPlayerController();
	if(!IsValid(PlayerController)) return;

	const FInputModeGameOnly InputModeGameOnly;
	PlayerController->SetInputMode(InputModeGameOnly);
	PlayerController->SetShowMouseCursor(true);
}

void UPuzzlePlatformGameInstance::Join()
{
	GEngine->AddOnScreenDebugMessage(0, 5.f, FColor::Green, FString::Printf(TEXT("GameInstance Join: %s"), *JoinURL));

	APlayerController* PlayerController = GetFirstLocalPlayerController();
	if(!IsValid(PlayerController)) return;

	PlayerController->ClientTravel(JoinURL, TRAVEL_Absolute);
}
