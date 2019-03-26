#include "Simulation.h"
#define ROBI p->Robots[i]
#define ROBZ p->Robots[z]
#define TIMES 1000

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

int Mode1(PSimulation p, allegro_t * allegro_p, int mode) {
		float size_floor_h = SCREEN_H / (p->m);
		float size_floor_w = SCREEN_W / (p->n);
		float size_floor = size_floor_h > size_floor_w ? size_floor_w : size_floor_h;   //Determino tamaño de baldosa para que se ajuste a la ventana
		if (mode == 1) {
			Create_dirty_floor(p->n, p->m, size_floor);
		}
	p->Robots = (PRobot*)malloc(sizeof(PRobot)*(p->nRobots)); 
	for (int i = 0; i < p->nRobots; i++) {
		ROBI = createRobot();
		if (mode = 1) {
			setLocation(ROBI, (double)rand() / (RAND_MAX / p->n), (double)rand() / (RAND_MAX / p->m), rand() % MAX_ANGLE);
		}
		clean(p->f, whereIsRobX(ROBI), whereIsRobY(ROBI));
		if (mode == 1) {
			Set_robot(whereIsRobX(ROBI), whereIsRobY(ROBI), angleRob(ROBI), allegro_p, size_floor);
		}
	}
	if (mode == 1) {
		al_flip_display();
		al_rest(0.5);
		srand(time(NULL));
	}


	while (isClean(p->f)==false) {
		al_clear_to_color(al_map_rgb(0, 0, 0));
		if (mode == 1) {
			Create_dirty_floor(p->n, p->m, size_floor);
			for (int k = 0; k < p->n; k++) {
				for (int j = 0; j < p->m; j++) {
					if (isCleanBaldosa((p->f), k, j)) {
						Clean_floor(k, j, size_floor);
					}
				}

			}
			for (int z = 0; z < p->nRobots;z++) {
				Set_robot(whereIsRobX(ROBZ), whereIsRobY(ROBZ), angleRob(ROBZ), allegro_p, size_floor);
			}
		}
		for (int i = 0; i < p->nRobots; i++) {
			/*moveRobot(ROBI, 1, angleRob(ROBI));*/
			if (validRange(p->f, whereIsRobX(ROBI), whereIsRobY(ROBI), angleRob(ROBI))) {
					moveRobot(ROBI, 1);
					clean(p->f, whereIsRobX(ROBI), whereIsRobY(ROBI));
					/*Clean_floor(whereIsRobX(ROBI), whereIsRobY(ROBI), size_floor);*/
					/*Set_robot(whereIsRobX(ROBI), whereIsRobY(ROBI), angleRob(ROBI), allegro_p, size_floor);*/
					//al_move_robot(whereIsRobX(ROBI), whereIsRobY(ROBI), angleRob(ROBI), allegro_p, size_floor);
			}
			else {
				setLocation(ROBI, whereIsRobX(ROBI), whereIsRobY(ROBI), rand() % 360);
			}			
		}
		p->TickCount++;
		if (mode == 1) {
			al_flip_display();
			al_rest(0.5);
		}
	}
	for (int k = 0; k < p->n; k++) {
		for (int j = 0; j < p->m; j++) {
			if (isCleanBaldosa((p->f), k, j)) {
				Clean_floor(k, j, size_floor);
			}
		}

	}
	for (int z = 0; z < p->nRobots;z++) {
		Set_robot(whereIsRobX(ROBZ), whereIsRobY(ROBZ), angleRob(ROBZ), allegro_p, size_floor);
	}
	al_rest(1);

	al_ShowTickCount(p->TickCount, allegro_p);
	return p->TickCount;

}

void destroySimulation(PSimulation p) {
	for (int i = 0; i < p->nRobots; i++) {
		free(ROBI);
	}
	free(p->Robots);
	destroyFloor(p->f);
	free(p);
}

/*void Mode2(PSimulation p, allegro_t * allegro_p) {
	int times;
	int tickAnt;
	int TickProm;
	for (int i = 1; ; i++) {
		tickAnt = TickProm;
		times = TIMES;
		int aux = 0;
		PSimulation p2 = createSimulation(p->n, p->m, i);
		while (times != 0) {
			TickProm+=Mode1(p, allegro_p, 2);
			times--;
		}
		TickProm = TickProm / TIMES;
	}*/


