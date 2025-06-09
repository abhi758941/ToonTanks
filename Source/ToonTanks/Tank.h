// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()
	

	public:
	ATank();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	public:
		
	private:
	UPROPERTY(VisibleAnywhere , BlueprintReadWrite , Category = "Model elements" , meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere , BlueprintReadWrite , Category = "Model elements" , meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* Camera;
	UPROPERTY(BlueprintReadWrite , meta = (AllowPrivateAccess = "true"))
		FVector DeltaLocation;
	UPROPERTY(BlueprintReadWrite , meta = (AllowPrivateAccess = "true"))
		FRotator DeltaRotation;
	UPROPERTY(EditAnywhere , BlueprintReadWrite , meta = (AllowPrivateAccess = "true"))
		float MovementSpeed = 50;
	UPROPERTY(EditAnywhere , BlueprintReadWrite , meta = (AllowPrivateAccess = "true"))
		float RotationSpeed = 50;
	
	
	UFUNCTION(BlueprintCallable)
		void Move(float Value);
	UFUNCTION(BlueprintCallable)
		void Turn(float Value);
};
