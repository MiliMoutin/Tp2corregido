
#include "Floor.h"
#include <iostream>
#include <cstdlib>
using namespace std;


PFloor createFloor(int n, int m) {
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
	for (int i = 0; i < p->m*p->n; i++) 
	{
		if (p->baldosas[i] == false) 
		{
			return false;
		}
	}
	return true;
}

bool clean(PFloor f, double x, double y) {
	int j = floor(x);
	int i = floor(y);
	if (*(f->baldosas + (i*f->n) + j) == true) 
	{
		return false;
	}
	*(f->baldosas + (i*f->n) + j) = true;
	return true;
}


bool validRange(PFloor f, double x, double y, double angle,float size) {
	double x_ = x + cos((angle*M_PI) / 180);
	double y_ = y + sin((angle*M_PI) / 180);
	if ((x_ > ((f->n)-0.3)) || ((x_ < 0.3)) || (y_ > ((f->m) - 0.3)) || (y_ < 0.2))
		//verfica que la nueva posicion no se salga del mapa
	{
		return false ;
	}
	else {
		return true ;
	}
}

bool isCleanBaldosa(PFloor f, double x, double y) {
	return *(f->baldosas + ((f->n)*(int)(floor(x))) + (int)floor(y));
}

void destroyFloor(PFloor f) {
	//free(f->baldosas);
	free(f);
	return;
}



