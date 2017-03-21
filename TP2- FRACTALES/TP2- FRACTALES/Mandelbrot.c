
#include "Mandelbrot.h"

COMPLEJO comp_cuadrado(COMPLEJO c) //función que eleva complejos al cuadrado
{
	float a= (c.real)*(c.real)-(c.imaginario)*(c.imaginario), b=2*(c.real)*(c.imaginario); //a y b son las partes real e imaginaria del resultado
	COMPLEJO result;
	result.real=a;
	result.imaginario=b;
	return result;
}
UINT fn_mandelbrot (UINT nmax, COMPLEJO z,int af,int bf) 
/****** La función fn_mandelbrot calcula la función fn hasta nmax, si diverge devuelve el n para el cuál sucedió, de lo contrario devuelve 0. 
        Recibe el punto analizado y los límites del plano para analizar la divergencia                                                         ********/
{
	UINT n;
	COMPLEJO fn={0,0},a={0,0}; 
	for(n=0;n<=nmax;++n)
	{
		if((fabs(fn.real)>af)||(fabs(fn.imaginario)>bf)) //verifica si la función diverge
			return n;
		else
		{
			a=comp_cuadrado(fn);
			fn.real=(a.real)+(z.real);                  //fn=f(n-1)^2+z
			fn.imaginario=(a.imaginario)+(z.imaginario);
		}
	}
	return nmax; //si llegó a nmax sin diverger es un punto del conjunto de Mandelbrot
}


UINT sub_mandelbrot (float a0, float af, float b0, float bf)//recibe los límites del plano complejo, siendo b la parte imaginaria y a la real, 0 los extremos negativos y f los positivos
{
/****** Variables *******/

	float a=a0,b=bf,grany=(bf-b0)/600,granx=(af-a0)/800;//a y b son las variables que recorren el plano pintándolo y gran es la granularidad en x o y
	COMPLEJO z={0,0};
	UINT n,m,l;

/******* Interacción con el usuario *********/

	printf("Oprima 1, 2 o 3 para elegir la opcion de combinacion de colores para el grafico,siendo 1 la mas simple.\n");
	char i=getchar();
	while (i=='\n') //evita leer el caracter del enter que queda en el buffer
		i=getchar();
	if(i=='1')
	{
		m=0;
		l=0;
	}
	else if (i=='2')
	{
		m=0;
		l=1;
	}
	else if (i=='3')
	{
		m=1;
		l=1;
	}
	else
	{
		printf("Opcion invalida, pruebe nuevamente.\n");
		return 1;
	}


/**** Recorre el display pixel por pixel, evalúa la función y pinta del color correspondiente *****/

	for(float x=0.5;x<=799.5;x=x+1,a=a+granx)
	{
		for(float y=0.5;y<=599.5;y=y+1,b=b-grany)  //x e y arrancan en 0.5 ya que es el centro del primer pixel, y se incrementan en uno para ir ubicándose en cada centro
		{
			z.real=a;
			z.imaginario=b;  //z es el número complejo a evaluar
			n=fn_mandelbrot(255,z,af,bf);
			ALLEGRO_COLOR color=al_map_rgb(((255-n)*n*m)/(0.1),l*(255-n)/(0.3*(n-(n-1)*(1-m))),255-n); //pinta de acuerdo a la opción elegida por el usuario
			al_draw_pixel(x,y,color);
		}
		b=bf;

	}
	al_flip_display(); //muestra el display
	al_rest(5.0);

/***** Interacción con el usuario, define si devuelve un valor que le permita volver a empezar o termina *****/

	printf("Si desea volver a empezar presione 1, de lo contrario 0 para terminar.\n");
	char k=getchar();
	while (k=='\n') //evita leer el caracter del enter que queda en el buffer
		k=getchar();
	if(k=='1')
		return 1;
	else if(k=='0')
		return 0;
	else
		printf("Error de lectura, el programa finalizara.\n");
	al_rest(3.0);
	return 0;
}

int Mandelbrot(float a0, float af, float b0, float bf)//recibe los límites del plano complejo, siendo b la parte imaginaria y a la real, 0 los extremos negativos y f los positivos
/*********** Función principal, permite repetir el gráfico si el usuario lo desea y valida datos ********/
{

	if ((a0 > -0.4) || (a0 < -4))
	{
		printf("a0 Value Incorrect\n");
		return -1;
	}
	else if ((af < 0.4) || (af > 4))
	{
		printf("af Value Incorrect\n");
		return -1;
	}
	else if ((b0 > -0.4) || (b0 < -4))
	{
		printf("b0 Value Incorrect\n");
		return -1;
	}
	else if ((bf < 0.4) || (bf > 4))
	{
		printf("bf Value Incorrect\n");
		return -1;
	}
	
	UINT i=1;
	while (i)
	{
		i=sub_mandelbrot(a0,af,b0,bf);
	}
}
