// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DropshotPlayerController.generated.h"

UCLASS()
class ADropshotPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ADropshotPlayerController();

protected:
	/** True if the controlled character should navigate to the mouse cursor. */
	uint32 bMoveToMouseCursor : 1;

	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	// End PlayerController interface

	/** Navigate player to the given world location. */
	void SetNewMoveDestination(const FVector DestLocation);

	//--------------------------
	//        Input
	//--------------------------
	/** Move the player forward, or backward with negative input */
	void MoveForward(float Value);
    /** Move the player to the right, or left with negative input */
    void MoveRight(float Value);
	/** Trigger swing with power */
	void SwingPower();
	/** Trigger swing with control */
	void SwingControl();
	/** Trigger swing with curve */
	void SwingCurve();
	/** Trigger swing with drop */
	void SwingDrop();
};


