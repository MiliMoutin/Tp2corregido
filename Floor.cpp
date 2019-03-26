
#include "Floor.h"
#include <iostream>
#include <cstdlib>
using namespace std;


PFloor createFloor(int m, int n) {
	PFloor toret = NULL;
	toret = (PFloor)malloc(sizeof(Floor));
	if (toret != NULL) {
		toret->m = m;
		toret->n = n;
		toret->baldosas = (bool*)malloc(sizeof(bool) *m *n);
		for (int i = 0; i < m*n; i++)
			toret->baldosas[i] = false;
	}
	else {
		free(toret);
	}
	return toret;
}

bool isClean(PFloor p) {
	bool clean = true;
	for (int i = 0; i < p->m*p->n && clean; i++) {
		clean = p->baldosas[i];
	}
	return clean;
}

bool clean(PFloor f, int x, int y) {
	int i = floor(x);
	int j = floor(y);
	if (*(f->baldosas + (i*f->n) + j) == true) {
		return false;
	}
	*(f->baldosas + (i*f->n) + j) = true;
	return true;
}

void destroyFloor(PFloor f) {
	free(f->baldosas);
	free(f);
}

bool validRange(PFloor f, double x, double y) {
	return (x < f->m) && (y < f->n);
}



