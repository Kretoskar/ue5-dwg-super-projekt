// Fill out your copyright notice in the Description page of Project Settings.


#include "TestActor.h"

#include "Kismet/KismetMathLibrary.h"

ATestActor::ATestActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ATestActor::BeginPlay()
{
	Super::BeginPlay();

	FMatrix MA = A->GetTransform().ToMatrixNoScale();
	FMatrix MB = B->GetTransform().ToMatrixNoScale();
	FMatrix MT = T->GetTransform().ToMatrixNoScale();
	
	FMatrix Mres = MT * MA.Inverse() * MB;
	
	TargetTransform = FTransform(Mres);
}

void ATestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	T->SetActorTransform(UKismetMathLibrary::TLerp(T->GetTransform(), TargetTransform, 0.01f));
}

