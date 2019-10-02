// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "DsBall.generated.h"

UCLASS()
class DROPSHOT_API ADsBall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADsBall();

    /** Returns USphereComponent subobject **/
    FORCEINLINE class USphereComponent* GetSphereComponent() const { return Sphere; }

    /** Returns UStaticMeshComponent subobject **/
    FORCEINLINE class UStaticMeshComponent* GetStaticMeshComponent() const { return Mesh; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
    /** Mesh */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Ball, meta = (AllowPrivateAccess = "true"))
    class USphereComponent* Sphere;

    /** Mesh */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Ball, meta = (AllowPrivateAccess = "true"))
    class UStaticMeshComponent* Mesh;
};


