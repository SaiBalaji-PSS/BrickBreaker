// Fill out your copyright notice in the Description page of Project Settings.


#include "LimiterActor.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ALimiterActor::ALimiterActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	LimiterMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LimiterMesh"));
	RootComponent = LimiterMesh;

}

// Called when the game starts or when spawned
void ALimiterActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALimiterActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

