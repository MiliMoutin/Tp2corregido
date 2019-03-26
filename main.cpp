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
int parseCallback(char *, char *, void *);	 //Declaracion de la funcion de callback



#define FILAS	5
#define COLUMNAS	5



int main(int argc, char **argv)
{
	allegro_t allegro_data;						//Estructura para allegro
	allegro_t * allegro_p = &allegro_data;

	PSimulation Simulation_data;

	srand(time(NULL));

	//parsecmdline
	
	//MAX_ARGS =3 -> UserData guarda Fila, Columna, Nrobots
	/*int		*UserData[MAX_ARGS];		//Arreglo de strings donde se guardan los parametros
	int		parseCmdLine_Return;		//Variable que almacena el retorno de parseCmdLine


	parseCmdLine_Return = parseCmdLine(argc, argv, parseCallback, UserData);	//Invoco al parse y almaceno su retorno

	switch (parseCmdLine_Return)																//Si hubo errores durante la ejecucion																						//de parseCmdLine se muestra en pantalla
	{																							//su origen
	case EMPTY_ARGS: printf("No ha ingresado ningun argumento en linea de comandos\n");
		break;

	case OVERFLOW_ARGS: printf("La cantidad de argumentos excede el maximo de %d\n", MAX_ARGS);
		break;

	case SINTAX_ERROR: printf("Su ingreso ha sido incorrecto (Formato: -clave valor // parametro)\n");
		break;
	
	}*/

	


	if (init_allegro(allegro_p)) //Inicializo allegro
	{
		return 0; //si fallas devuelve 0
	}


	Simulation_data=createSimulation(COLUMNAS, FILAS, 10);
	Mode1(Simulation_data, allegro_p, 1);

	al_destroy_display(allegro_data.display); //destruyo display display

	return 0;
}





int parseCallback(char *key, char *value, void *UserData)
{
	if (key == NULL)
	{
		//Guardar value en UserData, ya que lo que ingreso
		//es un parámetro
		return 1;	//Interpretacion correcta
	}
	if (key != NULL && value != NULL && (*value) != '-')
	{
		switch(*(key+1))
		{
		case 'f':	if((int)atoi(value)>70 || (int)atoi(value)<0)
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
						*((int*)UserData+1) = (int)atoi(value);
					}
					break;

		case 'r':	if ((int)atoi(value) < 0)
					{
						return 0;
					}
					else
					{
						*((int*)UserData + 2) = (int)atoi(value);
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

