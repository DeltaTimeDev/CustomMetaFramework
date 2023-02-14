// Fill out your copyright notice in the Description page of Project Settings.


#include "BTXRFramework/Grab/BTGrabToolHandComponent.h"
#include "OculusXRHandComponent.h"

void UBTGrabToolHandComponent::BeginPlay()
{
	Super::BeginPlay();
}

FVector UBTGrabToolHandComponent::GetGrabPoint()
{
	if (GetAttachmentRootActor()) // TODO will be changed may be interface ?
	{
		UActorComponent* ActorComponent = (USceneComponent*)GetAttachmentRootActor()->GetDefaultSubobjectByName(FName(TEXT("RightHandTracking_Custom")));
			
			//GetAttachmentRootActor()->GetComponentsByClass(UOculusXRHandComponent::StaticClass());

		if (ActorComponent)
		{
			UOculusXRHandComponent* HandComponent = Cast<UOculusXRHandComponent>(ActorComponent);
			
			if (HandComponent)
			{
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString::Printf(TEXT("FOUND %s"), *HandComponent->GetBoneLocationByName(GrabBoneName, EBoneSpaces::WorldSpace).ToString()));
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString::Printf(TEXT("NAME %s"), *GrabBoneName.ToString()));

				 return HandComponent->GetBoneLocationByName(GrabBoneName, EBoneSpaces::WorldSpace);
			}
		}
	}
	
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(TEXT("NOT FOUND ")));

	return FVector();
}
