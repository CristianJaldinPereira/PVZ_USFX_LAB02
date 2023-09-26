// Fill out your copyright notice in the Description page of Project Settings.


#include "ZombieDeportista.h"


AZombieDeportista::AZombieDeportista()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ZombieMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_WideCapsule.Shape_WideCapsule'"));
	energia = 250;
	
}


// Con esta parte del c�digo, el zombie deportista se mover� fuera del carril actual en rango que se determino
void AZombieDeportista::MoveOutOfLane()
{
	if (!bHasMoved)
	{
		FVector CurrentLocation = GetActorLocation();

		// Genera coordenadas X e Y aleatorias
		float RandomX = FMath::FRandRange(580.0f, -309.4f); // Ajusta el rango seg�n tu escenario
		float RandomY = FMath::FRandRange(-820.0f, -230.0f); // Ajusta el rango seg�n tu escenario

		// Calcula la nueva ubicaci�n fuera del carril actual
		FVector NewLocation = CurrentLocation + FVector(RandomX, RandomY, 0.0f);

		// Establece la nueva ubicaci�n del actor
		SetActorLocation(NewLocation);

		// Establece la variable de estado como verdadera para que no se mueva nuevamente
		bHasMoved = true;
	}
}




	
