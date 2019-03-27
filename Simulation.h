#pragma once
#include <cstdlib>
#include <stdio.h>
#include "tp2_allegro.h"
#include "Robot.h"
#include "Floor.h"

typedef struct {
	PRobot* Robots;
	PFloor f;
	int n;
	int m;
	int TickCount;
	int nRobots;
}Simulation;

typedef Simulation* PSimulation;

PSimulation createSimulation(int n, int m, int nRobots);
int Mode1(PSimulation s, allegro_t * allegro_p, int mode);
void Mode2(PSimulation s, allegro_t * allegro_p);
void destroySimulation(PSimulation p);

