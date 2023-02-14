// Fill out your copyright notice in the Description page of Project Settings.


#include "BMC/BTQuizScenarioManagerActor.h"
#include "BTXRFramework/Snap/BTSnappableSubsystem.h"
#include "BMC/BTHttpTestActor.h"
#include "Kismet/GameplayStatics.h"

void ABTQuizScenarioManagerActor::TestMode()
{
	MainEngine->GrabbableComponent->bShouldGrab = false;

	for (ABTEnginePart* SubPart : SubEngineParts)
	{
		SubPart->GrabbableComponent->bShouldGrab = true;
	}


	for (size_t i = 0; i < SubEngineParts.Num(); i++)
	{

		//FVector LocationToSet{ 0,0,150 };
		//LocationToSet += MainEngine->GetActorForwardVector() * 25;
		//LocationToSet += MainEngine->GetActorRightVector() * 50 * i;
		//FVector LocationToSet = SpawnPoints[i % SpawnPoints.Num()];

		float degree = FMath::DegreesToRadians(i * 17.0f -90);
		FVector LocationToSet = FVector(20,150*FMath::Sin(degree) ,  150 * FMath::Cos(degree)+80);

		SubEngineParts[i]->SetActorLocation(LocationToSet);


	}
}

void ABTQuizScenarioManagerActor::SnapCheck(ABTEnginePart* Part)
{
	UGameInstance* GameInstance = UGameplayStatics::GetGameInstance(GetWorld());
	UBTSnappableSubsystem* SnappableSubsystem = GameInstance->GetSubsystem<UBTSnappableSubsystem>();
	float SnapDistance = SnappableSubsystem->SnapDistance;


	FName ClosestSocket;
	float Distance;
	bool Success = SnappableSubsystem->GetClosestSocket(Part->GetActorLocation(), ClosestSocket, Distance);

	if (Success)
	{
		if (Distance < SnapDistance)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString::Printf(TEXT("Distance is ok ")));
			if (Part->SnappableComponent->SuperActorSocket == ClosestSocket)
			{
				SetEnginePartResult(Part, true);
			}
			else
			{
				SetEnginePartResult(Part, false);
			}
		}
	}
}

void ABTQuizScenarioManagerActor::OnPartReleased(ABTEnginePart* Part)
{
	SnapCheck(Part);
}

void ABTQuizScenarioManagerActor::SetEnginePartResult(ABTEnginePart* Part, bool Success)
{
	QuizSheet.Add(Part->SnappableComponent->SuperActorSocket.ToString(), Success);

	UMaterialInterface* MaterialToSet = Success ? SuccessMaterial : FailMaterial;

	UStaticMeshComponent* SMC = Part->EnginePartMesh; //HoloMeshes[Part->SnappableComponent->SuperActorSocket];

	for (size_t i = 0; i < SMC->GetStaticMesh()->GetStaticMaterials().Num(); i++)
	{
		SMC->SetMaterial(i, MaterialToSet);
	}

	FVector LocationToSet{ 0,0,200 };
	LocationToSet += MainEngine->GetActorForwardVector()*150;
	LocationToSet += MainEngine->GetActorRightVector() * 50 * DoneIndex;

	Part->SetActorLocation(LocationToSet);

	DoneIndex++;
	if (DoneIndex>=5)
	{
		FString JsonString =HttpActor->CreateJson("aa", QuizSheet);
		UE_LOG(LogTemp, Error, TEXT("JsonString : %s"), *JsonString);
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString::Printf(TEXT("JsonString : %s"), *JsonString));

		//HttpActor->SendReqest(Json);
	}
}
