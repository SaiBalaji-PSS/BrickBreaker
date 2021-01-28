// Fill out your copyright notice in the Description page of Project Settings.


#include "BallActor.h"
#include "Components/StaticMeshComponent.h"
#include "BlockActor.h"
#include "LimiterActor.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
ABallActor::ABallActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Ball = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ball Mesh"));
	RootComponent = Ball;

	//Ball->SetEnableGravity(false);

	//Ball->SetConstraintMode(EDOFMode::XZPlane);


	//ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("pm"));
//	ProjectileMovement->Velocity.X = 0.0f;
	
	Ball->OnComponentHit.AddDynamic(this, &ABallActor::OnCompHit);



}

// Called when the game starts or when spawned
void ABallActor::BeginPlay()
{
	Super::BeginPlay();


	
}

// Called every frame
void ABallActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);



}

void ABallActor::OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{

	ABlockActor* HitBlock = Cast<ABlockActor>(OtherActor);

	ALimiterActor* Limiter = Cast<ALimiterActor>(OtherActor);

	ABallActor* AnotherBall = Cast<ABallActor>(OtherActor);

	UE_LOG(LogTemp, Warning, TEXT("Hit OutSide"));

	if (HitBlock != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit Inside"));


		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplodeEffect, HitBlock->GetActorLocation());
		UGameplayStatics::PlaySound2D(this, BlockHitSound);
		HitBlock->Destroy();
	}

	else if (Limiter != nullptr)
	{
		this->Destroy();
	}

	else if (AnotherBall != nullptr)
	{
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), SparkEffect,AnotherBall->GetActorLocation());
	}

 

	


}

