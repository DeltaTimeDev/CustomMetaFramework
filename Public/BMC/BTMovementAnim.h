// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BTMovementAnim.generated.h"

USTRUCT(BlueprintType) struct FAnimData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadwrite)
	FVector InitialPoint;

	UPROPERTY(BlueprintReadwrite)
	FVector TargetPoint;

	UPROPERTY(BlueprintReadwrite)
	FRotator TargetRotation;

	UPROPERTY(BlueprintReadwrite)
	float Duration;

	UPROPERTY(BlueprintReadwrite)
	class ABTEnginePart* TargetActor;

	FAnimData(class ABTEnginePart* NewTargetActor, FVector NewInitialPoint, FVector NewTargetPoint, float NewDuration)
	{
		TargetActor = NewTargetActor;
		InitialPoint = NewInitialPoint;
		TargetPoint = NewTargetPoint;
		Duration = NewDuration;
	}

	FAnimData()
	{}
};

UCLASS(Blueprintable)
class BMC_API UBTMovementAnim : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void Init(FAnimData InAnimData);

	UFUNCTION(BlueprintCallable)
	void Stop();

	UFUNCTION()
		void CustomTick();

	UPROPERTY()
		FAnimData AnimData;

private:
	FTimerHandle TickTimerHandle;
	float DeltaTime = 0.02f;
	float TotalStepCount = 1;
	float StepCount = 0;

	UPROPERTY()
	FVector DeltaLocation;

};
