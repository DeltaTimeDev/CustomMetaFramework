// Fill out your copyright notice in the Description page of Project Settings.


#include "BMC/BTScenarioManagerActor.h"
#include "BMC/BTAnimManagerActor.h"
// Sets default values
ABTScenarioManagerActor::ABTScenarioManagerActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABTScenarioManagerActor::BeginPlay()
{
	Super::BeginPlay();

	//AnimationManagerRef->OnAnimationsFinished.AddDynamic(this, &ABTScenarioManagerActor::OnAnimationFinished);
}

// Called every frame
void ABTScenarioManagerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABTScenarioManagerActor::SpawnParts(FVector Origin)
{
	FActorSpawnParameters Params;
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	FRotator Rotation = FRotator::ZeroRotator;

	MainEngine = GetWorld()->SpawnActor<ABTEnginePart>(MainEngineClass, Origin, Rotation, Params);

	ACCControlUnit = GetWorld()->SpawnActor<ABTEnginePart>(ACCControlUnitClass, Origin, Rotation, Params);
	ACCControlUnit->SnappableComponent->Init(MainEngine);
	ACCControlUnit->OnEnginePartSelected.AddDynamic(this, &ABTScenarioManagerActor::OnPartGrabbed);
	ACCControlUnit->OnEnginePartReleased.AddDynamic(this, &ABTScenarioManagerActor::OnPartReleased);


	ACControlUnit = GetWorld()->SpawnActor<ABTEnginePart>(ACControlUnitClass, Origin, Rotation, Params);
	ACControlUnit->SnappableComponent->Init(MainEngine);
	ACControlUnit->OnEnginePartSelected.AddDynamic(this, &ABTScenarioManagerActor::OnPartGrabbed);
	ACControlUnit->OnEnginePartReleased.AddDynamic(this, &ABTScenarioManagerActor::OnPartReleased);


	AirCoolingUnit = GetWorld()->SpawnActor<ABTEnginePart>(AirCoolingUnitClass, Origin, Rotation, Params);
	AirCoolingUnit->SnappableComponent->Init(MainEngine);
	AirCoolingUnit->OnEnginePartSelected.AddDynamic(this, &ABTScenarioManagerActor::OnPartGrabbed);
	AirCoolingUnit->OnEnginePartReleased.AddDynamic(this, &ABTScenarioManagerActor::OnPartReleased);


	Belts = GetWorld()->SpawnActor<ABTEnginePart>(BeltsClass, Origin, Rotation, Params);
	Belts->SnappableComponent->Init(MainEngine);
	Belts->OnEnginePartSelected.AddDynamic(this, &ABTScenarioManagerActor::OnPartGrabbed);
	Belts->OnEnginePartReleased.AddDynamic(this, &ABTScenarioManagerActor::OnPartReleased);


	CoolingSystem = GetWorld()->SpawnActor<ABTEnginePart>(CoolingSystemClass, Origin, Rotation, Params);
	CoolingSystem->SnappableComponent->Init(MainEngine);
	CoolingSystem->OnEnginePartSelected.AddDynamic(this, &ABTScenarioManagerActor::OnPartGrabbed);
	CoolingSystem->OnEnginePartReleased.AddDynamic(this, &ABTScenarioManagerActor::OnPartReleased);


	ElectronicControllerUnit = GetWorld()->SpawnActor<ABTEnginePart>(ElectronicControllerUnitClass, Origin, Rotation, Params);
	ElectronicControllerUnit->SnappableComponent->Init(MainEngine);
	ElectronicControllerUnit->OnEnginePartSelected.AddDynamic(this, &ABTScenarioManagerActor::OnPartGrabbed);
	ElectronicControllerUnit->OnEnginePartReleased.AddDynamic(this, &ABTScenarioManagerActor::OnPartReleased);


	ExhaustManifold = GetWorld()->SpawnActor<ABTEnginePart>(ExhaustManifoldClass, Origin, Rotation, Params);
	ExhaustManifold->SnappableComponent->Init(MainEngine);
	ExhaustManifold->OnEnginePartSelected.AddDynamic(this, &ABTScenarioManagerActor::OnPartGrabbed);
	ExhaustManifold->OnEnginePartReleased.AddDynamic(this, &ABTScenarioManagerActor::OnPartReleased);


	FuelFilter = GetWorld()->SpawnActor<ABTEnginePart>(FuelFilterClass, Origin, Rotation, Params);
	FuelFilter->SnappableComponent->Init(MainEngine);
	FuelFilter->OnEnginePartSelected.AddDynamic(this, &ABTScenarioManagerActor::OnPartGrabbed);
	FuelFilter->OnEnginePartReleased.AddDynamic(this, &ABTScenarioManagerActor::OnPartReleased);


	FuelPump = GetWorld()->SpawnActor<ABTEnginePart>(FuelPumpClass, Origin, Rotation, Params);
	FuelPump->SnappableComponent->Init(MainEngine);
	FuelPump->OnEnginePartSelected.AddDynamic(this, &ABTScenarioManagerActor::OnPartGrabbed);
	FuelPump->OnEnginePartReleased.AddDynamic(this, &ABTScenarioManagerActor::OnPartReleased);



	IntakeManifold = GetWorld()->SpawnActor<ABTEnginePart>(IntakeManifoldClass, Origin, Rotation, Params);
	IntakeManifold->SnappableComponent->Init(MainEngine);
	IntakeManifold->OnEnginePartSelected.AddDynamic(this, &ABTScenarioManagerActor::OnPartGrabbed);
	IntakeManifold->OnEnginePartReleased.AddDynamic(this, &ABTScenarioManagerActor::OnPartReleased);


	OilFilter = GetWorld()->SpawnActor<ABTEnginePart>(OilFilterClass, Origin, Rotation, Params);
	OilFilter->SnappableComponent->Init(MainEngine);
	OilFilter->OnEnginePartSelected.AddDynamic(this, &ABTScenarioManagerActor::OnPartGrabbed);
	OilFilter->OnEnginePartReleased.AddDynamic(this, &ABTScenarioManagerActor::OnPartReleased);



	TurboCharge = GetWorld()->SpawnActor<ABTEnginePart>(TurboChargeClass, Origin, Rotation, Params);
	TurboCharge->SnappableComponent->Init(MainEngine);
	TurboCharge->OnEnginePartSelected.AddDynamic(this, &ABTScenarioManagerActor::OnPartGrabbed);
	TurboCharge->OnEnginePartReleased.AddDynamic(this, &ABTScenarioManagerActor::OnPartReleased);


	SubEngineParts.Add(ACCControlUnit);
	SubEngineParts.Add(ACControlUnit);
	SubEngineParts.Add(AirCoolingUnit);
	SubEngineParts.Add(Belts);
	SubEngineParts.Add(CoolingSystem);
	SubEngineParts.Add(ElectronicControllerUnit);
	SubEngineParts.Add(ExhaustManifold);
	SubEngineParts.Add(FuelFilter);
	SubEngineParts.Add(FuelPump);
	SubEngineParts.Add(IntakeManifold);
	SubEngineParts.Add(OilFilter);
	SubEngineParts.Add(TurboCharge);


	for (ABTEnginePart* Part : SubEngineParts)
	{
		SpawnHolograms(Part);
	}



	//SwitchToMode1();
}
FTimerHandle TimerHandle_SaveAnchors;
void ABTScenarioManagerActor::SwitchToMode1()
{
	if (SelectedPart)
	{
		SelectedPart->Deselect();
	}


	MainEngine->GrabbableComponent->bShouldGrab = true;

	for (ABTEnginePart* SubPart : SubEngineParts)
	{
		SubPart->GrabbableComponent->bShouldGrab = false;
	}

	AnimationManagerRef->AddMergeAnim(ACCControlUnit, MainEngine->GetActorForwardVector(), 50, AnimSpeed);
	AnimationManagerRef->AddMergeAnim(ACControlUnit, -MainEngine->GetActorForwardVector(), 50, AnimSpeed);
	AnimationManagerRef->AddMergeAnim(AirCoolingUnit, -MainEngine->GetActorForwardVector(), 50, AnimSpeed);
	AnimationManagerRef->AddMergeAnim(Belts, -MainEngine->GetActorRightVector(), 50, AnimSpeed);
	AnimationManagerRef->AddMergeAnim(CoolingSystem, MainEngine->GetActorForwardVector(), 50, AnimSpeed);
	AnimationManagerRef->AddMergeAnim(ElectronicControllerUnit, -MainEngine->GetActorForwardVector(), 50, AnimSpeed);
	AnimationManagerRef->AddMergeAnim(ExhaustManifold, MainEngine->GetActorForwardVector(), 40, AnimSpeed);
	AnimationManagerRef->AddMergeAnim(FuelFilter, -MainEngine->GetActorForwardVector(), 50, AnimSpeed);
	AnimationManagerRef->AddMergeAnim(FuelPump, -MainEngine->GetActorForwardVector(), 50, AnimSpeed);
	AnimationManagerRef->AddMergeAnim(IntakeManifold, -MainEngine->GetActorForwardVector(), 35, AnimSpeed);
	AnimationManagerRef->AddMergeAnim(OilFilter, MainEngine->GetActorForwardVector(), 35, AnimSpeed);
	AnimationManagerRef->AddMergeAnim(TurboCharge, MainEngine->GetActorForwardVector(), 55, AnimSpeed);


	
	HideHolograms();
}

