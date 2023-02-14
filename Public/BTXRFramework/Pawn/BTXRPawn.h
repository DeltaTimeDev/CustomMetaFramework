// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MotionControllerComponent.h"
#include "BTXRPawn.generated.h"

UCLASS()
class BMC_API ABTXRPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABTXRPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	UFUNCTION(BlueprintCallable)
	class UBTGrabToolComponent* GetGrabTool() { return GrabTool; };

	//UFUNCTION(BlueprintCallable)
	//class UBTAnchorTool* GetAnchorTool() { return AnchorTool; };

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> GrabToolModelSubClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> AnchorToolModelSubClass;

protected:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* XRDefaultSceneComponent;

	UPROPERTY(EditDefaultsOnly)
	UMotionControllerComponent* MotionControllerRight;
	UPROPERTY(EditDefaultsOnly)

	UMotionControllerComponent* MotionControllerLeft;

	UPROPERTY(EditDefaultsOnly)
	class UCameraComponent* CameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UBTGrabToolComponent* GrabTool;

	//UPROPERTY(EditDefaultsOnly)

	//class UBTAnchorTool* AnchorTool;


	UPROPERTY(EditDefaultsOnly)
	class UChildActorComponent* ToolModelActor;


	UFUNCTION()
	void OnAnchorToolActivated(UActorComponent* Component, bool bReset);

	UFUNCTION()
	void OnGrabToolActivated(UActorComponent* Component, bool bReset);
};
