//======================================================================================================================
//			ALGORITMOS Y ESTRUCTURAS DE DATOS
//				ITBA 2017
//
//	TP2 - FRACTALES
// El programa realiza tres tipos de fractales: fractal triangular, fractal poligonal y fractal de mandelbroot.
//
//
//	Grupo 5:
//		IÑAKI GONZALEZ BIGLIARDI
//		IGNACIO MARTIN INHARGUE
//		MATIAS NICOLÁS PIERDOMINICI
//	Git:
//	https://github.com/igonzalezb/EDA-TP2-FRACTALES.git
//
//
//======================================================================================================================

#include <stdio.h>
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_color.h>


#include "poligono.h"
#include "Mandelbrot.h"
#include "triangulo.h"
#include "PARSER.h"
#include "callback.h"

#define ERROR		-1
#define SCREEN_W	800
#define SCREEN_H	600
#define CENTER_W	(al_get_display_width(display) / 2)
#define CENTER_H	(al_get_display_height(display) / 2)
#define VACIO		-9

void al_configuration_end(void);
int allegro_setup(void);
int validacionUsuario(parametros_t);


typedef int(*pCallback) (char *, char*, void *);


int main(int argc, char *argv[] )
{
	pCallback p = &ValidacionFractales;

	parametros_t user1;
	parametros_t * userData = &user1;

	user1.type = VACIO;
	user1.lAngle = VACIO;
	user1.rAngle = VACIO;
	user1.lConstant = VACIO;
	user1.lStart = VACIO;
	user1.lEnd = VACIO;
	user1.numPoints = VACIO;
	user1.xi = VACIO;
	user1.yi = VACIO;
	user1.xf = VACIO;
	user1.yf = VACIO;
	
	
	if (!parseCmdLine(argc, argv, p, &user1))
	{
		printf("PARSER ERROR\n");
	}

	if (validacionUsuario(user1) == ERROR)
	{
		printf("INPUT ERROR\n");
		return ERROR;
	}
		
	

//============================================================================================================
	ALLEGRO_DISPLAY * display = NULL;
	
	if (allegro_setup() == ERROR)
	{
		printf("Failed to configure and start the simulation");
	}

	display = al_create_display(SCREEN_W, SCREEN_H);
	if (!display) {
		fprintf(stderr, "Failed to create display!\n");
		al_configuration_end();
		return ERROR;
	}

	al_clear_to_color(al_color_name("white"));
	al_flip_display();

//===========================================================================================================
	

	
	point_t center;
	center.x = CENTER_W;
	center.y = CENTER_H;
	coordinates_t centre;
	centre.x = CENTER_W;
	centre.y = CENTER_H;

	switch (user1.type)
	{
		case UNIFORME:
			TriangleRecursion(center, user1.lStart, user1.lEnd, user1.rAngle, user1.rAngle, SCREEN_W, SCREEN_H);
			al_rest(5);
			break;
		case POLIGONO:
			
			poligono(user1.lStart, user1.lEnd, user1.lConstant, centre, user1.numPoints);
			al_rest(5);
			break;
		case MANDELBROT:
			Mandelbrot(user1.xi, user1.yi, user1.xf, user1.yf);
			break;
	}

	
	al_destroy_display(display);
	al_configuration_end();
	return 0;

}
//===============================================================================================================================
//	Validacion de datos 
//
//	Cheque que cada fractal tenga los valores necesarios para dibujar y no de mas.
//===============================================================================================================================


int validacionUsuario(parametros_t p)
{
	switch (p.type)
	{
	case UNIFORME:
		if ((p.rAngle == VACIO) || (p.lAngle == VACIO) || (p.lStart == VACIO) || (p.lEnd == VACIO))
		{
			return ERROR;
		}
		else if (((p.xi != VACIO) || (p.yi != VACIO) || (p.xf != VACIO) || (p.yf != VACIO) || (p.lConstant != VACIO) || (p.numPoints != VACIO)))
		{
			return ERROR;
		}
		break;

	case POLIGONO:
		if ((p.lEnd == VACIO) || (p.lConstant == VACIO) || (p.lStart == VACIO) || (p.numPoints == VACIO))
		{
			return ERROR;
		}
		else if (((p.xi != VACIO) || (p.yi != VACIO) || (p.xf != VACIO) || (p.yf != VACIO) || (p.rAngle != VACIO) || (p.lAngle != VACIO)))
		{
			return ERROR;
		}

		break;
	case MANDELBROT:
		if ((p.xi == VACIO) || (p.yi == VACIO) || (p.xf == VACIO) || (p.yf == VACIO))

		{
			return ERROR;
		}
		else if (((p.rAngle != VACIO) || (p.lAngle != VACIO) || (p.lStart != VACIO) || (p.lConstant != VACIO) || (p.lEnd != VACIO) || (p.numPoints != VACIO)))
		{
			return ERROR;
		}
		break;
	default:
		return ERROR;

	}

	return 0;
}





int allegro_setup (void)
{
	if (!al_init())
	{
		fprintf(stderr, "Failed to initialize allegro!\n");

		return ERROR;
	}

	if (!al_init_primitives_addon())
	{
		fprintf(stderr, "Failed to initialize the primitives!\n");

		al_uninstall_system();

		return ERROR;
	}

	return 0;
}

void al_configuration_end(void)
{
	al_uninstall_system();

	al_shutdown_primitives_addon();

	
}
