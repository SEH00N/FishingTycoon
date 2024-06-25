// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/FTInteractPanel.h"
#include "Components/TextBlock.h"
#include "Components/PanelSlot.h"
#include <Components/CanvasPanelSlot.h>
#include <Interface/FTWidgetHandler.h>

void UFTInteractPanel::NativeConstruct()
{
	Super::NativeConstruct();

	Text = Cast<UTextBlock>(GetWidgetFromName(TEXT("ContentText")));

	IFTWidgetHandler* WidgetHandler = Cast<IFTWidgetHandler>(OwningActor);
	if (WidgetHandler)	
		WidgetHandler->InitWidget(this);

	Display(false);
}

void UFTInteractPanel::Init(FString& Tooltip)
{
	Text->SetText(FText::FromString(TEXT("[F] : " + Tooltip)));
}

void UFTInteractPanel::Display(bool Active)
{
	SetVisibility(Active ? ESlateVisibility::Visible : ESlateVisibility::Hidden);
}
