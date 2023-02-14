// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BMC/BTEnginePart.h"
#include "BMC/BTMovementAnim.h"
#include "BTAnimManagerActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAnimStateChanged, int32, State);


UCLASS()
class BMC_API ABTAnimManagerActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABTAnimManagerActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void AddAnim(FAnimData AnimData);
	void AddExplosionAnim(ABTEnginePart* EnginePart, FVector Direction, float Distance, float Speed, bool Inverse = false);
	void AddMergeAnim(ABTEnginePart* EnginePart, FVector Direction, float Distance, float Speed, bool Inverse = false);


	UPROPERTY()
	TMap<AActor*,UBTMovementAnim*> Anims;
};
