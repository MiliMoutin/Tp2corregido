#include <iostream>
#include <cstdlib>
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

double whereIsRobX(PRobot r) {
	return wherex(r->p);
}
double whereIsRobY(PRobot r) {
	return wherey(r->p);
}
double angleRob(PRobot r) {
	return angle(r->p);
}

