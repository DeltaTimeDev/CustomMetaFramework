// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BMC/BTScenarioManagerActor.h"
#include "BTQuizScenarioManagerActor.generated.h"

/**
 * 
 */
UCLASS()
class BMC_API ABTQuizScenarioManagerActor : public ABTScenarioManagerActor
{
	GENERATED_BODY()


public:

	UFUNCTION(BlueprintCallable)
	void TestMode();

	void SnapCheck(ABTEnginePart* Part);


	virtual void OnPartReleased(ABTEnginePart* Part) override;

	UPROPERTY(EditAnywhere)
	class UMaterialInterface* FailMaterial;

	UPROPERTY(EditAnywhere)
	class UMaterialInterface* SuccessMaterial;


	UPROPERTY()
	TMap<FString, bool> QuizSheet;

	int DoneIndex = 0;


	void SetEnginePartResult(ABTEnginePart* Part, bool Success);


	UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true))
	TArray<FVector> SpawnPoints;

	UPROPERTY(EditAnywhere)
	class ABTHttpTestActor* HttpActor;
	
};
