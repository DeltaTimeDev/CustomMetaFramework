// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BTLanFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class BMC_API UBTLanFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "BTLanFunctionLibrary")
	static void FindIP_Address(
		FString& IP_Address
	);

};
