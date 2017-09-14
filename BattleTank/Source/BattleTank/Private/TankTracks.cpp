// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTracks.h"
#include "Engine/World.h"

void UTankTracks::SetThrottle(float throttle)
{
	// auto Time = GetWorld()->GetTimeSeconds();
	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s throttle: throttle %f "), *Name, throttle);

	// TODO clamp actual throttle value so player can't override

}


