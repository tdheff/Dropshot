// Fill out your copyright notice in the Description page of Project Settings.


#include "DsBall.h"


// Sets default values
ADsBall::ADsBall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Replication
	SetReplicates(true);
	SetReplicateMovement(true);
	bAlwaysRelevant = true;

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	RootComponent = Sphere;

	GetSphereComponent()->InitSphereRadius(7.0f);
}

// Called when the game starts or when spawned
void ADsBall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADsBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SetActorLocation(GetActorLocation() + FVector::ForwardVector * 150.f * DeltaTime);

}

