#include <stdint.h>
#include <math.h>
typedef struct {
	float x;
	float y;
}point_t;

void TriangleRecursion(point_t StartPosition, float lStart, float lEnd, float RightAngle, float LeftAngle)
{

}


void TriangleRecursionPoints(point_t a, point_t b, point_t c, float lEnd)
{
	point_t center;
	//if /*longitud de algun lado*/<lEND
//	{
		//dibujo triangulo en vase a las tres cordenadas recividas
	//	return;
	   //
	//}
	//else
	//{
		//calculo el centro
		//TriangleRecursionPoints(a,b,center,lEnd);
		//TriangleRecursionPoints(a, center,c,lEnd);
		//TriangleRecursionPoints(center,b,c, lEnd);

	//}

}

//Function taht return de distance between to pointa
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