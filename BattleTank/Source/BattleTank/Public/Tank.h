// Copyright Brandon Roman

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h" // CANNOT put new includes below

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:

	// Sets default values for this pawn's properties
	ATank();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	

	
	
};
