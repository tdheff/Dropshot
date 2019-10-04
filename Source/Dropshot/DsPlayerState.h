// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "DsPlayerState.generated.h"

UENUM()
enum ETeam
{
	None = 0,
	Home,
	Away
};

UENUM()
enum EActionState
{
	Free = 0,
	Serving,
	Charging,
	Swinging
};

UENUM()
enum ESwingType
{
	Power = 0,
	Control,
	Curve,
	Drop
};

/**
 * 
 */
UCLASS()
class DROPSHOT_API ADsPlayerState : public APlayerState
{
	GENERATED_UCLASS_BODY()

public:
	
	FORCEINLINE TEnumAsByte<ETeam> GetTeam() const { return Team; }
	FORCEINLINE TEnumAsByte<EActionState> GetActionState() const { return ActionState; }
	FORCEINLINE TEnumAsByte<ESwingType> GetCurrentSwingType() const { return CurrentSwingType; }
	FORCEINLINE float GetCurrentSwingCharge() const { return CurrentSwingCharge; }

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = PlayerState, meta = (AllowPrivateAccess = "true"))
	TEnumAsByte<ETeam> Team;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = PlayerState, meta = (AllowPrivateAccess = "true"))
	TEnumAsByte<EActionState> ActionState;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = PlayerState, meta = (AllowPrivateAccess = "true"))
	TEnumAsByte<ESwingType> CurrentSwingType;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = PlayerState, meta = (AllowPrivateAccess = "true"))
	float CurrentSwingCharge;
	
};
