// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "DropshotGameMode.h"
#include "DropshotPlayerController.h"
#include "DropshotCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADropshotGameMode::ADropshotGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ADropshotPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}