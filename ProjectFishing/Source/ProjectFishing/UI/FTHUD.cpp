// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/FTHUD.h"
#include "UI/FTInteractPanel.h"

UFTHUD::UFTHUD(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UFTHUD::NativeConstruct()
{
	Super::NativeConstruct();

	InteractPanel = Cast<UFTInteractPanel>(GetWidgetFromName(TEXT("WBP_InteractPanel")));
}
