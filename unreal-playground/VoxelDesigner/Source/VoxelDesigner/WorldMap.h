// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "VoxelElement.h"
#include "GameFramework/Actor.h"
#include "WorldMap.generated.h"


#define IDX(i,j,k) ( (k*i*j)+ (i*j) + i )

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

	UFUNCTION(BlueprintCallable, meta = (FriendlyName = "Update Scale", CompactNodeTitle = "Update Scale", Keywords = "Update Relative 3D Scale"), Category = Game)
		void ClearMap();

	void DeployVoxel(FHitResult HitResult);


protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = WorldSetting)
	TArray<AVoxelElement*> WorldData;

	AVoxelElement** WorldArrayData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = VoxelEditorSettings)
	uint32 WorldHeight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = VoxelEditorSettings)
	uint32 WorldWidth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = VoxelEditorSettings)
	uint32 WorldDepth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = VoxelEditorSettings)
	uint32 TileSize;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = VoxelEditorSettings)
	class USceneComponent* MapSceneComponent;


	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = VoxelEditorSettings)
	class UStaticMeshComponent * GroundMeshComponenet;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = VoxelEditorSettings)
	class UInstancedStaticMeshComponent* WorldVoxelMeshes;


	UStaticMesh * CubeStaticMesh;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Voxel Editor Settings")
	TSubclassOf< class AVoxelElement> VoxelElement;



};
