// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BTXRFramework/Component/BTSceneComponent.h"
#include "BTGrabToolComponent.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, ClassGroup = (BTXRFramework), meta = (BlueprintSpawnableComponent))
class BMC_API UBTGrabToolComponent : public UBTSceneComponent
{
	GENERATED_BODY()


public:
	UPROPERTY(EditAnywhere)
	float DetectRadius = 10;

protected:
	UPROPERTY()
	class UMotionControllerComponent* RightHand;

	UPROPERTY()
	class UBTGrabbableComponent* HeldComponent;

	UPROPERTY()
	class UBTGrabbableSubsystem* GrabbableSubsystemRef;

protected:
	virtual void BeginPlay() override;

private:

	void OnRightGrabPressed() override;
	void OnRightGrabReleased() override;

	void TryToGrab();
	void TryToRelease();

	float ExpectedDistance = 10;
	
	virtual FVector GetGrabPoint();
	
};
