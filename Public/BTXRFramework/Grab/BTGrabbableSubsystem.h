// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "BTXRFramework/Grab/BTGrabbableComponent.h"
#include "BTGrabbableSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class BMC_API UBTGrabbableSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void Register(UBTGrabbableComponent* GrabbableComponent);
	
	UFUNCTION(BlueprintCallable)
	class UBTGrabbableComponent* GetClosestComponent(FVector Point);

	UFUNCTION(BlueprintCallable)
	class UBTGrabbableComponent* GetCollidingComponent(FVector Point, float DetectRadius);


private:	
	UPROPERTY()
	TArray<UBTGrabbableComponent*> GrabbableComponents;

	
};
