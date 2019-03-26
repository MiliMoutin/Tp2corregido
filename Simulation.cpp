#include "Simulation.h"
#define MAX_ANGLE 360

PSimulation createSimulation(int n, int m, int nRobots) {
	PSimulation toret = (PSimulation)malloc(sizeof(Simulation));
	if (toret != NULL) {
		toret->n = n;
		toret->m = m;
		toret->f = createFloor(m, n);
		toret->nRobots = nRobots;
		toret->TickCount = 0;
		return toret;
	}
	else return NULL;
}

int Mode1(PSimulation p, allegro_t * allegro_p) {
	float size_floor_h = SCREEN_H / p->m;
	float size_floor_w = SCREEN_W / p->n;
	float size_floor = size_floor_h > size_floor_w ? size_floor_w : size_floor_h;   //Determino tamaño de baldosa para que se ajuste a la ventana
	Create_dirty_floor(p->n, p->m, size_floor);

	p->Robots = (PRobot*) malloc(sizeof(PRobot)*(p->nRobots)); /*inicializo el vector de robots*/
	for (int i = 0; i < p->nRobots; i++) {
		p->Robots[i] = createRobot();
		setLocation(p->Robots[i], rand() % p->n, rand() % p->m, rand() % MAX_ANGLE);
		clean(p->f, whereIsRobX(p->Robots[i]), whereIsRobY(p->Robots[i]));
		Clean_floor(whereIsRobX(p->Robots[i]), whereIsRobY(p->Robots[i]), size_floor);
		Set_robot(whereIsRobX(p->Robots[i]), whereIsRobY(p->Robots[i]), angleRob(p->Robots[i]), allegro_p, size_floor);
		
	}
	al_flip_display();
	al_rest(10.0);

	return p->TickCount;

	
}
