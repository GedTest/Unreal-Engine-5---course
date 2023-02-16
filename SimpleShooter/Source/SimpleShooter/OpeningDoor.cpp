// Fill out your copyright notice in the Description page of Project Settings.


#include "OpeningDoor.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AOpeningDoor::AOpeningDoor(){
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DoorLeft = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorLeft"));
	DoorLeft->SetupAttachment(RootComponent);
	DoorRight = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorRight"));
	DoorRight->SetupAttachment(RootComponent);
}

void AOpeningDoor::MoveDoor(FVector Offset){
	//FMath::VInterpConstantTo(DoorLeft->GetActorLocation(), DoorLeft->GetActorLocation() + Offset, UGameplayStatics::GetWorldDeltaSeconds(this), 1.f)
	/*
	FVector DoorLeftNewLocation = DoorLeft->GetActorLocation() + Offset;
	FVector DoorRightNewLocation = DoorRight->GetActorLocation() + Offset;
	
	DoorLeft->GetComponentLocation()
	DoorRight->SetActorLocation(DoorRightNewLocation);
	*/
}
