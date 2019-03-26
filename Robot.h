#pragma once
#include "Position.h"
#define M_PI       3.14159265358979323846   // pi
#define MAX_ANGLE 360

typedef struct {
	PPosition p;
}Robot;


typedef Robot* PRobot;

PRobot createRobot();
bool setLocation(PRobot r, double x, double y, double angle);
double whereIsRobX(PRobot r);
bool moveRobot(PRobot r, int delta);
double whereIsRobY(PRobot r);
bool nextCoordinate(PRobot bot);
double angleRob(PRobot r);
void destroyRob(PRobot r);

