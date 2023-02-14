// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "BTXRFramework/Snap/BTSnappableComponent.h"
#include "BTSnappableSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class BMC_API UBTSnappableSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void Register(UBTSnappableComponent* SnappableComponent);

	UFUNCTION(BlueprintCallable)
	void RegisterSnappableSockets(class ABTEnginePart* InMainEngine);

	UBTSnappableComponent* GetClosestComponent(FVector Location);
	
	bool GetClosestSocket(FVector Location, FName& SocketName, float& Distance);
	

	float SnapDistance = 25;

private:
	UPROPERTY()
	TArray<UBTSnappableComponent*> SnappableComponents;

	TArray<FName> AllSocketNames;

	class ABTEnginePart* MainEngine;
};
