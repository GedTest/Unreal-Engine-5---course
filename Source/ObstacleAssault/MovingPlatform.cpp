// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Move(DeltaTime);
	Rotate(DeltaTime);
}

void AMovingPlatform::Move(float DeltaTime){

	if (ShouldPlatformReturn()){
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation += MoveDirection * MAX_DISTANCE;
		SetActorLocation(StartLocation);
		
		PlatformVelocity = -PlatformVelocity;
	} else {
		FVector CurrentLocation = GetActorLocation();
		CurrentLocation += PlatformVelocity * DeltaTime;
		SetActorLocation(CurrentLocation);
	}
	return;
}

void AMovingPlatform::Rotate(float DeltaTime){
	AddActorLocalRotation(RotationVelocity * DeltaTime);
	return;
}

bool AMovingPlatform::ShouldPlatformReturn() const{
	return GetDistanceMoved() >= MAX_DISTANCE;
}

float AMovingPlatform::GetDistanceMoved() const{
	return FVector::Distance(StartLocation, GetActorLocation());
}