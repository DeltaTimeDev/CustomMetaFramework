// Fill out your copyright notice in the Description page of Project Settings.


#include "BTXRFramework/Grab/BTGrabToolComponent.h"
#include "BTXRFramework/Grab/BTGrabbableComponent.h"
#include "Kismet/GameplayStatics.h"
#include "BTXRFramework/Grab/BTGrabbableSubsystem.h"

void UBTGrabToolComponent::BeginPlay() //TODO Does below should be in beginplay? works but maybe more elegant
{
	Super::BeginPlay();

	UGameInstance* GameInstance = UGameplayStatics::GetGameInstance(GetWorld());
	GrabbableSubsystemRef = GameInstance->GetSubsystem<UBTGrabbableSubsystem>();
}



void UBTGrabToolComponent::OnRightGrabPressed()
{
	TryToGrab();
}

void UBTGrabToolComponent::OnRightGrabReleased()
{
	TryToRelease();
}

void UBTGrabToolComponent::TryToGrab()
{	
	//UBTGrabbableComponent* ClosestToolGrabComponent = GrabbableSubsystemRef->GetClosestComponent(GetComponentLocation());
	
	
	UBTGrabbableComponent* ClosestToolGrabComponent = GrabbableSubsystemRef->GetCollidingComponent(GetGrabPoint(),10);

	if (ClosestToolGrabComponent)
	{
		if (ClosestToolGrabComponent->TryGrab(MotionController))
		{
			HeldComponent = ClosestToolGrabComponent;
		}
	}

	//float Distance = FVector::Dist(GetGrabPoint(), ClosestToolGrabComponent->GetComponentLocation());



	//if (ClosestToolGrabComponent && Distance < ExpectedDistance)
	//{
	//	if (ClosestToolGrabComponent->TryGrab(MotionController))
	//	{
	//		HeldComponent = ClosestToolGrabComponent;
	//	}
	//}
}

void UBTGrabToolComponent::TryToRelease()
{
	if (HeldComponent)
	{
		if (HeldComponent->TryRelease())
		{
			HeldComponent = nullptr;
		}
	}
}

FVector UBTGrabToolComponent::GetGrabPoint()
{
	return GetComponentLocation();
}
