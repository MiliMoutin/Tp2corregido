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
