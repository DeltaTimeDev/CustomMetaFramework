// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "BTGrabbableComponent.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGrabStateChanged, int32, State);


UCLASS(Blueprintable, ClassGroup=(BTXRFramework), meta=(BlueprintSpawnableComponent) )
class BMC_API UBTGrabbableComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBTGrabbableComponent();

	UFUNCTION(BlueprintCallable)
	bool TryGrab(class UMotionControllerComponent* MotionController);

	UFUNCTION(BlueprintCallable)
	bool TryRelease();

	UPROPERTY(BlueprintAssignable)
	FGrabStateChanged OnGrabbed;
	UPROPERTY(BlueprintAssignable)
	FGrabStateChanged OnReleased;

	UPROPERTY(EditAnywhere)
	bool bShouldGrab = true;

	UPROPERTY(EditAnywhere)
	bool bSimulateOnDrop = false;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void SetPrimitiveCompPhysics(bool bSimulate);
	bool AttachParentToMotionController(class UMotionControllerComponent* MotionController);
	void SetShouldSimulateOnDrop();

protected:
	bool bIsHeld = false;

	UPROPERTY()
	class UMotionControllerComponent* MotionControllerRef;

	UPROPERTY()
	class UBTGrabbableSubsystem* GrabbableSubsystemRef;
};
