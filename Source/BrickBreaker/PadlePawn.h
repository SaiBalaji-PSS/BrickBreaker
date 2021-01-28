// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BallActor.h"
#include "PadlePawn.generated.h"

UCLASS()
class BRICKBREAKER_API APadlePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APadlePawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere,Category="Component")
	class UStaticMeshComponent* PaddleMesh;

	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintPure)
	int GetNumberOfBalls() const;

private:

	void MoveLeftRight(float axisvalue);

	void LaunchBall();

	FVector MovementDirection;

	UPROPERTY(EditAnywhere, Category = "Speed")
		float MovementSpeed;


	UPROPERTY(EditAnywhere,Category="Ball Class Reference")
	TSubclassOf<ABallActor> BallActorClassReference;

	int NumberOfBallsLeft;

};
