// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProjectFishingGameMode.h"
#include "ProjectFishingCharacter.h"
#include "UObject/ConstructorHelpers.h"

AProjectFishingGameMode::AProjectFishingGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
