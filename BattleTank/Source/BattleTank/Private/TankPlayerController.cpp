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
	UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());
	// TODO Tell controlled Tank to aim at this point
	}

}


// Get world location of linetrace through crosshair
bool ATankPlayerController::GetSightRayHitLocaiton(FVector &OutHitLocation) const
{
	OutHitLocation = FVector(1.0);

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


