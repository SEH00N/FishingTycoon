// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/FTWidgetComponent.h"
#include "FTUserWidget.h"

void UFTWidgetComponent::InitWidget()
{
	Super::InitWidget();

	UFTUserWidget* FTUserWidget = Cast<UFTUserWidget>(GetWidget());
	if (FTUserWidget)
		FTUserWidget->Init(GetOwner());
}
