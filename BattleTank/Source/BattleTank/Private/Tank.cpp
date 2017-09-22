// Copyright Brandon Roman

#include "Tank.h"
#include "Engine/World.h"
#include "Public/TankBarrel.h"
#include "Public/Projectile.h"


// Corresponding Tank header file must be included first
// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	// Super is needed for the 
	Super::BeginPlay();

}


void ATank::Fire()
{
	if (!ensure(Barrel)) { return; }
	bool bIsReloaded = (((FPlatformTime::Seconds()) - LastFireTime) > ReloadTimeSeconds);

	if (bIsReloaded) 
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
