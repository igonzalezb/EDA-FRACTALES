#ifndef POLIGONO_H
#define POLIGONO_H


typedef struct {
	float x;
	float y;
} coordinates_t;



int poligono(float lStart, float lEnd, float lConstant, coordinates_t center, int numPoints);


#endif // POLIGONO_H
