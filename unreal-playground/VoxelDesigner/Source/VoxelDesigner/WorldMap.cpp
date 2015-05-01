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
	TileSize = 100;

	MapSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Main Scene Componenet"));
	WorldVoxelMeshes = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("Instance Static Mesh Component"));
	RootComponent = MapSceneComponent;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticCubeMesh(TEXT("StaticMesh'/Game/Shapes/Shape_Cube'"));
	CubeStaticMesh = StaticCubeMesh.Object;

	GroundMeshComponenet = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ground Mesh"));

	GroundMeshComponenet->SetRelativeScale3D(FVector(WorldHeight, WorldWidth, 0.1));
	GroundMeshComponenet->RelativeLocation = FVector(WorldHeight / 2 * 100, WorldWidth / 2 * 100, -0.1);

	GroundMeshComponenet->SetStaticMesh(CubeStaticMesh);
	GroundMeshComponenet->AttachParent= MapSceneComponent;
	
	WorldVoxelMeshes->SetStaticMesh(CubeStaticMesh);
	WorldVoxelMeshes->AttachParent = MapSceneComponent;

	//WorldArrayData = new AVoxelElement*[100];
}

// Called when the game starts or when spawned
void AWorldMap::BeginPlay()
{
	Super::BeginPlay();

	GroundMeshComponenet->SetRelativeScale3D(FVector(WorldHeight, WorldWidth, 0.1));
	GroundMeshComponenet->RelativeLocation = FVector(WorldHeight / 2 * 100, WorldWidth / 2 * 100, -0.1);
	
}

// Called every frame
void AWorldMap::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}

void AWorldMap::UpdateScale(FVector newScale)
{
	WorldHeight = newScale.X;
	WorldWidth = newScale.Y;
	WorldDepth = newScale.Z;
	//WorldArrayData = new AVoxelElement*[(int)FVector::DotProduct(newScale, FVector(1, 1, 1))];

	GroundMeshComponenet->SetRelativeScale3D(FVector(WorldHeight, WorldWidth, 0.1));
	GroundMeshComponenet->RelativeLocation = FVector(WorldHeight / 2 * 100, WorldWidth / 2 * 100, -0.1);

	//GetWorld()->GetFirstPlayerController()->GetPawn()->SetActorLocation(FVector(WorldHeight / 2 * 100, WorldWidth / 2 * 100, 150));
}

void AWorldMap::DeployVoxel(FHitResult HitResult)
{

	const FVector eulerAngles = FVector(0, 0, 0);
	const FRotator SpawnRotation = FRotator::MakeFromEuler(eulerAngles);
	const FVector SpawnLocation = FVector((int)(HitResult.Location.X / 100)* 100.0f + TileSize / 2, (int)(HitResult.Location.Y / 100)* 100.0f + TileSize / 2, (int)(HitResult.Location.Z / 100)* 100.0f);
	FActorSpawnParameters SpawnParams;


	if (HitResult.IsValidBlockingHit())
	{
		UWorld* const World = GetWorld();

		if (World != NULL)
		{
			AVoxelElement* possibleVoxelElement = Cast<AVoxelElement>(HitResult.Actor.Get());

			if (possibleVoxelElement != NULL)
			{
				FVector delta = (HitResult.Location / 100) - possibleVoxelElement->VoxelIndex;
				delta.Normalize();

				FVector PropperSpawnLocation = HitResult.Location + (delta);
				PropperSpawnLocation = FVector((int)(PropperSpawnLocation.X / 100)* 100.0f + TileSize / 2, (int)(PropperSpawnLocation.Y / 100)* 100.0f + TileSize / 2, (int)(PropperSpawnLocation.Z / 100)* 100.0f);

				auto myElement = World->SpawnActor<AVoxelElement>(VoxelElement, PropperSpawnLocation, SpawnRotation, SpawnParams);
				myElement->VoxelIndex = PropperSpawnLocation / 100;

				WorldData.Add(myElement);
			}
			else
			{
				auto myElement = World->SpawnActor<AVoxelElement>(VoxelElement, SpawnLocation, SpawnRotation, SpawnParams);
				myElement->VoxelIndex = SpawnLocation / 100;

				WorldData.Add(myElement);
			}
		}
	}

}

void AWorldMap::RepaintVoxel(FHitResult HitResult, UMaterialInterface* selectedMat)
{
	const FVector eulerAngles = FVector(0, 0, 0);
	const FRotator SpawnRotation = FRotator::MakeFromEuler(eulerAngles);
	const FVector SpawnLocation = FVector((int)(HitResult.Location.X / 100)* 100.0f + TileSize / 2, (int)(HitResult.Location.Y / 100)* 100.0f + TileSize / 2, (int)(HitResult.Location.Z / 100)* 100.0f);
	FActorSpawnParameters SpawnParams;


	if (HitResult.IsValidBlockingHit())
	{
		UWorld* const World = GetWorld();

		if (World != NULL)
		{
			AVoxelElement* possibleVoxelElement = Cast<AVoxelElement>(HitResult.Actor.Get());

			if (possibleVoxelElement != NULL)
			{
				possibleVoxelElement->VoxelMeshComponent->SetMaterial(0, selectedMat);
			}
			
		}
	}

}

void AWorldMap::ClearMap()
{
	for (AVoxelElement* voxel : WorldData)
	{
		voxel->Destroy(true);
	}

	WorldData.RemoveAllSwap([](AVoxelElement* val) {return true; });
}