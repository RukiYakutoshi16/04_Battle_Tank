// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankBarrel.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{

	barrel = BarrelToSet;
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAimingComponent::MoveBarrelToward(FVector AimDirection)
{
	auto BarrelRotator = barrel->GetForwardVector().Rotation();
	auto AimRotator = AimDirection.Rotation();
	auto DeltaRotator = AimRotator - BarrelRotator;
	
	barrel->Elevate(5);

	//make rotator 
	//rotate barrel based on barrel

}

void UTankAimingComponent::AimAt(FVector  WorldSpaceAim, float launchSpeed) {
	if (!barrel) return;
		FVector outLaunchVelocity;
		FVector StartLocation = barrel->GetSocketLocation(FName("Projectile"));

		bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
			this,
			outLaunchVelocity,
			StartLocation,
			WorldSpaceAim,
			launchSpeed,
			false,
			10.0f,
			0.0f,
			ESuggestProjVelocityTraceOption::DoNotTrace
			);

		if (bHaveAimSolution) 
		
		{
			auto AimDirection = outLaunchVelocity.GetSafeNormal();
			auto TankName = GetOwner()->GetName();
		//	UE_LOG(LogTemp, Warning, TEXT("%s aiming at at %s "),*TankName, *AimDirection.ToString());
			MoveBarrelToward(AimDirection);
		}

		
}

