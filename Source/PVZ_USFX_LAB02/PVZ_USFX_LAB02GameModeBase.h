// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PVZ_USFX_LAB02GameModeBase.generated.h"

/**
 *
 */
class AZombie;
class AZombieComun;
class APlant;
class APlanta_Ataque;
class ALanza_Guisantes;
class AZombieDeportista;

UCLASS()
class PVZ_USFX_LAB02_API APVZ_USFX_LAB02GameModeBase : public AGameModeBase
{
	GENERATED_BODY()


public:
	// Sets default values for this actor's properties
	APVZ_USFX_LAB02GameModeBase();



private:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override
	{
		Super::BeginPlay();

		// Definición de un objeto de tipo World
		UWorld* const World = GetWorld();

		//ASpawns* Spawn1 = GetWorld()->SpawnActor<ASpawns>(ASpawns::StaticClass(), FVector(0,0,0), FRotator::ZeroRotator);
		// 
		//AZombie* Zombie1 = GetWorld()->SpawnActor<AZombie>(AZombie::StaticClass(), FVector(400.0, 200.0, 100.0), FRotator::ZeroRotator);

		GetWorld()->GetTimerManager().SetTimer(MoveTimerHandle, this, &APVZ_USFX_LAB02GameModeBase::MoveOutOfLane, 5.0f, false);


		World->GetTimerManager().SetTimer(Temporizador, this, &APVZ_USFX_LAB02GameModeBase::Spawn, 2, true);

		//Aparición de los soles
		//ASol* Sol1 = GetWorld()->SpawnActor<ASol>(ASol::StaticClass(), FVector(-400,-50,160), FRotator::ZeroRotator);
		//ASol* Sol2 = GetWorld()->SpawnActor<ASol>(ASol::StaticClass(), FVector(-450, -50, 160), FRotator::ZeroRotator);

		//Definiendo la posición de los zombies
		FVector SpawnLocationZombie = FVector(-920.0f, 400.0f, 22.0f);

		// Genera 5 zombies
		////for (int i = 0; i < 7; i++) {
		////	// Define una posición temporal para el zombie en X
		////	SpawnLocationZombie.X += 100;
		////	// Aparicion de los zombies


		////	NuevoZombie = GetWorld()->SpawnActor<AZombieComun>(AZombieComun::StaticClass(), SpawnLocationZombie, FRotator::ZeroRotator);

		////	NuevoZombie->Velocidad = FMath::FRandRange(0.1, 0.1);

		////	Zombies.Add(NuevoZombie);

		////}



		// Esta parte es la del parcial donde se generan los zombies deportistas y se le cambio la velocidad del movimiento

		for (int i = 0; i < 1; i++) {
			// Define una posición temporal para el zombie en X
			SpawnLocationZombie.X += 100;
			// Aparicion de los zombies


			NuevoZombieDeportista = GetWorld()->SpawnActor<AZombieDeportista>(AZombieDeportista::StaticClass(), SpawnLocationZombie, FRotator::ZeroRotator);

			NuevoZombieDeportista->Velocidad = FMath::FRandRange(0.5, 0.5);

			Zombies.Add(NuevoZombieDeportista);
		}
		//Esta parte del codigo es para que el zombie se mueva a una posicion aleatoria cada cierto tiempo
		GetWorld()->GetTimerManager().SetTimer(MoveTimerHandle, this, &AZombieDeportista::MoveOutOfLane, 5.0f, false);




		//Definiendo la posición de las plantas
		FVector SpawnLocationPlant = FVector(-920.0f, -600.0f, 22.0f);
		FVector SpawnLocationPlantTemp = SpawnLocationPlant;

		// Genera 5 plantas
		for (int i = 0; i < 7; i++)
		{
			//Define una posicion temporal para la planta en X
			SpawnLocationPlantTemp.X += 100;



			for (int j = 0; j < 2; j++)
			{

				// Define una posición temporal para la planta en Y
				SpawnLocationPlantTemp.Y += 100;

				// Genera un nombre para la planta
				NombrePlanta = FString::Printf(TEXT("Planta %d_%d"), i + 1, j + 1); // Cambio en la generación del nombre

				// Crea una nueva instancia de APlant en el mundo
				NuevaPlantaGuisante = GetWorld()->SpawnActor<ALanza_Guisantes>(ALanza_Guisantes::StaticClass(), SpawnLocationPlantTemp, FRotator::ZeroRotator);

				// Asigna un valor aleatorio a la energía de la planta
				NuevaPlantaGuisante->energia = FMath::FRandRange(0.0, 10.0);

				// Muestra un mensaje en la consola
				//UE_LOG(LogTemp, Warning, TEXT("Energía de %s: %i"), *NombrePlanta, NuevaPlanta->energia);

				// Muestra un mensaje en la pantalla
				GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Energía de %s: %i"), *NombrePlanta, NuevaPlantaGuisante->energia));
				// Muestra un mensaje en el registro de errores
				UE_LOG(LogTemp, Warning, TEXT("Energía de %s: %i"), *NombrePlanta, NuevaPlantaGuisante->energia);

				// Agrega la planta al contenedor de plantas
				Plantas.Add(NombrePlanta, NuevaPlantaGuisante);


				Plantas2.Add(NuevaPlantaGuisante);


				// Coloca la planta en una posición diferente
				//NuevaPlanta->SetActorLocation(FVector(i * 100, 0, 0));


			}
			// Define una posición temporal para la planta en Y
			SpawnLocationPlantTemp.Y = SpawnLocationPlant.Y;

		}

		//FString Mensaje = FString::Printf(TEXT("Encontrada planta: %s"), *NombrePlanta);
		//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, Mensaje);


		//World->GetTimerManager().SetTimer(Temporizador, this, &APVZ_USFX_LAB02GameModeBase::aumentovelocidad, 1, true);

		World->GetTimerManager().SetTimer(Temporizador2, this, &APVZ_USFX_LAB02GameModeBase::MostrarEnergiaDePlantas, 1.f, true);


	}



	FTimerHandle MoveTimerHandle;
	


	

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FTimerHandle Temporizador;



	void Spawn();

	FVector contador;


	int contador2;


	FVector localizacion;


	// Declarar un vector de objetos
	TArray<AZombie*> Zombies;


	// Declarar un contenedor tipo TMap de objetos
	TMap<FString, APlant*> Plantas;

	// Declarar un vector de objetos

	TArray<APlant*> Plantas2;

	float TiempoTranscurrido;

	void aumentovelocidad();

	void MostrarEnergiaDePlantas();


	AZombieComun* NuevoZombie;
	AZombieDeportista* NuevoZombieDeportista;


	FTimerHandle Temporizador2;

	FString NombrePlanta;

	ALanza_Guisantes* NuevaPlantaGuisante;
	


	int FilaActual;
	int ColumnaActual;



};

