// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "BTSceneComponent.generated.h"

/*The component expect to be attached to motion controlller and the controller belongs to A Pawn*/
UCLASS(Blueprintable, ClassGroup=(BTXRFramework), meta=(BlueprintSpawnableComponent) )
class BMC_API UBTSceneComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	UBTSceneComponent();

protected:
	
	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void OnRightGrabPressed();
	UFUNCTION()
	virtual void OnRightGrabReleased();


	UPROPERTY(VisibleAnywhere)
	class UMotionControllerComponent* MotionController;
};
