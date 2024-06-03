// Fill out your copyright notice in the Description page of Project Settings.


#include "FTPlayer.h"

// Sets default values
AFTPlayer::AFTPlayer()
{
	// Pawn
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> CharacterMeshRef(TEXT("/Game/FishingTycoon/Characters/Woowakgood.Woowakgood"));
	if (CharacterMeshRef.Object)
	{
		GetMesh()->SetSkeletalMesh(CharacterMeshRef.Object);
	}
}

