// Copyright Brandon Roman

#include "TankPlayerController.h"
#include "BattleTank.h"
#include "Engine/World.h"
#include "GameFramework/Pawn.h"
#include "Public/TankAimingComponent.h"


ATankPlayerController::ATankPlayerController()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();

	if (!ensure(AimingComponent)) { return; }
	FoundAimingComponent(AimingComponent);
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair()
{
	AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }

	FVector OutHitLocation; // Out Parameter
	if (GetSightRayHitLocaiton(OutHitLocation))
	{
		AimingComponent->AimAt(OutHitLocation);
	}

}


// Get world location of linetrace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocaiton(FVector &OutHitLocation) const
{
	// Find the crosshair position in pixel coordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation(ViewportSizeX*CrossHairXLocation, ViewportSizeY*CrossHairYLocation);

	// De-project the screen position of the cross hair
	FVector LookDirection;
	FVector HitLocation;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{

		// Line trace along that look direction, and see what is hit (up to max range)
		GetLookVectorHitLocation(OutHitLocation, LookDirection);
	}

	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& OutLookDirection) const
{
	FVector CameraWorldLocation; // Will be discarded
	bool check = DeprojectScreenPositionToWorld(
		ScreenLocation.X, 
		ScreenLocation.Y, 
		CameraWorldLocation, 
		OutLookDirection);

	return check;
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector &OutHitLocation, FVector LookDirection) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(
			HitResult,
			StartLocation,
			EndLocation,
			ECollisionChannel::ECC_Visibility)
		)
	{
		OutHitLocation = HitResult.Location;
		return true;
	}
	OutHitLocation = FVector(0);
	return false;
}


// TODO : Done : Deprecated stuff During refactor
/*
	ATank* ATankPlayerController::GetControlledTank() const
	{
		// TODO Changed this part of Controlled Tank
		if (ControlledTank)
		{
			return ControlledTank;
		}
		else
		{
			return nullptr;
		}
}
*/


