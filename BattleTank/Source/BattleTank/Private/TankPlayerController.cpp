// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "BattleTank.h"
#include "GameFramework/Pawn.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));
	GetControlledTank();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	ATank* TempTank = nullptr;
	TempTank = Cast<ATank>(GetPawn());
	if (TempTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank found %s"), *(TempTank->GetName()));
		return TempTank;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No tank found"));
		return TempTank;
	}
}


