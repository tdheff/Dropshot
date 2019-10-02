// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "DropshotPlayerController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Runtime/Engine/Classes/Components/DecalComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "DropshotCharacter.h"
#include "Engine/World.h"

ADropshotPlayerController::ADropshotPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}

void ADropshotPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
}

void ADropshotPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	InputComponent->BindAction("SetDestination", IE_Pressed, this, &ADropshotPlayerController::OnSetDestinationPressed);
	InputComponent->BindAction("SetDestination", IE_Released, this, &ADropshotPlayerController::OnSetDestinationReleased);

    InputComponent->BindAxis("MoveForward", this, &ADropshotPlayerController::MoveForward);
    InputComponent->BindAxis("MoveRight", this, &ADropshotPlayerController::MoveRight);

	InputComponent->BindAction("ResetVR", IE_Pressed, this, &ADropshotPlayerController::OnResetVR);
}

void ADropshotPlayerController::OnResetVR()
{
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void ADropshotPlayerController::MoveForward(float Value) {
    if (ADropshotCharacter* MyPawn = Cast<ADropshotCharacter>(GetPawn()))
    {
        MyPawn->MoveForward(Value);
    }
}

void ADropshotPlayerController::MoveRight(float Value) {
    if (ADropshotCharacter* MyPawn = Cast<ADropshotCharacter>(GetPawn()))
    {
        MyPawn->MoveRight(Value);
    }
}

void ADropshotPlayerController::SetNewMoveDestination(const FVector DestLocation)
{
	APawn* const MyPawn = GetPawn();
	if (MyPawn)
	{
		float const Distance = FVector::Dist(DestLocation, MyPawn->GetActorLocation());

		// We need to issue move command only if far enough in order for walk animation to play correctly
		if ((Distance > 120.0f))
		{
			UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, DestLocation);
		}
	}
}

void ADropshotPlayerController::OnSetDestinationPressed()
{
	// set flag to keep updating destination until released
	bMoveToMouseCursor = true;
}

void ADropshotPlayerController::OnSetDestinationReleased()
{
	// clear flag to indicate we should stop updating the destination
	bMoveToMouseCursor = false;
}
