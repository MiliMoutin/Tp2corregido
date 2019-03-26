#pragma once
#pragma once
#define M_PI       3.14159265358979323846   // pi
#define MAX_ANGLE 360


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
bool validRange(PFloor f, double x, double y, double angle);
bool isCleanBaldosa(PFloor f, double x, double y);