void ABTScenarioManagerActor::SwitchToMode2()
{
	if (SelectedPart)
	{
		SelectedPart->Deselect();
	}


	MainEngine->GrabbableComponent->bShouldGrab = false;

	for (ABTEnginePart* SubPart : SubEngineParts)
	{
		SubPart->GrabbableComponent->bShouldGrab = true;
	}



					

	AnimationManagerRef->AddExplosionAnim(ACCControlUnit, MainEngine->GetActorForwardVector(), 50, AnimSpeed, true);
	AnimationManagerRef->AddExplosionAnim(ACControlUnit, -MainEngine->GetActorForwardVector(), 50, AnimSpeed, true);
	AnimationManagerRef->AddExplosionAnim(AirCoolingUnit, -MainEngine->GetActorForwardVector(), 50, AnimSpeed, true);
	AnimationManagerRef->AddExplosionAnim(Belts, -MainEngine->GetActorRightVector(), 50, AnimSpeed, true);
	AnimationManagerRef->AddExplosionAnim(CoolingSystem, MainEngine->GetActorForwardVector(), 50, AnimSpeed, true);
	AnimationManagerRef->AddExplosionAnim(ElectronicControllerUnit, -MainEngine->GetActorForwardVector(), 50, AnimSpeed, true);
	AnimationManagerRef->AddExplosionAnim(ExhaustManifold, MainEngine->GetActorForwardVector(), 40, AnimSpeed, true);
	AnimationManagerRef->AddExplosionAnim(FuelFilter, -MainEngine->GetActorForwardVector(), 50, AnimSpeed, true);
	AnimationManagerRef->AddExplosionAnim(FuelPump, -MainEngine->GetActorForwardVector(), 50, AnimSpeed, true);
	AnimationManagerRef->AddExplosionAnim(IntakeManifold, -MainEngine->GetActorForwardVector(), 35, AnimSpeed, true);
	AnimationManagerRef->AddExplosionAnim(OilFilter, MainEngine->GetActorForwardVector(), 35, AnimSpeed, true);
	AnimationManagerRef->AddExplosionAnim(TurboCharge, MainEngine->GetActorForwardVector(), 55, AnimSpeed, true);

	//AnimationManagerRef->AddAnim(ACCControlUnit, MainEngine->GetActorUpVector() + MainEngine->GetActorForwardVector(), 10, 0.15f);

	ShowHolograms();

}

