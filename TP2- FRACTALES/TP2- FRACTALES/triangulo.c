#include<stdio.h>
#include <stdint.h>
#include <math.h>
#include "triangulo.h"
#include <allegro5\allegro.h>
#include <allegro5/allegro_primitives.h>

#define LINE_THICKNESS 1 //Grosor de la linea del triangulo 

#define MY_PI 3.14159265358979323846
#define TRIANGLE_INTERNAL_ANGLE 180.0
#define TRUE 1
#define FALSE 0
void TriangleRecursionPoints(point_t a, point_t b, point_t c, float lEnd);

double DistanceBetweenPoints(point_t x, point_t y);

point_t TriangleIncenter(point_t a, point_t b, point_t c);

double DistanceBetweenPoints(point_t x, point_t y);

ALLEGRO_COLOR RandomColors(void);

void DrawTriangle3Points(point_t a, point_t b, point_t c);
point_t TriangleThirdPoint(point_t StartBase, float BaseLengh, float RightAngle, float LeftAngle);
float ValAbsolute(float value);

void TriangleRecursion(point_t StartPosition, float lStart, float lEnd, float RightAngle, float LeftAngle,int16_t ScreenWidth,int16_t ScreenHigh)
{
	point_t b = { StartPosition.x + lStart,StartPosition.y};
	point_t c = {0,0};
	uint8_t Error=FALSE;

	if (TRIANGLE_INTERNAL_ANGLE > (ValAbsolute(LeftAngle) + ValAbsolute(RightAngle)))//evaluo la suma de los angulos los angulos
	{
		c = TriangleThirdPoint(StartPosition, lStart, ((RightAngle*MY_PI)/ TRIANGLE_INTERNAL_ANGLE), ((LeftAngle*MY_PI) / TRIANGLE_INTERNAL_ANGLE));
		c.y= StartPosition.y - (c.y - StartPosition.y);
	}
	else if (TRIANGLE_INTERNAL_ANGLE <= (ValAbsolute(LeftAngle) + ValAbsolute(RightAngle)))
	{
		Error = TRUE;
	}
    else if ((b.x > ScreenWidth) || (b.y > ScreenHigh))//chequeo que todos los puntos esten dentro de la pantalla
	{
		Error = TRUE;
	}
	else if ((StartPosition.x > ScreenWidth) || (StartPosition.y > ScreenHigh))
	{
		Error = TRUE;
	}
	else if ((c.x > ScreenWidth) || (c.y > ScreenHigh))
	{
		Error = TRUE;
	}
	
	
	
	if (!Error)
	{
		TriangleRecursionPoints(StartPosition, b, c, lEnd);
	}
	else
	{
		printf("ERROR EN EL INGRESO DE LOS PARAMTROS \n");
	}
	

}

//TriangleRecursionPoints
//recive 3 coordenadas y la longitud minima de lado
//devuelve:nada
//accion:dibuja recursivamente triangulos de centro

void TriangleRecursionPoints(point_t a, point_t b, point_t c, float lEnd)
{
	
	//si la distancia de algun segmento es menor que el valor minimo -> caso base
	if ((DistanceBetweenPoints(a, TriangleIncenter(a, b, c))<lEnd)||(DistanceBetweenPoints(b, TriangleIncenter(a, b, c))<lEnd) || (DistanceBetweenPoints(TriangleIncenter(a, b, c),c)<lEnd))
	{
		
		DrawTriangle3Points(a,b,c); //dibujo el triangulo 
		return;
	   
	}
		TriangleRecursionPoints(TriangleIncenter(a, b, c), b, c, lEnd);
		TriangleRecursionPoints(a, TriangleIncenter(a, b, c), c, lEnd);
		TriangleRecursionPoints(a,b, TriangleIncenter(a, b, c),lEnd);
}

//DistanceBetweenPoints
//recive 2 point_t
//devuelve: double
//accion: calcula la distancia euclidiana entre
//dos puntos
//
double DistanceBetweenPoints(point_t x, point_t y)
{
	return  sqrt((double)(((x.x - y.x)*(x.x - y.x)) + ((x.y - y.y)*(x.y - y.y))));

}


//TriangleIncenter
//recive: 3 puntos
//devuelve: point_t
//accion: calcula el incentro entre los tres vertices 
//recividos

point_t TriangleIncenter(point_t a, point_t b, point_t c)
{
	
	point_t center;
			
	center.x = (a.x + b.x + c.x) / 3.0;
	center.y = (a.y + b.y + c.y) / 3.0;
	return center;
}

//RandomColors
//recive: nada
//devuelve: ALLEGRO_COLOR
//accion: genera un ALLEGRO_COLOR random
//
//

ALLEGRO_COLOR RandomColors()
{
	return al_map_rgb(rand() % 255, rand() % 255, rand() % 255);
}

//DrawTriangle3Points
//recive: las tres coordenadas de los vertices del triangulo
//devuelve:no devuelve nada
//accion: dibuja un triangulo, cada vez que se la llama dibuja un triangulo con colores de lados distintos
//
//
void DrawTriangle3Points(point_t a, point_t b, point_t c)
{
	al_draw_triangle(a.x, a.y, b.x, b.y, c.x, c.y, RandomColors(), LINE_THICKNESS);
	al_flip_display();
}


//TriangleThirdPoint
//recive: un punto, la longitud del lado, y los 3 angulos adyacebtes a ese lado
//devuelve: el tercer punto de un triangulo
//
//
//
point_t TriangleThirdPoint(point_t StartBase, float BaseLengh, float RightAngle, float LeftAngle)
{
	point_t ThirdPoint;
	float LeftBase = BaseLengh *((sin(RightAngle)) / (sin(MY_PI-(RightAngle+LeftAngle))));
	ThirdPoint.x = StartBase.x + (cos(LeftAngle)*LeftBase);
	ThirdPoint.y = StartBase.y + (sin(LeftAngle)*LeftBase);
	return ThirdPoint;
}

// ValAbsolute
//recive float
//devuelve valor absoluto de un numero
//
//

float ValAbsolute(float value)
{
	if (value < 0)
	{
		return ((-1)*value);
	}
	else
	{
		return value;
	}
}
