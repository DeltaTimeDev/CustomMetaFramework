// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BTHttpTestActor.generated.h"

UCLASS()
class BMC_API ABTHttpTestActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABTHttpTestActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	void LoginWithSpaceTrack(const FString& NewObjectId, const FString& NewUser, const FString& NewPassword);
	void CreateRequest();

	UFUNCTION(BlueprintCallable)
	FString CreateJson(FString MacId, TMap<FString,bool> Quests);

};
