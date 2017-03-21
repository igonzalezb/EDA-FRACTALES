//******************************************************************************//
// Bibliteca para parseo de la linea de comando.                                //
//permite analizar parametro y opciones. llama a un calback                     //
//para evaluar la validez de lo enviado, si devuelve 0, hay un herror.          //
//utiliza el puntero a void para permitirle al callback devolver informacion    //
//                                                                              //
//Creadores: Malena Muller(57057), Paulo Navarro(57775) y                       //
//Pierdominici Matias (57498)                                                    //
//Version: 12/03/2017                                                           //
//Git: https://github.com/mpierdominici/TP1-EDA.git                             //
//******************************************************************************//







#include <stdio.h>
#include <stdint.h>
#include "PARSER.h"
#define ERROR 0//codigo de error que devuelve el calback
#define MIN_ARGC 2 //cantidad  minima de argumentos a recivir por cmd
#define TRUE 1
#define FALSE 0
#define KEY '-'//caracter previo al key
#define TERMINADOR '\0' //caracter usado como terminador de strings





int parseCmdLine(int argc, char *argv[], pCallback p, void *userData)
{

	uint8_t end_runing = FALSE;//cariable usada para detener el proceso de busqueda de comandos
	int16_t counter_string = TRUE;//contador que apunta al string enviado por consola deseado, inicializado en 1(string 0 nombre del programa)
	int16_t return_value = TRUE;//variable que contiene lo que devuelve la funcion parseCmdLine
	uint8_t * key = NULL;//variable que almacena el key
	int16_t contador_opciones_parametros = FALSE;//contador que almacena la cantidad de opciones y parametros correctamanete ingresados
	if (argc<MIN_ARGC)//evaluo si hay sufucientes argumentos
	{
		return_value = PARSER_RETURN_ERROR;//en caso de que no los haya, detengo la ejecucion y devuelvo error
	}
	else
	{
		while (!end_runing)
		{
			if ((counter_string<argc) && ((*(argv[counter_string])) == KEY))//evaluo si recivo un key
			{
				if (((*((argv[counter_string]) + 1)) != TERMINADOR))//evaluo si el key esta acompañado por el valor
				{
					key = (uint8_t *)((argv[counter_string]) + 1);//almaceno el puntero a en key para su posterior uso
					counter_string++;//incremento el contador de string para ver cual es el proximo string
					if ((*(argv[counter_string])) != TERMINADOR)//evaluo si hay string despues del key
					{
						if ((counter_string<argc) && (((*p)(key, argv[counter_string], userData)) != ERROR))//llamo al calback con los parametros obtenidos, y evaluo si devuelve error
						{

							contador_opciones_parametros++;//como encontre paramteros, entonces sumo uno al contador
							counter_string++;//posiciono el contador de string apuntando al nuevo comando
						}
						else//si ocurre un erro desde el calback, fin de la ejecucion
						{
							end_runing = TRUE;
							return_value = PARSER_RETURN_ERROR;
						}

					}
					else
					{
						end_runing = TRUE;
						return_value = PARSER_RETURN_ERROR;
					}
				}
				else//en caso que no haya string despues del key, fin de la ejecucion
				{
					end_runing = TRUE;
					return_value = PARSER_RETURN_ERROR;
				}

			}
			else if ((counter_string<argc) && ((*(argv[counter_string])) != TERMINADOR))//en caso de que no reciva un key, evaluo si recivo una ocpion
			{
				if (((*p)(NULL, argv[counter_string], userData)) != ERROR)//llamo al calback con los parametros obtenidos, y evaluo si devuelve error
				{

					contador_opciones_parametros++;
					counter_string++;
				}
				else
				{
					end_runing = TRUE;
					return_value = PARSER_RETURN_ERROR;
				}

			}
			else if (!(counter_string<argc))//cuando ya se leyeron todos los argumentos y no hubo error
			{
				end_runing = TRUE;
				return_value = contador_opciones_parametros;
			}
			else
			{
				end_runing = TRUE;
				return_value = PARSER_RETURN_ERROR;
			}
		}




	}

	return return_value;






}