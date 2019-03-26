#pragma once
#include "Position.h"

typedef struct {
	PPosition p;
}Robot;


typedef Robot* PRobot;

PRobot createRobot();
bool setLocation(PRobot r, double x, double y, double angle);
double whereIsRobX(PRobot r);
double whereIsRobY(PRobot r);
double angleRob(PRobot r);

