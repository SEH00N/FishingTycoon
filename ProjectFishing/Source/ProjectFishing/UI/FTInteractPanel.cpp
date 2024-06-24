// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/FTInteractPanel.h"
#include "Components/TextBlock.h"

UFTInteractPanel::UFTInteractPanel(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UFTInteractPanel::NativeConstruct()
{
	Text = Cast<UTextBlock>(GetWidgetFromName(TEXT("Text")));
	Display(nullptr, false);
}

void UFTInteractPanel::Init(FVector2D& Position, FString& Tooltip)
{
	SetPositionInViewport(Position);
	Text->SetText(FText::FromString(TEXT("[ F ] : " + Tooltip)));
}

void UFTInteractPanel::Display(IInteractable* Performer, bool Active)
{
	if (Active)
	{
		SetVisibility(ESlateVisibility::Visible);
	}
	else
	{
		if (Performer != CurrentInteractable)
			return;

		CurrentInteractable = Performer;
		SetVisibility(ESlateVisibility::Hidden);
	}
}
