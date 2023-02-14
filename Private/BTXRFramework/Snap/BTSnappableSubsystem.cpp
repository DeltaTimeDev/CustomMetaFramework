// Fill out your copyright notice in the Description page of Project Settings.


#include "BTXRFramework/Snap/BTSnappableSubsystem.h"
#include "BMC/BTEnginePart.h"

void UBTSnappableSubsystem::Register(UBTSnappableComponent* SnappableComponent)
{
	SnappableComponents.AddUnique(SnappableComponent);
}

void UBTSnappableSubsystem::RegisterSnappableSockets(ABTEnginePart* InMainEngine)
{
	MainEngine = InMainEngine;
	AllSocketNames = MainEngine->EnginePartMesh->GetAllSocketNames();
}

UBTSnappableComponent* UBTSnappableSubsystem::GetClosestComponent(FVector Location)
{
	return nullptr;
}

bool UBTSnappableSubsystem::GetClosestSocket(FVector Location, FName& SocketName, float& Distance)
{
	FName ClosestSocketName;
	float MinDistance = TNumericLimits<float>::Max();
	bool bFound = false;

	for (FName Name : AllSocketNames)
	{
		float Dist = FVector::Dist(MainEngine->EnginePartMesh->GetSocketLocation(Name), Location);
		if (Dist < MinDistance)
		{
			ClosestSocketName = Name;
			MinDistance = Dist;
			bFound = true;
		}
	}

	if (bFound)
	{
		Distance = MinDistance;
		SocketName = ClosestSocketName;
		return true;
	}
	return false;
}


