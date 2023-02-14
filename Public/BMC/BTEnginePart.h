// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BTXRFramework/Snap/BTSnappableComponent.h"
#include "BTXRFramework/Grab/BTGrabbableComponent.h"
#include "Components/ChildActorComponent.h"
#include "BTEnginePart.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEngineStateChange, ABTEnginePart*, Engine);


UCLASS()
class BMC_API ABTEnginePart : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABTEnginePart();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly)
	USceneComponent* DefaultRootComponent;

	UPROPERTY(EditDefaultsOnly)
	UBTSnappableComponent* SnappableComponent;

	UPROPERTY(EditDefaultsOnly)
	UBTGrabbableComponent* GrabbableComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadwrite)
	UStaticMeshComponent* EnginePartMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadwrite)
	UChildActorComponent* InfoWidgetActor;

	/*UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> InfoWidgetActorClass;*/

	UFUNCTION()
	void OnGrabbed(int State);

	UFUNCTION()
	void OnReleased(int State);

	bool bShouldStartAttached = true;

	UFUNCTION()
	void Select();

	UFUNCTION()
	void Deselect();

	UPROPERTY()
	FEngineStateChange OnEnginePartSelected;

	UPROPERTY()
	FEngineStateChange OnEnginePartReleased;

	void CheckSnapping();

	void DeactivatePart();
	
};
