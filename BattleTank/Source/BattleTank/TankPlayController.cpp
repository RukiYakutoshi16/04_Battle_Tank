// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayController.h"




void ATankPlayController::BeginPlay() {
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("Not Possessing"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("%s"), *(ControlledTank->GetName()));
	}
	
}


ATank*  ATankPlayController::GetControlledTank() const {

	


	return Cast<ATank>(GetPawn());
}

