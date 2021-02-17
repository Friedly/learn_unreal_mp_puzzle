// Copyright 2021 Julien Saevecke. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MenuInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UMenuInterface : public UInterface
{
	GENERATED_BODY()
};

class GAME_API IMenuInterface
{
	GENERATED_BODY()

	public:
		virtual void Host() = 0;
		virtual void Join() = 0;
};
