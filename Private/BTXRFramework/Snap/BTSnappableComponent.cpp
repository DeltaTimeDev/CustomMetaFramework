// Fill out your copyright notice in the Description page of Project Settings.


#include "BTXRFramework/Snap/BTSnappableComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "BTXRFramework/Snap/BTSnappableSubsystem.h"

// Sets default values for this component's properties
UBTSnappableComponent::UBTSnappableComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;




	// ...
}


// Called when the game starts
void UBTSnappableComponent::BeginPlay()
{
	Super::BeginPlay();

	UGameInstance* GameInstance = UGameplayStatics::GetGameInstance(GetWorld());
	SnappableSubsystemRef = GameInstance->GetSubsystem<UBTSnappableSubsystem>();
	SnappableSubsystemRef->Register(this);	
}


// Called every frame
void UBTSnappableComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UBTSnappableComponent::Init(AActor* InSuperActor)
{
	if (InSuperActor)
	{
		SuperActor = InSuperActor;
	}
	AttachToSuperActor();
}

void UBTSnappableComponent::AttachToSuperActor()
{
	if (bShouldSnap)
	{
		check(SuperActor);

		//TODO Find more elegant way. urgent
		UStaticMeshComponent* StaticMesh = Cast<UStaticMeshComponent>(SuperActor->GetComponentByClass(UStaticMeshComponent::StaticClass()));
		GetAttachParent()->AttachToComponent(StaticMesh, FAttachmentTransformRules::SnapToTargetIncludingScale, SuperActorSocket);
	}
	
}

FVector UBTSnappableComponent::GetSuperLocation()
{
	UStaticMeshComponent* SuperActorStaticMesh = Cast<UStaticMeshComponent>(SuperActor->GetComponentByClass(UStaticMeshComponent::StaticClass()));
	if (!SuperActorStaticMesh)
	{
		UE_LOG(LogTemp, Error, TEXT("SuperActor should have mesh that has sockets"));
		return FVector();
	}
	return SuperActorStaticMesh->GetSocketLocation(SuperActorSocket);
}

FRotator UBTSnappableComponent::GetSuperRotation()
{
	UStaticMeshComponent* SuperActorStaticMesh = Cast<UStaticMeshComponent>(SuperActor->GetComponentByClass(UStaticMeshComponent::StaticClass()));
	if (!SuperActorStaticMesh)
	{
		UE_LOG(LogTemp, Error, TEXT("SuperActor should have mesh that has sockets"));
		return FRotator();
	}
	return SuperActorStaticMesh->GetSocketRotation(SuperActorSocket);
}

