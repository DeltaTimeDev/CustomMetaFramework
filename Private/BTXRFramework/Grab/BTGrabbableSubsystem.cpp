// Fill out your copyright notice in the Description page of Project Settings.


#include "BTXRFramework/Grab/BTGrabbableSubsystem.h"
#include "Kismet/GameplayStatics.h"

void UBTGrabbableSubsystem::Register(UBTGrabbableComponent* GrabbableComponent)
{
	GrabbableComponents.AddUnique(GrabbableComponent);
}

UBTGrabbableComponent* UBTGrabbableSubsystem::GetClosestComponent(FVector Point)
{
	UBTGrabbableComponent* ClosestComponent = nullptr;
	float MinDistance = TNumericLimits<float>::Max();

	for (UBTGrabbableComponent* Component : GrabbableComponents)
	{
		if (!Component->bShouldGrab) continue;

		float Dist = FVector::Dist(Component->GetComponentLocation(), Point);
		if (Dist < MinDistance)
		{
			ClosestComponent = Component;
			MinDistance = Dist;
		}
	}
	return ClosestComponent;
}

UBTGrabbableComponent* UBTGrabbableSubsystem::GetCollidingComponent(FVector Point, float DetectRadius)
{
	TArray<AActor*> IgnoredActors;
	//IgnoredActors.Add(GetOwner();
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypesArray;
	ObjectTypesArray.Reserve(1);
	ObjectTypesArray.Emplace(ECollisionChannel::ECC_PhysicsBody);
	TArray<FHitResult> OutHits;

	bool hit = UKismetSystemLibrary::SphereTraceMultiByProfile(GetWorld(), Point, Point, DetectRadius, TEXT("PhysicsActor"), false, IgnoredActors, EDrawDebugTrace::None, OutHits, true);

	if (hit)
	{
		for (size_t i = 0; i < OutHits.Num(); i++)
		{
			UE_LOG(LogTemp, Warning, TEXT("HitActor:%s"), *OutHits[i].GetActor()->GetName());
			UBTGrabbableComponent* GrabbableComponent = (UBTGrabbableComponent*)OutHits[i].GetActor()->GetComponentByClass(UBTGrabbableComponent::StaticClass());
			if (GrabbableComponent && GrabbableComponent->bShouldGrab)
			{
				return GrabbableComponent;
			}
		}
	}
	return nullptr;
}
