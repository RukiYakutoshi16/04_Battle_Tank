// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"



void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("Not Possessing"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("%s"), *(ControlledTank->GetName()));
	}

}


//Tick
//
//Aim toward cross hair
void ATankPlayerController::Tick(float DeltaTime)
{
	
	Super::Tick(DeltaTime);
	AimTowardCrosshair();
}

void ATankPlayerController::AimTowardCrosshair()
{


	if (!GetControlledTank()) { return; }
	FVector HitLocation; //out parameter
	if(GetSightRayHitLocation(HitLocation)){ 
		//UE_LOG(LogTemp, Warning, TEXT("Hit location: %s"), *HitLocation.ToString()); 
	}
	
}

bool ATankPlayerController::GetSightRayHitLocation(FVector & OutHitLocation) const
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);

	//UE_LOG(LogTemp, Warning, TEXT("Screen Location location: %s"), *ScreenLocation.ToString())
	return true;
}


ATank*  ATankPlayerController::GetControlledTank() const {




	return Cast<ATank>(GetPawn());
}








