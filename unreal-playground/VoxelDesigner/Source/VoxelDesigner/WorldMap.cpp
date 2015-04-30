// Fill out your copyright notice in the Description page of Project Settings.

#include "VoxelDesigner.h"
#include "WorldMap.h"
#include "VoxelElement.h"



// Sets default values
AWorldMap::AWorldMap()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	WorldHeight = 32;
	WorldWidth = 32;
	WorldDepth = 32;

	MapSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Main Scene Componenet"));
	RootComponent = MapSceneComponent;


	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticCubeMesh(TEXT("StaticMesh'/Game/Shapes/Shape_Cube'"));
	GroundMesh = StaticCubeMesh.Object;

	GroundMeshComponenet = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ground Mesh"));


	GroundMeshComponenet->SetRelativeScale3D(FVector(WorldHeight, WorldWidth, 1));
	GroundMeshComponenet->RelativeLocation =FVector(0, 0, 0);


	GroundMeshComponenet->SetStaticMesh(GroundMesh);
	GroundMeshComponenet->AttachParent= MapSceneComponent;
	

	

}

// Called when the game starts or when spawned
void AWorldMap::BeginPlay()
{
	Super::BeginPlay();

	GroundMeshComponenet->SetRelativeScale3D(FVector(WorldHeight, WorldWidth, 1));
	
}

// Called every frame
void AWorldMap::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AWorldMap::UpdateScale(FVector newScale)
{
	GroundMeshComponenet->SetRelativeScale3D(newScale);
}
