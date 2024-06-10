// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/FTPlayerController.h"
#include "Camera/CameraComponent.h"

void AFTPlayerController::BeginPlay()
{
    Super::BeginPlay();

    //CameraActor = GetWorld()->SpawnActor<AActor>();
    //CameraActor->SetActorLocation(FVector(-8888.848681, -8483.347280, 2745.625563));
    //CameraActor->SetActorRotation(FRotator(-23.000000, 25.000000, 0.000000));
    //SetViewTarget(CameraActor);
}
