#include <iostream>
#include <cstdlib>
#include <math.h>
#include "Robot.h"

using namespace std;

PRobot createRobot() {
	PRobot toret = (PRobot)malloc(sizeof(Robot));
	if (toret == NULL) {
		free(toret);
		return NULL;
	}
	toret->p = createPos(-1, -1, -1);
	return toret;
}

bool setLocation(PRobot r, double x, double y, double angle) {
	setCoordinates(r->p, x, y, angle);
	return true;
}

bool moveRobot(PRobot r, int delta) {
	movePoint(r->p, delta, angle(r->p));
	return true;
}

double whereIsRobX(PRobot r) {
	return wherex(r->p);
}
double whereIsRobY(PRobot r) {
	return wherey(r->p);
}
double angleRob(PRobot r) {
	return angle(r->p);
}

void destroyRobot(PRobot r) {
	destroyPosition(r->p);
	free(r);
}

bool nextCoordinate(PRobot bot) // recibe el punto y el maximo valor que pueden tener las coordenadas en el piso creado
{
	double x = whereIsRobX(bot);
    double y = whereIsRobY(bot);
    double angulo = angleRob(bot);
	setCoordinates(bot->p, x, y, rand()%MAX_ANGLE); //guarda nueva angulo
		return true;
}