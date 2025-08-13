// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/CapsuleComponent.h"
#include "PaperSpriteComponent.h"
#include "MyGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundBase.h"

#include "Obstacle.generated.h"

UCLASS()
class CARRACING_API AObstacle : public AActor
{
	GENERATED_BODY()
	
public:	

	AObstacle();

	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UCapsuleComponent* CapsuleComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UPaperSpriteComponent* ObstacleSprite;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USoundBase* HitSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsFinishLine = false;

	AMyGameMode* MyGameMode;



	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
