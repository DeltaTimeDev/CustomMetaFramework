// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BTXRFramework/Grab/BTGrabToolComponent.h"
#include "BTGrabToolHandComponent.generated.h"

/**
 * 
 */
UCLASS()
class BMC_API UBTGrabToolHandComponent : public UBTGrabToolComponent
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	FVector GetGrabPoint() override;
	
	UPROPERTY(EditAnywhere)
		FName GrabBoneName = FName("b_r_index3");
};
