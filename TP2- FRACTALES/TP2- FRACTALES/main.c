#include <stdio.h>
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_color.h>
#include <allegro5\allegro_image.h>


#include "poligono.h"

#define ERROR -1
#define SCREEN_W    800
#define SCREEN_H    600
#define CENTER_W	(al_get_display_width(display) / 2)
#define CENTER_H	(al_get_display_height(display) / 2)

void al_configuration_end(void);
int allegro_setup(void);


int main(int argc, char *argv[] )
{
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


	poligon(100.0, 30.0, CENTER_W, CENTER_H, 8, 0);
	
	al_rest(5);
	al_configuration_end();
	return 0;

}



int allegro_setup (void)
{
	if (!al_init())
	{
		fprintf(stderr, "Failed to initialize allegro!\n");

		return ERROR;
	}
	if (!al_init_image_addon())
	{
		fprintf(stderr, "Failed to initialize image addon !\n");

		al_uninstall_system();

		return ERROR;
	}
	/*if (!al_install_keyboard())
	{
		fprintf(stderr, "Failed to initialize the keyboard!\n");

		al_uninstall_system();

		al_shutdown_image_addon();

		return ERROR;
	}
	if (!al_install_mouse())
	{
		fprintf(stderr, "Failed to initialize mouse!\n");

		al_shutdown_image_addon();

		al_uninstall_system();

		al_uninstall_keyboard();

		return ERROR;
	}*/
	if (!al_init_primitives_addon())
	{
		fprintf(stderr, "Failed to initialize the primitives!\n");

		al_shutdown_image_addon();

		//al_uninstall_keyboard();

		al_uninstall_system();

		//al_uninstall_mouse();

		return ERROR;
	}
	/*if (!al_install_audio())
	{
		fprintf(stderr, "failed to initialize audio!\n");

		return ERROR;
	}
	if (!al_init_acodec_addon())
	{
		fprintf(stderr, "failed to initialize audio codecs!\n");

		return ERROR;
	}
	if (!al_reserve_samples(RESERVED_SAMPLES))
	{
		fprintf(stderr, "failed to reserve samples!\n");

		return ERROR;
	}
	al_init_font_addon();

	al_init_ttf_addon();*/

	return 0;
}
//
//
//
void al_configuration_end(void)
{
	al_uninstall_system();

	//al_shutdown_image_addon();

	//al_uninstall_keyboard();

	//al_uninstall_mouse();

	al_shutdown_primitives_addon();

	//al_uninstall_audio();

	//al_shutdown_font_addon();

	//al_shutdown_ttf_addon();

}
