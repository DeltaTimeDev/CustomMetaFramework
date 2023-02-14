// Fill out your copyright notice in the Description page of Project Settings.


#include "BMC/BTAnimManagerActor.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ABTAnimManagerActor::ABTAnimManagerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABTAnimManagerActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABTAnimManagerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);



	
}

void ABTAnimManagerActor::AddAnim(FAnimData AnimData)
{
	UBTMovementAnim* NewAnim = NewObject<UBTMovementAnim>(this, UBTMovementAnim::StaticClass());
	NewAnim->Init(AnimData);

	if (Anims.Contains(AnimData.TargetActor))
	{
		Anims[AnimData.TargetActor]->Stop();
	}

	Anims.Add(AnimData.TargetActor, NewAnim);
	
	//Anims.Add(NewAnim);

}

void ABTAnimManagerActor::AddExplosionAnim(ABTEnginePart* EnginePart, FVector Direction, float Distance, float Speed, bool Inverse)
{
	FAnimData Data;
	Data.TargetActor = EnginePart;
	Data.InitialPoint = EnginePart->GetActorLocation();

	FVector LocationOnParent = EnginePart->SnappableComponent->GetSuperLocation();
	FVector LocationOnParentDirectioned = LocationOnParent + Direction * Distance;
	Data.TargetPoint = LocationOnParentDirectioned;
	Data.TargetRotation = EnginePart->SnappableComponent->GetSuperRotation();
	Data.Duration = 1 / Speed;
	
	AddAnim(Data);
}

void ABTAnimManagerActor::AddMergeAnim(ABTEnginePart* EnginePart, FVector Direction, float Distance, float Speed, bool Inverse)
{
	FAnimData Data;
	Data.TargetActor = EnginePart;
	Data.InitialPoint = EnginePart->GetActorLocation();

	FVector LocationOnParent = EnginePart->SnappableComponent->GetSuperLocation();
	Data.TargetPoint = LocationOnParent;
	Data.TargetRotation = EnginePart->SnappableComponent->GetSuperRotation();

	Data.Duration = 1 / Speed;

	AddAnim(Data);
}
