#include "Simulation.h"
#define ROBI p->Robots[i]
#define ROBZ p->Robots[z]
#define TIMES 1000

PSimulation createSimulation(int n, int m, int nRobots) {
	PSimulation toret = (PSimulation)malloc(sizeof(Simulation));
	if (toret != NULL) {
		toret->n = n;
		toret->m = m;
		toret->f = createFloor(n, m);
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
		
		
	if (mode == 1) 
	{
			Create_dirty_floor(p->n, p->m, size_floor);
	}

	p->Robots = (PRobot*)malloc(sizeof(PRobot)*(p->nRobots)); 

	for (int i = 0; i < p->nRobots; i++) 
	{
		ROBI = createRobot();
		setLocation(ROBI, (double)rand() / (RAND_MAX / p->n), (double)rand() / (RAND_MAX / p->m), rand() % MAX_ANGLE);
		clean(p->f, whereIsRobX(ROBI), whereIsRobY(ROBI));

		if (mode == 1) {
						 Set_robot(whereIsRobX(ROBI), whereIsRobY(ROBI), angleRob(ROBI), allegro_p, size_floor);
					   }
	}

	if (mode == 1) 
	{
		al_flip_display();
		al_rest(0.5);
	}


	while (isClean(p->f)==false) 
	{
		if (mode == 1)
		{ 
			al_clear_to_color(al_map_rgb(0, 0, 0));
			Create_dirty_floor(p->n, p->m, size_floor);
			
			for (int k = 0; k < p->n; k++) {
				for (int j = 0; j < p->m; j++) {
					if (isCleanBaldosa((p->f), j, k)) {
						Clean_floor(k, j, size_floor);
					}
				}
			}

			for (int z = 0; z < p->nRobots;z++) 
			{
				Set_robot(whereIsRobX(ROBZ), whereIsRobY(ROBZ), angleRob(ROBZ), allegro_p, size_floor);
			}
		}

		for (int i = 0; i < p->nRobots; i++) 
		{
			if (validRange(p->f, whereIsRobX(ROBI), whereIsRobY(ROBI), angleRob(ROBI),size_floor)) 
			{
					moveRobot(ROBI, 1);
					clean(p->f, whereIsRobX(ROBI), whereIsRobY(ROBI));
			}
			else {
				setLocation(ROBI, whereIsRobX(ROBI), whereIsRobY(ROBI), rand() % 360);
			}			
		}


		p->TickCount++;
		if (mode == 1) 
		{
			al_flip_display();
			al_rest(0.1);
		}
	}

	if (mode == 1) 
	{
		for (int k = 0; k < p->n; k++) {
			for (int j = 0; j < p->m; j++) 
			{
					Clean_floor(k, j, size_floor);
			}
			

		}


		for (int z = 0; z < p->nRobots; z++) 
		{
			Set_robot(whereIsRobX(ROBZ), whereIsRobY(ROBZ), angleRob(ROBZ), allegro_p, size_floor);
		}

		al_rest(1);
	
		al_ShowTickCount(p->TickCount, allegro_p);
	}
	
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

void Mode2(PSimulation p, allegro_t * allegro_p) {
	int times;
	double tickAnt = 0;
	double TickProm = 0;
	int i = 1;
	double tick_v[10000];
	//double* tick_v = (double*)malloc(sizeof(double));




	times = TIMES;
	PSimulation p2 = createSimulation(p->n, p->m, i);
	while (times != 0)
	{
		TickProm += Mode1(p2, allegro_p, 2); //simula el modo 1 1000 veces y guarda la suma de todos los tick
		times--;
	}
	TickProm = TickProm / TIMES; //guarda el promedio de todos los tick sobre 1000
	tick_v[0] = TickProm;	// va guardando en el arreglo todos los valores de las sim
	//tick_v = (double *)realloc(tick_v, sizeof(double)*(i + 1));	//agrega mas espacio
	destroySimulation(p2);
	i++;
	
	do
	{		
		times = TIMES;
		PSimulation p2 = createSimulation(p->n, p->m, i);
		while (times != 0)
		{
			TickProm += Mode1(p2, allegro_p, 2); //simula el modo 1 1000 veces y guarda la suma de todos los tick
			times--;
		}
		TickProm = TickProm / TIMES; //guarda el promedio de todos los tick sobre 1000
		tick_v[i-1] = TickProm;	// va guardando en el arreglo todos los valores de las sim


		i++;
		destroySimulation(p2);

		printf("%f\n", abs(tick_v[i-2] - tick_v[i-3]));
	} while (abs(tick_v[i-2] - tick_v[i-3]) > 0.1);
	al_show_graph(tick_v, --i);
	return;
}


/*for (int i = 1;abs(tick_v[i] - tick_v[i - 1]) > 0.1; i++) {
		times = TIMES;
		PSimulation p2 = createSimulation(p->n, p->m, i);
		while (times != 0)
		{
			TickProm += Mode1(p2, allegro_p, 2); //simula el modo 1 1000 veces y guarda la suma de todos los tick
			times--;
		}
		TickProm = TickProm / TIMES; //guarda el promedio de todos los tick sobre 1000
		printf("%f", TickProm);
		tick_v[i-1] = TickProm;	// va guardando en el arreglo todos los valores de las sim
		tick_v = (double *)realloc(tick_v, sizeof(double)*(i));	//agrega mas espacio
		CantRobotMax++;

		destroySimulation(p2);
	}*/