void ABTScenarioManagerActor::OnAnimationFinished(int State)
{
	UE_LOG(LogTemp, Error, TEXT("ABTScenarioManagerActor::OnAnimationFinished"));

	//UnderEngine->GrabbableComponent->bShouldGrab = true;
	//RightEngine->GrabbableComponent->bShouldGrab = true;
}

void ABTScenarioManagerActor::SelectPart(ABTEnginePart* Part)
{
	if (SelectedPart)
	{
		SelectedPart->Deselect();
	}

	if (Part)
	{
		SelectedPart = Part;
		SelectedPart->Select();
	}

}

void ABTScenarioManagerActor::SpawnHolograms(ABTEnginePart* Part)
{
	UStaticMeshComponent* HoloStaticMeshComponent = NewObject<UStaticMeshComponent>(Part);
	HoloStaticMeshComponent->SetStaticMesh(Part->EnginePartMesh->GetStaticMesh());
	HoloStaticMeshComponent->RegisterComponent();

	for (size_t i = 0; i < HoloStaticMeshComponent->GetStaticMesh()->GetStaticMaterials().Num(); i++)
	{
		HoloStaticMeshComponent->SetMaterial(i, HoloMaterial);
	}

	HoloStaticMeshComponent->SetCollisionProfileName("NoCollision");

	bool sc = HoloStaticMeshComponent->AttachToComponent(MainEngine->GetRootComponent(), FAttachmentTransformRules::SnapToTargetIncludingScale, Part->SnappableComponent->SuperActorSocket);

	HoloMeshes.Add(Part->SnappableComponent->SuperActorSocket,HoloStaticMeshComponent);
}

void ABTScenarioManagerActor::HideHolograms()
{
	for (auto Mesh : HoloMeshes)
	{
		Mesh.Value->SetHiddenInGame(true);
	}
}

void ABTScenarioManagerActor::ShowHolograms()
{
	for (auto Mesh : HoloMeshes)
	{
		Mesh.Value->SetHiddenInGame(false);
	}
}

void ABTScenarioManagerActor::OnPartGrabbed(ABTEnginePart* Part)
{
	//SelectPart(Part);
}

void ABTScenarioManagerActor::OnPartReleased(ABTEnginePart* Part)
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString::Printf(TEXT("OnPartReleased")));

}

