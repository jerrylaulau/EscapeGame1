// Copyright Jerry Lau 2018

#include "GetObjectName.h"


// Sets default values for this component's properties
UGetObjectName::UGetObjectName()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGetObjectName::BeginPlay()
{
	Super::BeginPlay();

	FString ObjectName;
	ObjectName = this->GetName();

	UE_LOG(LogTemp, Warning, TEXT("ObjectName"));
	
}


// Called every frame
void UGetObjectName::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

