// Fill out your copyright notice in the Description page of Project Settings.


#include "BTXRFramework/Anchor/BTAnchorModel.h"

// Sets default values
ABTAnchorModel::ABTAnchorModel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABTAnchorModel::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABTAnchorModel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

