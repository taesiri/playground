// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "VoxelEditor.generated.h"

UCLASS()
class VOXELDESIGNER_API AVoxelEditor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVoxelEditor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Voxel Editor Settings")
	TSubclassOf< class AVoxelElement> VoxelElement;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Voxel Editor Settings")
	bool DisplayDebugInformation = false;
	
protected:

	void BeginTouch(const ETouchIndex::Type FingerIndex, const FVector Location);
	void EndTouch(const ETouchIndex::Type FingerIndex, const FVector Location);
	void TouchUpdate(const ETouchIndex::Type FingerIndex, const FVector Location);


	bool EnableTouchscreenMovement(UInputComponent* InputComponent);
};
