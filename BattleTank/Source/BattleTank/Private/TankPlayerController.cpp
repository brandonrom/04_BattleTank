// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "BattleTank.h"
#include "GameFramework/Pawn.h"


ATankPlayerController::ATankPlayerController()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	GetControlledTank();
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation; // Out Parameter
	if (GetSightRayHitLocaiton(HitLocation))
	{
	UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *HitLocation.ToString());
	// TODO Tell controlled Tank to aim at this point
	}


}


// Get world location of linetrace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocaiton(FVector &OutHitLocation) const
{
	// Find the crosshair position in pixel coordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation(ViewportSizeX*CrossHairXLocation, ViewportSizeY*CrossHairYLocation);

	// De-project the screen positioin of the cross hair
	// Line trace along that look direction, and see what is hit (up to max range)
	return true;
}



ATank* ATankPlayerController::GetControlledTank() const
{
	ATank* TempTank = nullptr;
	TempTank = Cast<ATank>(GetPawn());
	if (TempTank)
	{
		return TempTank;
	}
	else
	{
		return TempTank;
	}
}


