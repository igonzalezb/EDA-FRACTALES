#include <stdio.h>
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_color.h>
#include <allegro5\allegro_image.h>

#define ERROR -1
void al_configuration_end(void);
int allegro_setup(void);


int main(int argc, char *argv[] )
{
	
	
	
	
	
	if (allegro_setup() == ERROR)
	{
		printf("Failed to configure and start the simulation");
	}

	return 0;

}



int allegro_setup (void)
{
//	if (!al_init())
//	{
//		fprintf(stderr, "Failed to initialize allegro!\n");
//
//		return ERROR;
//	}
//	if (!al_init_image_addon())
//	{
//		fprintf(stderr, "Failed to initialize image addon !\n");
//
//		al_uninstall_system();
//
//		return ERROR;
//	}
//	/*if (!al_install_keyboard())
//	{
//		fprintf(stderr, "Failed to initialize the keyboard!\n");
//
//		al_uninstall_system();
//
//		al_shutdown_image_addon();
//
//		return ERROR;
//	}
//	if (!al_install_mouse())
//	{
//		fprintf(stderr, "Failed to initialize mouse!\n");
//
//		al_shutdown_image_addon();
//
//		al_uninstall_system();
//
//		al_uninstall_keyboard();
//
//		return ERROR;
//	}*/
//	if (!al_init_primitives_addon())
//	{
//		fprintf(stderr, "Failed to initialize the primitives!\n");
//
//		al_shutdown_image_addon();
//
//		//al_uninstall_keyboard();
//
//		al_uninstall_system();
//
//		//al_uninstall_mouse();
//
//		return ERROR;
//	}
//	/*if (!al_install_audio())
//	{
//		fprintf(stderr, "failed to initialize audio!\n");
//
//		return ERROR;
//	}
//	if (!al_init_acodec_addon())
//	{
//		fprintf(stderr, "failed to initialize audio codecs!\n");
//
//		return ERROR;
//	}
//	if (!al_reserve_samples(RESERVED_SAMPLES))
//	{
//		fprintf(stderr, "failed to reserve samples!\n");
//
//		return ERROR;
//	}
//	al_init_font_addon();
//
//	al_init_ttf_addon();*/
//
	return 0;
}
//
//
//
void al_configuration_end(void)
{
//	al_uninstall_system();
//
//	//al_shutdown_image_addon();
//
//	//al_uninstall_keyboard();
//
//	//al_uninstall_mouse();
//
//	al_shutdown_primitives_addon();
//
//	//al_uninstall_audio();
//
//	//al_shutdown_font_addon();
//
//	//al_shutdown_ttf_addon();
//
}
