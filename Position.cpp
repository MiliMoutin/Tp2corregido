#include <iostream>
#include <cmath>
#include "Position.h"

using namespace std;

PPosition createPos(double x, double y, double angle) {
	PPosition toret = (PPosition)malloc(sizeof(Position));
	if (toret == NULL) {
		free(toret);
		return NULL;
	}
	toret->x = x;
	toret->y = y;
	toret->angle = angle;
	return toret;
}


bool setCoordinates(PPosition po, double x, double y, double angle) {
	po->x = x;
	po->y = y;
	po->angle = angle;
	return true;
}

bool movePoint(PPosition po, double delta, double angle) {
	return setCoordinates(po, wherex(po)+(cos((3.1415 / 180)*angle)*delta), wherey(po)+(sin((3.1415 / 180)*angle)*delta), angle);
}

double wherex(PPosition po) {
	return po->x;
}

double wherey(PPosition po) {
	return po->y;
}

double angle(PPosition po) {
	return po->angle;
}

void destroyPosition(PPosition po) {
	free(po);
}

