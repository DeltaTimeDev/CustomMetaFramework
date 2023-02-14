// Fill out your copyright notice in the Description page of Project Settings.


#include "BMC/BTMovementAnim.h"
#include "BMC/BTEnginePart.h"
#include "BTXRFramework/Snap/BTSnappableComponent.h"

void UBTMovementAnim::Init(FAnimData InAnimData)
{
	AnimData = InAnimData;

	GetWorld()->GetTimerManager().SetTimer(TickTimerHandle, this, &UBTMovementAnim::CustomTick, DeltaTime, true);
	TotalStepCount = AnimData.Duration / DeltaTime;
	DeltaLocation = (AnimData.TargetPoint - AnimData.InitialPoint) / TotalStepCount;
}

void UBTMovementAnim::Stop()
{
	GetWorld()->GetTimerManager().ClearTimer(TickTimerHandle);
	ConditionalBeginDestroy();
}

void UBTMovementAnim::CustomTick()
{

	if (AnimData.TargetActor)
	{
		FVector CurrentLocation = AnimData.TargetActor->GetActorLocation();

		//if (FMath::IsNearlyZero(FVector::Dist(CurrentLocation, AnimData.TargetPoint), 0.1f))
		//{
		//	GetWorld()->GetTimerManager().ClearTimer(TickTimerHandle);
		//	ConditionalBeginDestroy();
		//}
		if (StepCount >= TotalStepCount)
		{
			AnimData.TargetActor->SnappableComponent->Init(nullptr);
			Stop();
		}
		else
		{
			AnimData.TargetActor->SetActorLocation(CurrentLocation + DeltaLocation);
			AnimData.TargetActor->SetActorRotation(FMath::Lerp(AnimData.TargetActor->GetActorRotation(), AnimData.TargetRotation,0.5f));
			StepCount++;
		}
	}
}
