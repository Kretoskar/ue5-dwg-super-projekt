// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestActor.generated.h"

UCLASS()
class DWG_API ATestActor : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	AActor* A;

	UPROPERTY(EditAnywhere)
	AActor* B;

	UPROPERTY(EditAnywhere)
	AActor* T;
	
public:	
	ATestActor();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	FTransform TargetTransform;
};
