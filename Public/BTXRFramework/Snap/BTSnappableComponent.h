// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "BTSnappableComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BMC_API UBTSnappableComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBTSnappableComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void Init(AActor* InSuperActor);

	UPROPERTY(EditAnywhere)
	AActor* SuperActor;

	UPROPERTY(EditAnywhere)
	FName SuperActorSocket;

	UFUNCTION(BlueprintCallable)
	void AttachToSuperActor();

	UPROPERTY(EditAnywhere)
	bool bShouldSnap = false;

	UFUNCTION(BlueprintCallable)
	FVector GetSuperLocation();

	UFUNCTION(BlueprintCallable)
	FRotator GetSuperRotation();

	UPROPERTY()
	class UBTSnappableSubsystem* SnappableSubsystemRef;
};
