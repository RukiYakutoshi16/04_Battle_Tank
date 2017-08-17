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
		GetControlledTank()->AimAt(HitLocation);
	}
	
}

bool ATankPlayerController::GetSightRayHitLocation(FVector & OutHitLocation) const
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);

	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection)) {
		//UE_LOG(LogTemp, Warning, TEXT("Screen Location location: %s"), *LookDirection.ToString());
		//GetLookVectorHitLocation
		

		if (GetLookVectorHitLocation(LookDirection, OutHitLocation)) {
			//UE_LOG(LogTemp, Warning, TEXT("Screen Location location: %s"), *OutHitLocation.ToString());
		}




	}
	

	return true;
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection ,FVector &HitLocation) const {
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility)
		)
	
	{

		HitLocation = HitResult.Location;
		return true;
	}
	return false;

}



ATank*  ATankPlayerController::GetControlledTank() const {




	return Cast<ATank>(GetPawn());
}


bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const {

	FVector CameraWorldLocation;//Discarded
	


	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		CameraWorldLocation,
		LookDirection);
	


}








