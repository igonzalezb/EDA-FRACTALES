#include<stdio.h>
#include <stdint.h>
#include <math.h>
#include "triangulo.h"



point_t TriangleIncenter(point_t a, point_t b, point_t c);
double DistanceBetweenPoints(point_t x, point_t y);


void TriangleRecursion(point_t StartPosition, float lStart, float lEnd, float RightAngle, float LeftAngle)
{

}


void TriangleRecursionPoints(point_t a, point_t b, point_t c, float lEnd)
{
	point_t center;
	if ((DistanceBetweenPoints(a,b)<lEnd)|| (DistanceBetweenPoints(b,c)<lEnd) || (DistanceBetweenPoints(a,c)<lEnd))
	{
		//dibujo triangulo en vase a las tres cordenadas recividas
		return;
	   
	}
	else
	{
		center = TriangleIncenter(a, b, c);
		TriangleRecursionPoints(a,b,center,lEnd);
		TriangleRecursionPoints(a, center,c,lEnd);
		TriangleRecursionPoints(center,b,c, lEnd);

	}

}


double DistanceBetweenPoints(point_t x, point_t y)
{
	return  sqrt((double)(((x.x - y.x)*(x.x - y.x)) + ((x.y - y.y)*(x.y - y.y))));

}


point_t TriangleIncenter(point_t a, point_t b, point_t c)
{
	
	point_t center;

		center.x=(float)(((a.x)*DistanceBetweenPoints(b, c)) + ((b.x)*DistanceBetweenPoints(a, c)) + ((c.x)*DistanceBetweenPoints(a, b)) / (DistanceBetweenPoints(b, c) + DistanceBetweenPoints(a, c) + DistanceBetweenPoints(a, b)));
		center.y =(float)(((a.y)*DistanceBetweenPoints(b, c)) + ((b.y)*DistanceBetweenPoints(a, c)) + ((c.y)*DistanceBetweenPoints(a, b)) / (DistanceBetweenPoints(b, c) + DistanceBetweenPoints(a, c) + DistanceBetweenPoints(a, b)));
		return center;
}