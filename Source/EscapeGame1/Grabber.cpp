// Copyright Jerry Lau 2018

#include "Grabber.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "DrawDebugHelpers.h"
#include "Color.h"

#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Grabber reporting for duty."))
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Get player viewpoint

	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
											OUT PlayerViewPointLocation, 
											OUT PlayerViewPointRotation);
	


	//UE_LOG(LogTemp, Warning, TEXT("Location: %s -- Rotation: %s"), 
	//							*PlayerViewPointLocation.ToString(), 
	//							*PlayerViewPointRotation.ToString())

	// Draw red debug line to visualize

	FVector LineTraceDirection = PlayerViewPointRotation.Vector() * Reach;
	FVector LineTraceEnd = PlayerViewPointLocation + LineTraceDirection;
	
	DrawDebugLine(
		GetWorld(),
		PlayerViewPointLocation,
		LineTraceEnd,
		FColor(150, 00, 00),
		false,
		0.f,
		0.f,
		5.0f
	);


	// Ray-cast out

	// See what we hit
}