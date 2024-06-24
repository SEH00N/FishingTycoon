// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/FTPlayerController.h"
#include "UI/FTHUD.h"

void AFTPlayerController::BeginPlay()
{
    Super::BeginPlay();

    FTHUD = CreateWidget<UFTHUD>(this, FTHUDWidgetClass);
    FTHUD->AddToViewport();
}
