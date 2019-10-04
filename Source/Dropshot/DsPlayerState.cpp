// Fill out your copyright notice in the Description page of Project Settings.


#include "DsPlayerState.h"

ADsPlayerState::ADsPlayerState(const class FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	Team = ETeam::None;
	ActionState = EActionState::Free;
	CurrentSwingCharge = 0.f;
}