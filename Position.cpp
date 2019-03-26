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
	return setCoordinates(po, cos((180 / 3.1415)*angle)*delta, sin((180 / 3.1415)*angle)*delta, angle);
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