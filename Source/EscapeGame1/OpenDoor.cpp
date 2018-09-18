// Copyright Jerry Lau 2018

#include "OpenDoor.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	Owner = GetOwner();

	// Set to the first player pawn
	ActorThatTriggers = GetWorld()->GetFirstPlayerController()->GetPawn();

}

void UOpenDoor::OpenDoor()
{
	// Set the rotation to OpenAngle
	Owner->SetActorRotation(FRotator(0.0f, OpenAngle, 0.0f));
}

void UOpenDoor::CloseDoor()
{
	// Set the rotation to 0
	Owner->SetActorRotation(FRotator(0.0f, 0.0f, 0.0f));
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// If ActorThatTriggers is in the volume, store game time of when the door opened, and open the door
	if (PressurePlate->IsOverlappingActor(ActorThatTriggers))
	{
		OpenDoorTimestamp = GetWorld()->GetTimeSeconds();

		OpenDoor();
	}

	else if ((OpenDoorTimestamp + DoorCloseDelay) < GetWorld()->GetTimeSeconds())
	{
		CloseDoor();
	}

}

