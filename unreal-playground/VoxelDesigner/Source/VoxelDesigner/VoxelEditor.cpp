// Fill out your copyright notice in the Description page of Project Settings.

#include "VoxelDesigner.h"
#include "VoxelEditor.h"
#include "VoxelElement.h"


// Sets default values
AVoxelEditor::AVoxelEditor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	

}

// Called when the game starts or when spawned
void AVoxelEditor::BeginPlay()
{
	Super::BeginPlay();

	EnableInput(GetWorld()->GetFirstPlayerController());

	EnableTouchscreenMovement(InputComponent);
	
}

// Called every frame
void AVoxelEditor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}


bool AVoxelEditor::EnableTouchscreenMovement(UInputComponent* InputComponent)
{

	bool bResult = false;
	if (FPlatformMisc::GetUseVirtualJoysticks() || GetDefault<UInputSettings>()->bUseMouseForTouch){


		InputComponent->BindTouch(EInputEvent::IE_Pressed, this, &AVoxelEditor::BeginTouch);
		InputComponent->BindTouch(EInputEvent::IE_Released , this, &AVoxelEditor::EndTouch);
		InputComponent->BindTouch(EInputEvent::IE_Repeat, this, &AVoxelEditor::TouchUpdate);

		bResult = true;
	}

	return bResult;

}

void AVoxelEditor::BeginTouch(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Blue, TEXT("Touch Begin event"));


	FHitResult HitResult;
	GetWorld()->GetFirstPlayerController()->GetHitResultUnderFingerByChannel(FingerIndex, UEngineTypes::ConvertToTraceType(ECC_Visibility), true, HitResult);


	if (VoxelElement != NULL)  
	{

		const FRotator SpawnRotation = FRotator();
		const FVector SpawnLocation = FVector(((int)HitResult.Location.X / 100)* 100.0f, ((int)HitResult.Location.Y / 100)* 100.0f, ((int)HitResult.Location.Z / 100)* 100.0f);
		FActorSpawnParameters SpawnParams;

		UWorld* const World = GetWorld();

		if (World != NULL) 
		{



			World->SpawnActor<AVoxelElement>(VoxelElement, SpawnLocation, SpawnRotation, SpawnParams);

		}
	}

	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Blue, HitResult.Location.ToString());


}
void AVoxelEditor::EndTouch(const ETouchIndex::Type FingerIndex, const FVector Location) 
{
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Blue, TEXT("Touch End event"));

}
void AVoxelEditor::TouchUpdate(const ETouchIndex::Type FingerIndex, const FVector Location) 
{
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Blue, TEXT("Touch Update event"));
}
