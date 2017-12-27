// Fill out your copyright notice in the Description page of Project Settings.
#include "TankAIController.h"
#include "Tank.h"
#include "Engine/World.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime) 
{
	Super::Tick(DeltaTime);

	ATank* PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	ATank* ControlledTank = Cast<ATank>(GetPawn());
	
	if (PlayerTank && ControlledTank)
	{
		// TODO Move towards the player

		// Aim the player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
	
		// TODO Fire if ready
		ControlledTank->Fire();
	}
}

