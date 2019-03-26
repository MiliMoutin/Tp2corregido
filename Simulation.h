#pragma once
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
int Mode1(PSimulation s);
