// Fill out your copyright notice in the Description page of Project Settings.


#include "BTXRFramework/Pawn/BTXRPawn.h"
#include "Camera/CameraComponent.h"
#include "Components/ChildActorComponent.h"
#include "BTXRFramework/Grab/BTGrabToolComponent.h"
//#include "BTXRFramework/Grab/BTGrabToolHandComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"

// Sets default values
ABTXRPawn::ABTXRPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	XRDefaultSceneComponent = CreateDefaultSubobject<USceneComponent>("XRDefaultSceneComponent");
	RootComponent = XRDefaultSceneComponent;


	MotionControllerRight = CreateDefaultSubobject<UMotionControllerComponent>("MotionControllerRight");
	MotionControllerRight->SetupAttachment(RootComponent);
	MotionControllerRight->MotionSource = FName("Right");

	MotionControllerLeft = CreateDefaultSubobject<UMotionControllerComponent>("MotionControllerLeft");
	MotionControllerLeft->SetupAttachment(RootComponent);
	MotionControllerLeft->MotionSource = FName("Left");


	CameraComponent = CreateDefaultSubobject<UCameraComponent>("Camera");
	CameraComponent->SetupAttachment(RootComponent);

	GrabTool = CreateDefaultSubobject<UBTGrabToolComponent>("GrabToolX");
	GrabTool->SetupAttachment(MotionControllerRight);

	//AnchorTool = CreateDefaultSubobject<UBTAnchorTool>("AnchorTool");
	//AnchorTool->SetupAttachment(MotionControllerRight);

	ToolModelActor = CreateDefaultSubobject<UChildActorComponent>("ToolModelActor");
	ToolModelActor->SetupAttachment(MotionControllerRight);

	//TODO passthrough will be added as component
}

// Called when the game starts or when spawned
void ABTXRPawn::BeginPlay()
{
	Super::BeginPlay();
	

	UHeadMountedDisplayFunctionLibrary::SetTrackingOrigin(EHMDTrackingOrigin::Floor);


	//AnchorTool->OnComponentActivated.AddDynamic(this, &ABTXRPawn::OnAnchorToolActivated);
	//GrabTool->OnComponentActivated.AddDynamic(this, &ABTXRPawn::OnGrabToolActivated);
}

// Called every frame
void ABTXRPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABTXRPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABTXRPawn::OnAnchorToolActivated(UActorComponent* Component, bool bReset)
{
}

void ABTXRPawn::OnGrabToolActivated(UActorComponent* Component, bool bReset)
{
}

