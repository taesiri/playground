// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "WorldMap.h"
#include "GameFramework/Actor.h"
#include "VoxelEditor.generated.h"


UENUM(BlueprintType)
enum class  EditorStates : uint8
{
	deployVoxel  UMETA(DisplayName = "Deploy"),
	rePaintVoxel UMETA(DisplayName = "Painter")
};



UCLASS()
class VOXELDESIGNER_API AVoxelEditor : public AActor
{
	GENERATED_BODY()
	
private:
	void DeployCommand(const ETouchIndex::Type FingerIndex, const FVector Location);
	void RePaintCommand(const ETouchIndex::Type FingerIndex, const FVector Location);

public:	
	// Sets default values for this actor's properties
	AVoxelEditor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Voxel Editor Settings")
	bool DisplayDebugInformation = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Voxel Editor Settings")
	AWorldMap* MapInstance;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Voxel Editor Settings")
	UMaterialInstance* selectedMat;



	UFUNCTION(BlueprintCallable, meta = (FriendlyName = "SwitchEditorState", CompactNodeTitle = "Switch State", Keywords = "Switch,Editor,State"), Category = Game)
	void SwitchEditorState(EditorStates newState);

protected:

	void BeginTouch(const ETouchIndex::Type FingerIndex, const FVector Location);
	void EndTouch(const ETouchIndex::Type FingerIndex, const FVector Location);
	void TouchUpdate(const ETouchIndex::Type FingerIndex, const FVector Location);


	bool EnableTouchscreenMovement(UInputComponent* InputComponent);



	EditorStates CurrentEditorState;
};
