// Fill out your copyright notice in the Description page of Project Settings.


#include "Shop/FTShop.h"

AFTShop::AFTShop()
{
}

void AFTShop::OnInteract(AActor* performer)
{
	UE_LOG(LogTemp, Log, TEXT("Interacted"));
}

void AFTShop::OnFocusBegin(AActor* performer)
{
	UE_LOG(LogTemp, Log, TEXT("Focus Begin"));
}

void AFTShop::OnFocusEnd(AActor* performer)
{
	UE_LOG(LogTemp, Log, TEXT("Focus End"));
}

