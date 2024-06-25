// Fill out your copyright notice in the Description page of Project Settings.


#include "Shop/FTShop.h"
#include "Core/FTPlayerController.h"
#include "UI/FTHUD.h"
#include "UI/FTInteractPanel.h"

AFTShop::AFTShop()
{
}

void AFTShop::BeginPlay()
{
	Super::BeginPlay();
}

void AFTShop::OnInteract(AActor* Performer)
{
	UE_LOG(LogTemp, Log, TEXT("Display UI"));
}

void AFTShop::OnFocusBegin(AActor* Performer)
{
}

void AFTShop::OnFocusEnd(AActor* Performer)
{
}

