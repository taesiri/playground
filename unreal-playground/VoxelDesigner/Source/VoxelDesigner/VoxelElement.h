// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "VoxelElement.generated.h"

UCLASS()
class VOXELDESIGNER_API AVoxelElement : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVoxelElement();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	UPROPERTY(VisibleDefaultsOnly, Category = VoxelElement)
	class UStaticMeshComponent* VoxelMeshComponent;

	UPROPERTY(VisibleDefaultsOnly, Category = VoxelElement)
	FVector VoxelIndex;

	
};
