// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	
public:
	ATank* GetControlledTank() const;

	void BeginPlay() override;


	virtual void Tick(float DeltaTime) override;

	void AimTowardCrosshair();
	
	

private:
	ATank* Battle;
	bool GetSightRayHitLocation(FVector &OutHitLocation) const;
	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = .5;
	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = .3333;


	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000;


	bool GetLookVectorHitLocation(FVector LookDirection,FVector&HitLocation) const;
};
