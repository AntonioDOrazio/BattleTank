// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// UE_LOG(LogTemp, Warning, TEXT("PlayerController ticking"));
	// AimTowardsCrosshair()
}



void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	ATank* PossessedTank = GetControlledTank();
	if (PossessedTank != nullptr) {
		FString LogMessage = PossessedTank->GetName();
		UE_LOG(LogTemp, Warning, TEXT("Player controller is possessing %s"), *LogMessage);
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("Tank not possessed"));
	}
}

ATank* ATankPlayerController::GetControlledTank() const 
{
	return Cast<ATank>(GetPawn());
}



