#pragma once
#ifndef CALLBACK_H
#define CALLBACK_H

enum { UNIFORME, POLIGONO, MANDELBROT };
typedef struct {
	int type;
	float rAngle;
	float lAngle;
	float xi;
	float yi;
	float xf;
	float yf;
	float lStart;
	float lEnd;
	float lConstant;
	int numPoints;
} parametros_t;
int ValidacionFractales(char * Key, char* Value, void * Data);


#endif // _CALLBACK_H