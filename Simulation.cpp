#include "Simulation.h"


PSimulation createSimulation(int n, int m, int nRobots) {
	PSimulation toret = (PSimulation)malloc(sizeof(Simulation));
	if (toret != NULL) {
		toret->n = n;
		toret->m = m;
		toret->nRobots = nRobots;
		toret->TickCount = 0;
		return toret;
	}
	else return NULL;
}




/*

void Create_dirty_floor(int col, int fil, float size_floor); //coloca todos los pisos sucios. recibe columna y fila.
al_flip_display(); //actualiza lo que ves en pantalla
al_rest(1.0); //delay 1.0

void Clean_floor(int x, int y, float); //
void Set_robot(float x, float y, float angle, allegro_t * allegro_p, float size_floor);




*/
