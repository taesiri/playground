// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "VoxelElement.h"
#include "GameFramework/Actor.h"
#include "WorldMap.generated.h"

UCLASS()
class VOXELDESIGNER_API AWorldMap : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWorldMap();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	UFUNCTION(BlueprintCallable, meta = (FriendlyName = "Update Scale", CompactNodeTitle = "Update Scale", Keywords = "Update Relative 3D Scale"), Category = Game)
	void UpdateScale(FVector newScale);



protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = WorldSetting)
	TArray<AVoxelElement*> WorldData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = VoxelEditorSettings)
		uint32 WorldHeight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = VoxelEditorSettings)
		uint32 WorldWidth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = VoxelEditorSettings)
		uint32 WorldDepth;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = VoxelEditorSettings)
	class USceneComponent* MapSceneComponent;


	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = VoxelEditorSettings)
	class UStaticMeshComponent * GroundMeshComponenet;


	UStaticMesh * GroundMesh;


};