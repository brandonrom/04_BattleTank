// Copyright Brandon Roman

#include "Tank.h"
#include "Engine/World.h"



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


