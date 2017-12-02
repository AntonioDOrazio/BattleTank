// Fill out your copyright notice in the Description page of Project Settings.
#include "TankAIController.h"

#include "Engine/World.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	ATank* PossessedTank = GetControlledTank();
	if (PossessedTank != nullptr) {
		FString LogMessage = PossessedTank->GetName();
		UE_LOG(LogTemp, Warning, TEXT("AI controller is possessing %s"), *LogMessage);
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI controller is possessing nothing"));
	}

	ATank* PlayerTank = GetPlayerTank();
	if (PlayerTank != nullptr) {
		FString LogMessage = PlayerTank->GetName();
		UE_LOG(LogTemp, Warning, TEXT("AI controller found player tank %s"), *LogMessage);
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI controller cannot found player tank"));
	}
	
}

void ATankAIController::Tick(float DeltaTime) 
{
	Super::Tick(DeltaTime);

	if (GetPlayerTank())
	{
		// TODO Move towards the player

		// Aim the player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	
		// TODO Fire if ready
	}
}


ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto* PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}