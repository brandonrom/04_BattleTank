// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "Public/TankAimingComponent.h"
#include "Engine/World.h"
#include "Public/TankBarrel.h"
#include "Public/Projectile.h"
#include "Public/TankMovementComponent.h"


// Corresponding Tank header file must be included first
// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	auto TankName = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s DONKEY: Tank C++ Constructed"), *TankName);


	// No need to protect as added at construction
	// TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	// Super is needed for the 
	Super::BeginPlay();

	auto TankName = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s DONKEY: Tank C++ Begin Play"), *TankName);
}

void ATank::AimAt(FVector HitLocation)
{
	if (!TankAimingComponent) { return; }
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}


void ATank::Fire()
{
	bool bIsReloaded = (((FPlatformTime::Seconds()) - LastFireTime) > ReloadTimeSeconds);

	if (Barrel && bIsReloaded) 
	{
		// Spawn a projectile at the socket location in the barrel
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile"))
			);

		Projectile->LaunchProjectile(LaunchSpeed);

		LastFireTime = FPlatformTime::Seconds();
	}
}
