// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/FTGameMode.h"

AFTGameMode::AFTGameMode()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerReference(TEXT("/Game/FishingTycoon/Blueprints/BP_FTPlayer.BP_FTPlayer_C"));

	if (PlayerReference.Class)
	{
		DefaultPawnClass = PlayerReference.Class;
	}
}
