// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h" // Put new includes above

class UTankAimingComponent;
class UTankMovementComponent;
class UTankBarrel;
class UTankTurret;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public: 
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable)
	void Fire();

protected: 
	UPROPERTY(BlueprintReadonly, Category = "Setup")
	UTankAimingComponent* TankAimingComponent = nullptr;
	UPROPERTY(BlueprintReadonly, Category = "Setup")
	UTankMovementComponent* TankMovementComponent = nullptr;

private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Firing") // in centimetri/s
	float LaunchSpeed = 4000; // TODO Find a sensible value

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3;

	//Local barrel reference for spawning projectile
	UTankBarrel* Barrel = nullptr; // TODO remove


	double LastFireTime = 0;
};
