// Fill out your copyright notice in the Description page of Project Settings.


#include "MaterialInitiatorSubsytem.h"
#include "Kismet/GameplayStatics.h"


void UMaterialInitiatorSubsytem::OnWorldBeginPlay(UWorld& InWorld)
{
	Super::OnWorldBeginPlay(InWorld);
	if (!GetWorld()) return;
	UE_LOG(LogTemp, Log, TEXT("WorldSubsystem is running!"));
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AActor::StaticClass(), FoundActors);
	UMaterialInterface* PrimaryMaterial = LoadObject<UMaterialInterface>(nullptr, TEXT("/Script/Engine.Material'/Game/Materials/PrimaryMaterial.PrimaryMaterial'"));
	UMaterialInterface* OutlineMaterial = LoadObject<UMaterialInterface>(nullptr, TEXT("/Script/Engine.Material'/Game/Materials/SecondaryOutlineMaterial.SecondaryOutlineMaterial'"));
	
	if (!IsValid(PrimaryMaterial) || !IsValid(OutlineMaterial)) {
		UE_LOG(LogTemp, Warning, TEXT("Primary or Outline Material is invalid"));
		return;
	}


	for (AActor* Actor : FoundActors) {

		TArray<UStaticMeshComponent*> FoundMeshComponents;
		Actor->GetComponents<UStaticMeshComponent>(FoundMeshComponents);

		for (UStaticMeshComponent* MeshComponent : FoundMeshComponents) {
			if (!IsValid(MeshComponent)) continue;
			MeshComponent->SetMaterial(0, PrimaryMaterial);
			MeshComponent->SetOverlayMaterial(OutlineMaterial);
			
		}

	}

}
//UStaticMeshComponent* DuplicateMeshComponent = NewObject<UStaticMeshComponent>( Actor, TEXT(" Duplicate") );
			//DuplicateMeshComponent->SetSimulatePhysics(false);
			//DuplicateMeshComponent->SetStaticMesh(MeshComponent->GetStaticMesh());
			////DuplicateMeshComponent->Scale
			////DuplicateMeshComponent->SetWorldScale3D(FVector(50f, 50f, 50f) );
			//DuplicateMeshComponent->AttachToComponent(MeshComponent, FAttachmentTransformRules::SnapToTargetIncludingScale);
			////MeshComponent->SetMater
			//DuplicateMeshComponent->RegisterComponent();

			//static ConstructorHelpers::FObjectFinder<UMaterialInterface> Material(TEXT("Material'/Game/Materials/YourMaterialName.YourMaterialName'"));
