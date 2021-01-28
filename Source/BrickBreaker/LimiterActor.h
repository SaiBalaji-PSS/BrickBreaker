// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LimiterActor.generated.h"

UCLASS()
class BRICKBREAKER_API ALimiterActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALimiterActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Components")
		class UStaticMeshComponent* LimiterMesh;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
