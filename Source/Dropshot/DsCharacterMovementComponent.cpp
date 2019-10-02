// Fill out your copyright notice in the Description page of Project Settings.


#include "DsCharacterMovementComponent.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/Character.h"


// section Replication

//Set input flags on character from saved inputs
void UDsCharacterMovementComponent::UpdateFromCompressedFlags(uint8 Flags)//Client only
{
    Super::UpdateFromCompressedFlags(Flags);


}

class FNetworkPredictionData_Client* UDsCharacterMovementComponent::GetPredictionData_Client() const
{
    check(PawnOwner != NULL);
    check(PawnOwner->Role < ROLE_Authority);

    if (!ClientPredictionData)
    {
        UDsCharacterMovementComponent* MutableThis = const_cast<UDsCharacterMovementComponent*>(this);

        MutableThis->ClientPredictionData = new FNetworkPredictionData_Client_DsMovement(*this);
        MutableThis->ClientPredictionData->MaxSmoothNetUpdateDist = 92.f;
        MutableThis->ClientPredictionData->NoSmoothNetUpdateDist = 140.f;
    }

    return ClientPredictionData;
}

void FSavedMove_DsMovement::Clear()
{
    Super::Clear();


}

uint8 FSavedMove_DsMovement::GetCompressedFlags() const
{
    uint8 Result = Super::GetCompressedFlags();


    return Result;
}

bool FSavedMove_DsMovement::CanCombineWith(const FSavedMovePtr& NewMove, ACharacter* Character, float MaxDelta) const
{

    return Super::CanCombineWith(NewMove, Character, MaxDelta);
}

void FSavedMove_DsMovement::SetMoveFor(ACharacter* Character, float InDeltaTime, FVector const& NewAccel, class FNetworkPredictionData_Client_Character & ClientData)
{
    Super::SetMoveFor(Character, InDeltaTime, NewAccel, ClientData);

    UDsCharacterMovementComponent* CharMov = Cast<UDsCharacterMovementComponent>(Character->GetCharacterMovement());
    if (CharMov)
    {

    }
}

void FSavedMove_DsMovement::PrepMoveFor(class ACharacter* Character)
{
    Super::PrepMoveFor(Character);

    UDsCharacterMovementComponent* CharMov = Cast<UDsCharacterMovementComponent>(Character->GetCharacterMovement());
    if (CharMov)
    {

    }
}

FNetworkPredictionData_Client_DsMovement::FNetworkPredictionData_Client_DsMovement(const UCharacterMovementComponent& ClientMovement)
        : Super(ClientMovement)
{

}

FSavedMovePtr FNetworkPredictionData_Client_DsMovement::AllocateNewMove()
{
    return FSavedMovePtr(new FSavedMove_DsMovement());
}

// end section