// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATankPlayerController();

	virtual void Tick(float DeltaTime) override;

	ATank* GetControlledTank() const;
	
	virtual void BeginPlay() override;

private:
	// Start tank barrel movement
	// Shot will hit where the crosshair intersects the world
	void AimTowardsCrosshair();

	bool GetSightRayHitLocaiton(FVector &OutHitLocation) const;

	UPROPERTY(EditDefaultsOnly)
	float CrossHairXLocation = 0.5;

	UPROPERTY(EditDefaultsOnly)
	float CrossHairYLocation = 0.33333;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector &HitLocation, FVector LookDirection) const;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000;

};

