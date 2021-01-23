// Copyright 2021 Julien Saevecke. All Rights Reserved.

#include "PuzzlePlatformGameInstance.h"

UPuzzlePlatformGameInstance::UPuzzlePlatformGameInstance(const FObjectInitializer& ObjectInitializer) {
	UE_LOG(LogTemp, Warning, TEXT("GameInstance Constructor"));
}

void UPuzzlePlatformGameInstance::Init() {
	UE_LOG(LogTemp, Warning, TEXT("GameInstance Init"));
}

void UPuzzlePlatformGameInstance::Host() {
	GEngine->AddOnScreenDebugMessage(0, 5.f, FColor::Green, TEXT("GameInstance Host"));
}

void UPuzzlePlatformGameInstance::Join(const FString& Address) {
	GEngine->AddOnScreenDebugMessage(0, 5.f, FColor::Green, FString::Printf(TEXT("GameInstance Join: %s"), *Address));
}