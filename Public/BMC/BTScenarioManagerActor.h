// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BMC/BTEnginePart.h"
#include "BTScenarioManagerActor.generated.h"

UCLASS()
class BMC_API ABTScenarioManagerActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABTScenarioManagerActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void SpawnParts(FVector Origin);

	UFUNCTION(BlueprintCallable)
	void SwitchToMode1();

	UFUNCTION(BlueprintCallable)
	void SwitchToMode2();

	UPROPERTY(EditAnywhere)
	class ABTAnimManagerActor* AnimationManagerRef;

	UPROPERTY(EditAnywhere)
	TSubclassOf<ABTEnginePart> MainEngineClass;
	UPROPERTY(EditAnywhere)
	TSubclassOf<ABTEnginePart> ACCControlUnitClass;
	UPROPERTY(EditAnywhere)
	TSubclassOf<ABTEnginePart> ACControlUnitClass;
	UPROPERTY(EditAnywhere)
	TSubclassOf<ABTEnginePart> AirCoolingUnitClass;
	UPROPERTY(EditAnywhere)
	TSubclassOf<ABTEnginePart> BeltsClass;
	UPROPERTY(EditAnywhere)
	TSubclassOf<ABTEnginePart> CoolingSystemClass;
	UPROPERTY(EditAnywhere)
	TSubclassOf<ABTEnginePart> ElectronicControllerUnitClass;
	UPROPERTY(EditAnywhere)
	TSubclassOf<ABTEnginePart> ExhaustManifoldClass;
	UPROPERTY(EditAnywhere)
	TSubclassOf<ABTEnginePart> FuelFilterClass;
	UPROPERTY(EditAnywhere)
	TSubclassOf<ABTEnginePart> FuelPumpClass;
	UPROPERTY(EditAnywhere)
	TSubclassOf<ABTEnginePart> IntakeManifoldClass;
	UPROPERTY(EditAnywhere)
	TSubclassOf<ABTEnginePart> OilFilterClass;
	UPROPERTY(EditAnywhere)
	TSubclassOf<ABTEnginePart> TurboChargeClass;

	UPROPERTY(EditAnywhere,BlueprintReadwrite)
	TArray<ABTEnginePart*> SubEngineParts;

	UPROPERTY()
	ABTEnginePart* MainEngine;
	UPROPERTY()
	ABTEnginePart* ACCControlUnit;
	UPROPERTY()
	ABTEnginePart* ACControlUnit;
	UPROPERTY()
	ABTEnginePart* AirCoolingUnit;
	UPROPERTY()
	ABTEnginePart* Belts;
	UPROPERTY()
	ABTEnginePart* CoolingSystem;
	UPROPERTY()
	ABTEnginePart* ElectronicControllerUnit;
	UPROPERTY()
	ABTEnginePart* ExhaustManifold;
	UPROPERTY()
	ABTEnginePart* FuelFilter;
	UPROPERTY()
	ABTEnginePart* FuelPump;
	UPROPERTY()
	ABTEnginePart* IntakeManifold;
	UPROPERTY()
	ABTEnginePart* OilFilter;
	UPROPERTY()
	ABTEnginePart* TurboCharge;

	UFUNCTION()
	void OnAnimationFinished(int State);


	UPROPERTY()
	ABTEnginePart* SelectedPart;

	UFUNCTION(BlueprintCallable)
	void SelectPart(ABTEnginePart* Part);


	UPROPERTY(EditAnywhere)
	float AnimSpeed;


	void SpawnHolograms(ABTEnginePart* Part);
	void HideHolograms();
	void ShowHolograms();


	UPROPERTY(EditAnywhere)
	class UMaterialInterface* HoloMaterial;

	UPROPERTY()
	TMap<FName,UStaticMeshComponent*> HoloMeshes;


	UFUNCTION()
	void OnPartGrabbed(ABTEnginePart* Part);
	UFUNCTION()
	virtual void OnPartReleased(ABTEnginePart* Part);

};
