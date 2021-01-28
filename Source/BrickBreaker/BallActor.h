// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"

#include "BallActor.generated.h"


UCLASS()
class BRICKBREAKER_API ABallActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABallActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere,Category="Components")
	class UStaticMeshComponent* Ball;

	//UPROPERTY(EditAnywhere, Category = "Projectile Movement")

	//	UProjectileMovementComponent* ProjectileMovement;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

private:
	UPROPERTY(EditAnywhere, Category = "Particle Effects")
		UParticleSystem* ExplodeEffect;
	UPROPERTY(EditAnywhere, Category = "Particle Effects")
		UParticleSystem* SparkEffect;

	UPROPERTY(EditAnywhere, Category = "Sound Effects")
		USoundBase* BlockHitSound;


};
