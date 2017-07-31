// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "BattleTank.h"
#include "GameFramework/Pawn.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("AIController Begin Play"));
	GetControlledTank();
}

ATank* ATankAIController::GetControlledTank() const
{
	ATank* ControlledTank = nullptr;
	ControlledTank = Cast<ATank>(GetPawn());
	if (ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank found %s"), *(ControlledTank->GetName()));
		return ControlledTank;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No tank found"));
		return ControlledTank;
	}
}


