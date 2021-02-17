// Copyright 2021 Julien Saevecke. All Rights Reserved.


#include "MainMenu.h"

#include "Components/Button.h"


bool UMainMenu::Initialize()
{
	const bool Success = Super::Initialize();

	if(!Success || !IsValid(HostButton) || !IsValid(JoinButton)) return false;

	HostButton->OnClicked.AddDynamic(this, &UMainMenu::HostServer);
	JoinButton->OnClicked.AddDynamic(this, &UMainMenu::JoinServer);

	return true;
}

void UMainMenu::SetMenuInterface(IMenuInterface* Interface)
{
	MenuInterface = Interface;
}

void UMainMenu::HostServer()
{
	UE_LOG(LogTemp, Warning, TEXT("Host Server"))
	if(MenuInterface == nullptr) return;
	
	MenuInterface->Host();
}

void UMainMenu::JoinServer()
{
	UE_LOG(LogTemp, Warning, TEXT("Join Server"))
	if(MenuInterface == nullptr) return;
	
	MenuInterface->Join();
}
