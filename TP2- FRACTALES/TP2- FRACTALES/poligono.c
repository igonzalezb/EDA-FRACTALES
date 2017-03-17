

#include "poligono.h"
#include <math.h>
#include <stdio.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5\allegro_color.h>

#define LINE_THICKNESS	5.0

#define PI		acos(-1.0)	//3.14159265358979323846

typedef struct {
	float x;
	float y;
} coordinates_t;

int draw_poligon(float l, float centreX, float centreY, int numPoints);


int poligon(float lStart,float lEnd, float centreX, float centreY, int numPoints, int i)
{
	coordinates_t v;
	double angle = 2 * PI / numPoints;
	double radius = lStart / (2 * sin(PI / numPoints));
	
	if (lStart < lEnd)
	{
		draw_poligon(lStart, centreX, centreY, numPoints);
		return 0;
	}
		
	else
	{
		draw_poligon(lStart, centreX, centreY, numPoints);
		for (int k = 0; k <= numPoints; k++)
		{
			v.x = centreX + radius * sin(i * angle);
			v.y = centreY + radius * cos(i * angle);
			poligon(lStart*0.5, lEnd, v.x, v.y, numPoints, i++);
		}

	}
	return 0;
}



int draw_poligon(float l, float centreX, float centreY, int numPoints)
{
	double angle = 2 * PI / numPoints;
	double radius = l / (2 * sin(PI / numPoints));

	coordinates_t v1, v2;
	
	for (int i = 0, j = 1; i <= numPoints && j <= numPoints; i++, j++)
	{
		v1.x = centreX + radius * sin(i * angle);
		v1.y = centreY + radius * cos(i * angle);

		v2.x = centreX + radius * sin(j * angle);
		v2.y = centreY + radius * cos(j * angle);

		al_draw_line(v1.x, v1.y, v2.x, v2.y, al_color_name("black"), LINE_THICKNESS);
		al_flip_display();
	}
	return 0;
}
