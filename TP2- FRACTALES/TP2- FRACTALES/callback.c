#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "callback.h"
#define ERROR_CALLBACK 0
#define TERMINADOR_CALLBACK '\0'
#define MAX_STRING 100
#define OK 1


int AllMayus(char * string, char mayus[MAX_STRING]);


int ValidacionFractales(char * Key, char* Value, void * Data)
{
	char key_mayus[MAX_STRING];

	if (Key != NULL)
	{
		if (AllMayus(Key, key_mayus))
		{
			if (strcmp(key_mayus, "TYPE") == 0)
			{
				if (AllMayus(Value, key_mayus))
				{
					if (strcmp(key_mayus, "UNIFORME") == 0)
					{
						((parametros_t *)Data)->type = UNIFORME;
					}
					else if (strcmp(key_mayus, "POLIGONO") == 0)
					{
						((parametros_t *)Data)->type = POLIGONO;
					}
					else if (strcmp(key_mayus, "MANDELBROT") == 0)
					{
						((parametros_t *)Data)->type = MANDELBROT;
					}
					
				}
				else
				{
					return ERROR_CALLBACK;
				}

			}
			else if (strcmp(key_mayus, "RANGLE") == 0)
			{
				((parametros_t *)Data)->rAngle = atof(Value);
			}
			else if (strcmp(key_mayus, "LANGLE") == 0)
			{
				((parametros_t *)Data)->lAngle = atof(Value);
			}
			else if (strcmp(key_mayus, "XI") == 0)
			{
				((parametros_t *)Data)->xi = atof(Value);
			}
			else if (strcmp(key_mayus, "YI") == 0)
			{
				((parametros_t *)Data)->yi = atof(Value);
			}
			else if (strcmp(key_mayus, "XF") == 0)
			{
				((parametros_t *)Data)->xf = atof(Value);
			}
			else if (strcmp(key_mayus, "YF") == 0)
			{
				((parametros_t *)Data)->yf = atof(Value);
			}
			else if (strcmp(key_mayus, "LSTART") == 0)
			{
				((parametros_t *)Data)->lStart = atof(Value);
			}
			else if (strcmp(key_mayus, "LEND") == 0)
			{
				((parametros_t *)Data)->lEnd = atof(Value);
			}
			else if (strcmp(key_mayus, "LCONSTANT") == 0)
			{
				((parametros_t *)Data)->lConstant = atof(Value);
			}
			else if (strcmp(key_mayus, "NUMPOINTS") == 0)
			{
				((parametros_t *)Data)->numPoints = atoi(Value);
			}
			else
			{
				return ERROR_CALLBACK;
			}
			
		}
		else
		{
			return ERROR_CALLBACK;
		}

	}
	else
	{
		return ERROR_CALLBACK;
	}
	return OK;
}

int AllMayus(char * string, char mayus [MAX_STRING])
{
	int i = 0;
	while ((string[i]) != TERMINADOR_CALLBACK)
	{
		if (('a' <= string[i]) && ('z' >= string[i]))
		{
			mayus[i] = string[i] - ('a' - 'A');
		}
		else if (('A' <= string[i]) && ('Z' >= string[i]))
		{
			mayus[i] = string[i];
		}
		else if (('1' <= string[i]) && ('9' >= string[i])||(string[i]== '-'))

		{
			mayus[i] = string[i];
			

		}
		else if (string[i]== TERMINADOR_CALLBACK)
		{
			mayus[i] = TERMINADOR_CALLBACK;
		}
		else
		{
			return ERROR_CALLBACK;
		}
		i++;
	}
	mayus[i] = TERMINADOR_CALLBACK;
	return OK;
}