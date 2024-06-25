// Fill out your copyright notice in the Description page of Project Settings.


#include "Fishing/FTWater.h"

AFTWater::AFTWater()
{
}

void AFTWater::BeginPlay()
{
	Super::BeginPlay();
}

void AFTWater::OnInteract(AActor* Performer)
{
	UE_LOG(LogTemp, Log, TEXT("Start Fishing"));
}

void AFTWater::OnFocusBegin(AActor* Performer)
{
}

void AFTWater::OnFocusEnd(AActor* Performer)
{
}
