// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

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
	
};
