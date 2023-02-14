// Fill out your copyright notice in the Description page of Project Settings.


#include "BTXRFramework/Component/BTSceneComponent.h"
#include "MotionControllerComponent.h"


UBTSceneComponent::UBTSceneComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UBTSceneComponent::BeginPlay() //TODO Does below should be in beginplay? works but maybe more elegant
{
	Super::BeginPlay();

	USceneComponent* s = GetAttachParent();
	MotionController = (UMotionControllerComponent*)GetAttachParent();
	check(MotionController);
	
	APawn* Pawn = Cast<APawn>(GetAttachmentRootActor());
	
	//check(Pawn);
	//check(Pawn->InputComponent);


	if (Pawn && Pawn->InputComponent)
	{
		UInputComponent* InputComponent = CastChecked<UInputComponent>(Pawn->InputComponent);
		InputComponent->BindAction("GrabRight", IE_Pressed, this, &UBTSceneComponent::OnRightGrabPressed);
		InputComponent->BindAction("GrabRight", IE_Released, this, &UBTSceneComponent::OnRightGrabReleased);
	}

	
}

void UBTSceneComponent::OnRightGrabPressed()
{
}

void UBTSceneComponent::OnRightGrabReleased()
{
}


