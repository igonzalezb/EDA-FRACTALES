//#include <stdbool.h>
//#include <allegro5/allegro.h>
//#include <allegro5/allegro_color.h>
//#include <allegro5/allegro_image.h>
//
//#include <allegro5/allegro_primitives.h>
//#include <allegro5/allegro_font.h>
//#include <allegro5/allegro_ttf.h>
//
//#include <allegro5/allegro_audio.h> 
//#include <allegro5/allegro_acodec.h>
//#include <stdio.h>
//
//
//
//bool allegro_startup(void)
//{
//	if (al_init())
//	{
//		if (al_init_primitives_addon())
//		{
//			if (al_install_keyboard())
//			{
//				if (al_install_mouse())
//				{
//					if (al_init_image_addon())
//					{
//						al_init_font_addon();   //Void
//						if (al_init_ttf_addon())
//						{
//							if (al_install_audio())
//							{
//								if (al_init_acodec_addon())
//								{
//									if (al_reserve_samples(1))
//									{
//										return true;
//
//									}
//									else
//										fprintf(stderr, "ERROR: Failed to reserve samples:(\n");
//									//al_shutdown_acodec_addon(); Does not exist
//								}
//								else
//									fprintf(stderr, "ERROR: Failed to initialize acodec addon\n");
//								al_uninstall_audio();
//							}
//							else
//								fprintf(stderr, "ERROR: Failed to install audio\n");
//							al_shutdown_ttf_addon();
//						}
//						else
//							fprintf(stderr, "ERROR: Failed to initialize ttf addon\n");
//						al_shutdown_font_addon();
//						al_shutdown_image_addon();
//					}
//					else
//						fprintf(stderr, "ERROR: Failed to initialize image addon\n");
//					al_uninstall_mouse();
//				}
//				else
//					fprintf(stderr, "ERROR: Failed to install mouse\n");
//				al_uninstall_keyboard();
//			}
//			else
//				fprintf(stderr, "ERROR: Failed to to install keyboard\n");
//			al_shutdown_primitives_addon();
//		}
//		else
//			fprintf(stderr, "ERROR: Failed to load primitives addon \n");
//	}
//	else
//		fprintf(stderr, "ERROR: Failed to initialize allegro system\n");
//	return false;
//}
