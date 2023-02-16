// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OpeningDoor.generated.h"

UCLASS()
class SIMPLESHOOTER_API AOpeningDoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOpeningDoor();

public:
	UFUNCTION(BlueprintCallable)
	void MoveDoor(FVector Offset);

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(AllowPrivateAccess="true"))
	class UStaticMeshComponent* DoorRight;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(AllowPrivateAccess="true"))
	UStaticMeshComponent* DoorLeft;

	UPROPERTY(EditAnywhere)
	FVector MoveOffset;
};
