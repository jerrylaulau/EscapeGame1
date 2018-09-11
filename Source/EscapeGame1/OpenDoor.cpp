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

	ActorThatTriggers = GetWorld()->GetFirstPlayerController()->GetPawn();

}

void UOpenDoor::OpenDoor()
{
	// Initiate Actor
	AActor* Owner = GetOwner();

	// Define the new rotation angle
	FRotator NewRotation = FRotator(0.0f, 90.0f, 0.0f);

	// Set the rotation
	Owner->SetActorRotation(NewRotation);

	UE_LOG(LogTemp, Warning, TEXT("Door opened at angle %s."), *NewRotation.ToString());
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// If ActorThatTriggers is in the volume
	if (PressurePlate->IsOverlappingActor(ActorThatTriggers))
	{
		OpenDoor();
	}
}

