// Fill out your copyright notice in the Description page of Project Settings.


#include "BTXRFramework/Grab/BTGrabbableComponent.h"
#include "MotionControllerComponent.h"
#include "Kismet/GameplayStatics.h"
#include "BTXRFramework/Grab/BTGrabbableSubsystem.h"

UBTGrabbableComponent::UBTGrabbableComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

bool UBTGrabbableComponent::TryGrab(UMotionControllerComponent* MotionController)
{
	if (!bShouldGrab){ return false; }

	SetPrimitiveCompPhysics(false);

	if (AttachParentToMotionController(MotionController))
	{
		bIsHeld = true;
		//TODO snap types
	}

	if (bIsHeld)
	{
		MotionControllerRef = MotionController;
		OnGrabbed.Broadcast(1);
		//Play Haptics
		return true;
	}
	else
	{
		return false;
	}
}

bool UBTGrabbableComponent::TryRelease()
{
	GetOwner()->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
	bIsHeld = false;

	if (!bIsHeld)
	{
		OnReleased.Broadcast(1);
		return true;
	}

	return false;
}

void UBTGrabbableComponent::BeginPlay()
{
	Super::BeginPlay();

	UGameInstance* GameInstance = UGameplayStatics::GetGameInstance(GetWorld());
	GrabbableSubsystemRef = GameInstance->GetSubsystem<UBTGrabbableSubsystem>();
	GrabbableSubsystemRef->Register(this);

	SetShouldSimulateOnDrop();
	if (Cast<UPrimitiveComponent>(GetAttachParent()))
	{
		Cast<UPrimitiveComponent>(GetAttachParent())->SetCollisionProfileName(FName("PhysicsActor"), true);
	}	
}

void UBTGrabbableComponent::SetPrimitiveCompPhysics(bool bSimulate)
{
	if (Cast<UPrimitiveComponent>(GetAttachParent()))
		Cast<UPrimitiveComponent>(GetAttachParent())->SetSimulatePhysics(bSimulate);
	else
		UE_LOG(LogTemp, Error, TEXT("GrabComponent->SetSimulatingParent->Cast To PrimitiveComponent FAILED"));

}

bool UBTGrabbableComponent::AttachParentToMotionController(UMotionControllerComponent* MotionController)
{
	bool SuccessAttach = GetAttachParent()->AttachToComponent(MotionController, FAttachmentTransformRules::KeepWorldTransform);
	return SuccessAttach; //TODO maybe error reason will be logged
}

void UBTGrabbableComponent::SetShouldSimulateOnDrop()
{
	if (Cast<UPrimitiveComponent>(GetAttachParent()) || Cast<UPrimitiveComponent>(GetAttachParent())->IsAnySimulatingPhysics())
	{
		bSimulateOnDrop = true;
	}
}

