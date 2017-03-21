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
//
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

#define ERROR -1
#define SCREEN_W    800
#define SCREEN_H    600
#define CENTER_W	(al_get_display_width(display) / 2)
#define CENTER_H	(al_get_display_height(display) / 2)
#define 

void al_configuration_end(void);
int allegro_setup(void);
int parseCallback(char *key, char *value, void *userData);

typedef struct
{
	char **keys;
	char **values;
	char **fractals;
}userData_t;


typedef struct {
	int type;
	float rAngle;
	float lAngle;
	float x0;
	float y0;
	float xf;
	float lStart;
	float lEnd;
	float lConstant;
} parametros_t;

enum {UNIFORME, POLIGONO, MANDELBROT};

int validacionUsuario(parametros_t parametro)
{
	switch (parametro.type)
	{
	case UNIFORME:
		break;
	case POLIGONO:
		break;
		case 

	default:
		printf("ERROR de Fractal ingresado\n");
		break;
	}
}


typedef int(*pCallback) (char *, char*, void *);


int main(int argc, char *argv[] )
{
	userData_t *userData = {NULL};
	pCallback p = &parseCallback;
	
	
	if (!parseCmdLine(argc, argv, p, userData))
	{
		printf("INPUT ERROR\n");
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
	
	coordinates_t center;
	center.x = CENTER_W;
	center.y = CENTER_H;
	
	poligono(100.0, 50.0, 0.5, center, 8);
	
	//al_rest(3);
	//al_clear_to_color(al_color_name("white"));
	//al_flip_display();

	

	//Mandelbrot(-2, 2, -2, 2);

	//TriangleRecursion(center, 200.0, 15.0, 25, 25, SCREEN_W, SCREEN_H);
	al_rest(3);

	al_destroy_display(display);
	al_configuration_end();
	return 0;

}

int parseCallback(char *key, char *value, void *userData)
{
	int i;
	bool isEqual;
	const char *fractalsList[3] = { "UNIFORME","POLIGONO","MANDELBROT" };
	
	if (key == NULL)
	{
		for (i = 0; i < 3; i++)
		{
			isEqual=strcmp(value, fractalsList[i]);
			if (isEqual == true)
			{
				switch (i)
				{
				case 0:	//UNIFORME

					break;
				case 1:	//POLIGONO

					break;

				case 2:	//MANDELBROT

					break;
				
				}
			}

		}
		
		
	}
	else
	{

	}

	


	return 1;
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
