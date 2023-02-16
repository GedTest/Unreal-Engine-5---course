// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"

void AShooterAIController::Tick(float DeltaSeconds){
    Super::Tick(DeltaSeconds);
    /*
    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    
    if(LineOfSightTo(PlayerPawn)){
        GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
        GetBlackboardComponent()->SetValueAsVector(TEXT("LastKnownPlayerLocation"), PlayerPawn->GetActorLocation());
        // Built-in AI navigation
        //MoveToActor(PlayerPawn, 250);
        // Rotating, so that AI focuses on player
        //SetFocus(PlayerPawn);
    } else {
        GetBlackboardComponent()->ClearValue(TEXT("PlayerLocation"));
        //ClearFocus(EAIFocusPriority::Gameplay);
        //StopMovement();
    }
    */
}

void AShooterAIController::BeginPlay(){
    Super::BeginPlay();
    
    if(AIBehavior){
        RunBehaviorTree(AIBehavior);
        GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());

        //APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
        
    }
}
