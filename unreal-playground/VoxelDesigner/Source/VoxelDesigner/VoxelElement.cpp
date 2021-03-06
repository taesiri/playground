// Fill out your copyright notice in the Description page of Project Settings.

#include "VoxelDesigner.h"
#include "VoxelElement.h"


// Sets default values
AVoxelElement::AVoxelElement()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VoxelMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Voxel Mesh"));

	RootComponent = VoxelMeshComponent;


}

// Called when the game starts or when spawned
void AVoxelElement::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVoxelElement::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}


