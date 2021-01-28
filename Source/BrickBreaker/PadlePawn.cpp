// Fill out your copyright notice in the Description page of Project Settings.


#include "PadlePawn.h"
#include "Components/StaticMeshComponent.h"
#include "BallActor.h"


APadlePawn::APadlePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PaddleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Paddle"));
	RootComponent = PaddleMesh;

	MovementSpeed = 800.0f;

	NumberOfBallsLeft = 3;

}

// Called when the game starts or when spawned
void APadlePawn::BeginPlay()
{
	Super::BeginPlay();


	FRotator SpawnRotation;



	SpawnRotation.Pitch = FMath::FRand() * 360.0f;
	SpawnRotation.Yaw = FMath::FRand() * 360.0f;
	SpawnRotation.Roll = FMath::FRand() * 360.0f;

	FVector SpawnLoacation = FVector(-210.0f, 0.0f, 20.0f);

	UWorld* World = GetWorld();

	if (World != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Ball Location"));

		ABallActor* SpawnedBall = World->SpawnActor<ABallActor>(BallActorClassReference, SpawnLoacation, SpawnRotation);

		UStaticMeshComponent* BallMesh = Cast<UStaticMeshComponent>(SpawnedBall->GetRootComponent());

		if (BallMesh != nullptr)
		{
			NumberOfBallsLeft--;

			BallMesh->AddImpulse(FVector(990.0f, 0, 0), FName(), true);

		}

	}


	
	
}

// Called every frame
void APadlePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!MovementDirection.IsZero())
	{
		FVector UpdatedLocation = this->GetActorLocation() + (MovementDirection * MovementSpeed * DeltaTime);

		this->SetActorLocation(UpdatedLocation);
	}

}

// Called to bind functionality to input
void APadlePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("Move"), this, &APadlePawn::MoveLeftRight);
	PlayerInputComponent->BindAction(TEXT("Launch"), IE_Pressed, this, &APadlePawn::LaunchBall);

}



void APadlePawn::MoveLeftRight(float axisvalue)
{
	MovementDirection.Y = FMath::Clamp(axisvalue, -1.0f, 1.0f);
}

void APadlePawn::LaunchBall()
{
	if (NumberOfBallsLeft == 0)
	{
		return;
	}



	FRotator SpawnRotation;



	SpawnRotation.Pitch = FMath::FRand() * 360.0f;
	SpawnRotation.Yaw = FMath::FRand() * 360.0f;
	SpawnRotation.Roll = FMath::FRand() * 360.0f;

	FVector SpawnLoacation = FVector(-210.0f, 0.0f, 20.0f);

	UWorld* World = GetWorld();

	if (World != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Ball Location"));
		ABallActor* SpawnedBall = World->SpawnActor<ABallActor>(BallActorClassReference, SpawnLoacation, SpawnRotation);

		
       
		UStaticMeshComponent* BallMesh = Cast<UStaticMeshComponent>(SpawnedBall->GetRootComponent());

		if (BallMesh != nullptr)
		{
			NumberOfBallsLeft--;

			BallMesh->AddImpulse(FVector(990.0f, 0,0),FName(),true);

		}
	}
}



int APadlePawn::GetNumberOfBalls() const
{
	return NumberOfBallsLeft;
}

