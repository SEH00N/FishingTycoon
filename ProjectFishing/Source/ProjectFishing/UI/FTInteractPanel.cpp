// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/FTInteractPanel.h"
#include "Components/TextBlock.h"
#include "Components/PanelSlot.h"
#include <Components/CanvasPanelSlot.h>

UFTInteractPanel::UFTInteractPanel(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UFTInteractPanel::NativeConstruct()
{
	Text = Cast<UTextBlock>(GetWidgetFromName(TEXT("ContentText")));
	Display(nullptr, false);
}

void UFTInteractPanel::Init(FString& Tooltip)
{
	Text->SetText(FText::FromString(TEXT("[ F ] : " + Tooltip)));
}

void UFTInteractPanel::SetPosition(FVector2D& Position)
{
	// ¿Ö ¾È µÊ??
	SetPositionInViewport(Position);
}

void UFTInteractPanel::Display(IFTInteractable* Performer, bool Active)
{
	if (Active)
	{
		SetVisibility(ESlateVisibility::Visible);
		CurrentInteractable = Performer;
	}
	else
	{
		if (Performer != CurrentInteractable)
			return;

		CurrentInteractable = Performer;
		SetVisibility(ESlateVisibility::Hidden);
	}
}
