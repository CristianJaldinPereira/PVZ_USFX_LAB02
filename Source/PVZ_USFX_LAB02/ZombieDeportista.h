// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Zombie.h"
#include "ZombieDeportista.generated.h"

/**
 * 
 */
UCLASS()
class PVZ_USFX_LAB02_API AZombieDeportista : public AZombie
{
	GENERATED_BODY()
	
	public :
		AZombieDeportista();

		// bHasMoved tiene la funcion para que se active si el zombie se mueva o no 
		bool bHasMoved = false;

		
		void MoveOutOfLane();






};
