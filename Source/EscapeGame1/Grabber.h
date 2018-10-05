// Copyright Jerry Lau 2018

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/InputComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Grabber.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPEGAME1_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	// Debug line extension length
	float Reach = 100.f;

	UPhysicsHandleComponent* PhysicsHandle = nullptr;

	UInputComponent* InputComponent = nullptr;

	// Ray-cast, called on grab and release keypresses
	void Grab();

	// Called when Grab is released
	void Release();

	// Setup attached input component
	void SetupInputComponent();

	// Find attached physics handle component
	void FindPhysicsHandleComponent();

	// Return the first physics body within range
	const FHitResult GetFirstPhysicsBodyHit();

	//// Return the first physics body within range, draws a red debug line displaying range
	const FHitResult GetFirstPhysicsBodyHitDebugLine();
};
