#ifndef MANDELBROT_H
#define MANDELBROT_H

/******** librerías  ***********/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <allegro5/allegro.h>

/***** typedef ********/

typedef struct      //defino números complejos
{
	float real;
	float imaginario;
} 
COMPLEJO;

typedef unsigned int UINT;


/************ funciones *****************/

COMPLEJO comp_cuadrado(COMPLEJO c);
UINT fn_mandelbrot (UINT nmax, COMPLEJO z,int af,int bf) ;
ALLEGRO_DISPLAY * in_allegro_color(void);
UINT sub_mandelbrot (void);
void Mandelbrot(void); //función principal

#endif