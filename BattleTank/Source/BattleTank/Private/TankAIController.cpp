// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "BattleTank.h"
#include "Tank.h"
#include "GameFramework/Pawn.h"
#include "Engine/World.h"
#include "GameFramework/Pawn.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	GetControlledTank();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController didn't find player"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found PlayerTank: %s"), *(PlayerTank->GetName()));
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetPlayerTank()) 
	{
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}

}


ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}


