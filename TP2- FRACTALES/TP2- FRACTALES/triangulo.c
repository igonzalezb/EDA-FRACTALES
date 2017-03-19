#include<stdio.h>
#include <stdint.h>
#include <math.h>
#include "triangulo.h"
#include <allegro5\allegro.h>
#include <allegro5/allegro_primitives.h>

#define LINE_THICKNESS 1
point_t TriangleIncenter(point_t a, point_t b, point_t c);
double DistanceBetweenPoints(point_t x, point_t y);
ALLEGRO_COLOR RandomColors();

void TriangleRecursion(point_t StartPosition, float lStart, float lEnd, float RightAngle, float LeftAngle)
{

}


void TriangleRecursionPoints(point_t a, point_t b, point_t c, float lEnd)
{
	
	
	if ((DistanceBetweenPoints(a, TriangleIncenter(a, b, c))<lEnd)||(DistanceBetweenPoints(b, TriangleIncenter(a, b, c))<lEnd) || (DistanceBetweenPoints(TriangleIncenter(a, b, c),c)<lEnd))
	{
		//dibujo triangulo en vase a las tres cordenadas recividas
		al_draw_triangle(a.x, a.y, b.x, b.y, c.x, c.y,RandomColors(), LINE_THICKNESS);
		al_flip_display();
		return;
	   
	}
	
	
		
		TriangleRecursionPoints(TriangleIncenter(a, b, c), b, c, lEnd);
		TriangleRecursionPoints(a, TriangleIncenter(a, b, c), c, lEnd);
		TriangleRecursionPoints(a,b, TriangleIncenter(a, b, c),lEnd);
		
		

	

}


double DistanceBetweenPoints(point_t x, point_t y)
{
	return  sqrt((double)(((x.x - y.x)*(x.x - y.x)) + ((x.y - y.y)*(x.y - y.y))));

}


point_t TriangleIncenter(point_t a, point_t b, point_t c)
{
	
	point_t center;
			
	center.x = (a.x + b.x + c.x) / 3.0;
	center.y = (a.y + b.y + c.y) / 3.0;
	return center;
}


ALLEGRO_COLOR RandomColors()
{
	return al_map_rgb(rand() % 255, rand() % 255, rand() % 255);
}