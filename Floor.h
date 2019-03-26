#pragma once
#pragma once



typedef struct {
	bool* baldosas;
	int m;
	int n;
}Floor;

typedef Floor* PFloor;

PFloor createFloor(int m, int n);
bool isClean(PFloor f);
bool clean(PFloor f, double x, double y);
void destroyFloor(PFloor f);
bool validRange(PFloor f, double x, double y);
