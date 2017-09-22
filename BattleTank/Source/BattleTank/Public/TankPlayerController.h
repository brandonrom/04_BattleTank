// Copyright Brandon Roman

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;
class UTankAimingComponent;

/**
 *  Responsible for helping the player aim
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATankPlayerController();

	virtual void Tick(float DeltaTime) override;
	
	virtual void BeginPlay() override;

protected:
	UFUNCTION(BlueprintCallable, Category = "Setup")
	ATank* GetControlledTank() const;

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAimingComponent(UTankAimingComponent* AimCompRef);

private:
	// Start tank barrel movement
	// Shot will hit where the crosshair intersects the world
	void AimTowardsCrosshair();

	bool GetSightRayHitLocaiton(FVector &OutHitLocation) const;

	UPROPERTY(EditDefaultsOnly)
	float CrossHairXLocation = 0.5;

	UPROPERTY(EditDefaultsOnly)
	float CrossHairYLocation = 0.33333;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector &HitLocation, FVector LookDirection) const;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000;

	ATank* ControlledTank = nullptr;
	// Cast<ATank>(GetPawn());

};

