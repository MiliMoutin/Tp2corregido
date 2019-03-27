#include<iostream>
#include <allegro5/allegro.h> 
#include <allegro5/allegro_image.h> 
#include <allegro5/allegro_audio.h> // NO OLVIDAR AGREGAR EN EL LINKER DEL PROYECTO
#include <allegro5/allegro_acodec.h> // NO OLVIDAR AGREGAR EN EL LINKER DEL PROYECTO
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <cstdio>
#include <cstdlib>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>

#include "tp2_allegro.h"
#include "Floor.h"
#include "Position.h"
#include "Robot.h"
#include "Simulation.h"
#include "ParseCmdLine.h"

using namespace std;
int parseCallback(const char *,const char *, void *);	 //Declaracion de la funcion de callback



#define FILAS	15
#define COLUMNAS	10
#define MAX_ARGS 4



int main(int argc, const char *argv[])
{
	allegro_t allegro_data;						//Estructura para allegro
	allegro_t * allegro_p = &allegro_data;

	PSimulation Simulation_data;

	srand(time(NULL));

	//parsecmdline
	enum opciones { fil, col, robots, mode };

	//MAX_ARGS =4 -> UserData guarda Fila, Columna, Nrobots
	int		UserData[MAX_ARGS];		//Arreglo de int donde se guardan las opciones
	int		parseCmdLine_Return;		//Variable que almacena el retorno de parseCmdLine

	if (parseCmdLine(argc, argv, parseCallback, &UserData) == -1)	//Invoco al parse y almaceno su retorno
	{
		printf("Ingreso mal los parametros fila, col, robots, modo");
		return 0;
	}

	printf("fil %d\n", UserData[fil]);
	printf("col %d\n", UserData[col]);
	printf("robots %d\n", UserData[robots]);
	printf("mode %d\n", UserData[mode]);
	//while (1);



	if (init_allegro(allegro_p)) //Inicializo allegro
	{
		return 0; //si fallas devuelve 0
	}
	/*
	double arr[] = { 100,92,88,80,75,70,60,55,40,30,29,28,27,26,10 };
	al_show_graph(arr, 20);
	al_flip_display();
	while (1);*/


	Simulation_data=createSimulation(COLUMNAS, FILAS, 10);
	//Mode1(Simulation_data, allegro_p, 1);
	Mode2(Simulation_data, allegro_p);
	al_flip_display();
	al_rest(10.0);

	al_destroy_display(allegro_data.display); //destruyo display display

	return 0;
}





int parseCallback(const char *key,const char *value, void *UserData)
{
	if (key == NULL)
	{
		//Guardar value en UserData, ya que lo que ingreso
		//es un parámetro
		return 1;	//Interpretacion correcta
	}
	if (key != NULL && value != NULL && (*value) != '-')
	{
		printf("key %c\n", *key);
		switch (*key)
		{
			case 'f':	if ((int)atoi(value) > 70 || (int)atoi(value) < 0)
						{
							return 0;
						}
						else
						{
							*((int*)UserData) = (int)atoi(value);
						}
						break;

			case 'c':	if ((int)atoi(value) > 100 || (int)atoi(value) < 0)
						{
							return 0;
						}
						else
						{
							*(((int*)UserData)+1) = (int)atoi(value);
						}
						break;

			case 'r':	if ((int)atoi(value) < 0)
					{
						return 0;
					}
					else
					{
						*(((int*)UserData) + 2) = (int)atoi(value);
					}
					break;

			case 'm':	if ((int)atoi(value) == 1)
						{
							*(((int*)UserData) + 3) = (int)atoi(value);
						}else if ((int)atoi(value) == 2)
							{
								*(((int*)UserData) + 3) = (int)atoi(value);
							}
							else
								{	return 0;
								}
							break;
			default:	return 0;
		
		}

		return 1;
	}


	if (key != NULL && (value == NULL || (*value) == '-'))
	{
		printf("Error key: %s\n", key);
		return 0; //si tengo una clave sin valor, devuelvo 0
	}
	return 0;
}

