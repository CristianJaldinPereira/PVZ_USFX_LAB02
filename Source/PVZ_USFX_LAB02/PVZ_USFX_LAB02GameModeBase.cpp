// Copyright Epic Games, Inc. All Rights Reserved.


#include "PVZ_USFX_LAB02GameModeBase.h"
#include "Spawns.h"
#include "Zombie.h"
#include "Plant.h"
//#include "Sol.h"
#include "Math/UnrealMathUtility.h"
#include "Engine/Engine.h"
#include "TimerManager.h"


#include "Jugador.h"
#include "Controlador.h"
#include "HUDPlantas.h"


#include "Planta_Ataque.h"
#include "Lanza_Guisantes.h"

#include "ZombieComun.h"
#include "ZombieCono.h"
#include "ZombieCubo.h"
#include "ZombieDeportista.h"

APVZ_USFX_LAB02GameModeBase::APVZ_USFX_LAB02GameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;

	//Definiendo el Pawn o Peon
	DefaultPawnClass = AJugador::StaticClass();
	//Definiendo el Controlador
	PlayerControllerClass = AControlador::StaticClass();
	//Definiendo el HUD
	HUDClass = AHUDPlantas::StaticClass();



	contador = FVector(0, 0, 0);
	localizacion = FVector(400.0, 200.0, 100.0);
	contador2 = 0;

	TiempoTranscurrido = 0.0f;


	FilaActual = 1;
	ColumnaActual = 1;

}


{
	Super::Tick(DeltaTime);

	TiempoTranscurrido += DeltaTime;

	//if (TiempoTranscurrido > 2.0f) {
	//	// Iterar sobre el vector de objetos
	//	for (int i = 0; i < Zombies.Num(); i++) {
	//		Zombies[i]->Velocidad = FMath::FRand() * 2.0f;

	//		//Zombies[i]->MovementSpeed += i * 1.0f;
	//	}
	//	TiempoTranscurrido = 0.0f;
	// 
	//}

	//if (TiempoTranscurrido > 5.0f) {
	//	// Iterar sobre el vector de objetos
	//	for (int i = 0; i < Plantas2.Num(); i++) {
	//		int vtemp= Plantas2[i]->energia;
	//		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Energía de %s: %i"), *NombrePlanta, vtemp));

	//		
	//	}
	//	TiempoTranscurrido = 0.0f;
	//}


}

void APVZ_USFX_LAB02GameModeBase::Spawn()
{
	contador2++;

	contador = contador + FVector(100, 0, 0);
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Este es un mensaje")));


	AZombie* Zombie1 = GetWorld()->SpawnActor<AZombie>(AZombie::StaticClass(), localizacion, FRotator::ZeroRotator);



	localizacion.X = localizacion.X + contador2 * 100;
	localizacion.Y = localizacion.Y + contador2 * 100;
	//localizacion = localizacion + contador;




}

void APVZ_USFX_LAB02GameModeBase::aumentovelocidad()
{

	for (int i = 0; i < Zombies.Num(); i++)
	{
		Zombies[i]->Velocidad = +FMath::FRandRange(0, 0.2);
	}

}

void APVZ_USFX_LAB02GameModeBase::MostrarEnergiaDePlantas()
{

	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Este es un mensaje")));

	NombrePlanta = FString::Printf(TEXT("Planta %d_%d"), FilaActual, ColumnaActual);

	APlant* Planta = Plantas.FindRef(NombrePlanta);

	if (Planta)
	{
		FString Mensaje = FString::Printf(TEXT("%s: Energia %i"), *NombrePlanta, Planta->energia);

		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, Mensaje);

		UE_LOG(LogTemp, Warning, TEXT("%s"), *Mensaje);

	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("No se encontró la planta")));
	}

	ColumnaActual++;

	if (ColumnaActual > 2) // Ajusta este valor al número total de columnas
	{
		ColumnaActual = 1;
		FilaActual++;

		if (FilaActual > 5) // Ajusta este valor al número total de filas
		{
			FilaActual = 1;
		}
	}

}







