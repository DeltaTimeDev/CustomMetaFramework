// Fill out your copyright notice in the Description page of Project Settings.


#include "BMC/BTEnginePart.h"
#include "BTXRFramework/Snap/BTSnappableSubsystem.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABTEnginePart::ABTEnginePart()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//DefaultRootComponent = CreateDefaultSubobject<USceneComponent>("BTRootComponent");
	//RootComponent = DefaultRootComponent;

	EnginePartMesh = CreateDefaultSubobject<UStaticMeshComponent>("EnginePartMesh");
	//EnginePartMesh->SetupAttachment(DefaultRootComponent);
	RootComponent = EnginePartMesh;


	SnappableComponent = CreateDefaultSubobject<UBTSnappableComponent>("SnappableComponent");
	SnappableComponent->SetupAttachment(EnginePartMesh);

	GrabbableComponent = CreateDefaultSubobject<UBTGrabbableComponent>("GrabbableComponent");
	GrabbableComponent->SetupAttachment(EnginePartMesh);

	InfoWidgetActor = CreateDefaultSubobject<UChildActorComponent>("InfoWidgetActor");
	InfoWidgetActor->SetupAttachment(EnginePartMesh);


}

// Called when the game starts or when spawned
void ABTEnginePart::BeginPlay()
{
	Super::BeginPlay();
	

	GrabbableComponent->OnGrabbed.AddDynamic(this, &ABTEnginePart::OnGrabbed);
	GrabbableComponent->OnReleased.AddDynamic(this, &ABTEnginePart::OnReleased);

	if (bShouldStartAttached)
	{
		///SnappableComponent->AttachToSuperActor();
	}
	
}

// Called every frame
void ABTEnginePart::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABTEnginePart::OnGrabbed(int State)
{
	OnEnginePartSelected.Broadcast(this);
}

void ABTEnginePart::OnReleased(int State)
{
	OnEnginePartReleased.Broadcast(this);
	//CheckSnapping();
}

void ABTEnginePart::Select()
{
	InfoWidgetActor->SetHiddenInGame(false);
}

void ABTEnginePart::Deselect()
{
	InfoWidgetActor->SetHiddenInGame(true);
}

void ABTEnginePart::CheckSnapping()
{
	UGameInstance* GameInstance = UGameplayStatics::GetGameInstance(GetWorld());
	UBTSnappableSubsystem* SnappableSubsystem = GameInstance->GetSubsystem<UBTSnappableSubsystem>();
	float SnapDistance = SnappableSubsystem->SnapDistance;


	FName ClosestSocket;
	float Distance;
	bool Success = SnappableSubsystem->GetClosestSocket(GetActorLocation(),ClosestSocket,Distance);

	if (Success)
	{
		if (Distance < SnapDistance)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString::Printf(TEXT("Distance is ok ")));
			if (SnappableComponent->SuperActorSocket == ClosestSocket)
			{
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString::Printf(TEXT("SnappSuccess")));
			}
			else
			{
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString::Printf(TEXT("Snapp is fail")));
			}

		}
	}

}

void ABTEnginePart::DeactivatePart()
{
	//EnginePartMesh->SetHiddenInGame(true);
	SnappableComponent->SetActive(false);
	GrabbableComponent->SetActive(false);
	InfoWidgetActor->SetHiddenInGame(false);
}

