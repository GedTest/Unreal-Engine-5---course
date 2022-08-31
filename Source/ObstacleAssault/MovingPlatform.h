// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	int32 MAX_DISTANCE = 650;	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere, Category="Moving")
	FVector PlatformVelocity = FVector(0, 0, 300);

	UPROPERTY(EditAnywhere, Category="Rotating")
	FRotator RotationVelocity;

	FVector StartLocation;

	void Move(float DeltaTime);
	void Rotate(float DeltaTime);

	bool ShouldPlatformReturn() const;

	float GetDistanceMoved() const;
};
