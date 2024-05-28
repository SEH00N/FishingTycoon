// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/FTGameMode.h"

AFTGameMode::AFTGameMode()
{
	static ConstructorHelpers::FClassFinder<APawn> CharacterPlayerRef(TEXT("/Game/FishingTycoon/Blueprint/BP_FTCharacterPlayer.BP_FTCharacterPlayer_C"));
	if (CharacterPlayerRef.Class)
	{
		DefaultPawnClass = CharacterPlayerRef.Class;
	}
}
