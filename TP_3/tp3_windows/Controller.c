#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "Controller.h"
#include "parser.h"



/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	FILE *pFile = NULL;
	if(path != NULL && pArrayListPassenger != NULL)
	{
		pFile = fopen(path, "r");
		if(pFile != NULL)
		{
			if(!parser_PassengerFromText(pFile, pArrayListPassenger))
			{
				retorno = 0;
				printf("Correcta lectura del archivo, el mismo se cerro.\n");
			}
			fclose(pFile);
		}
		else
		{
			printf("El archivo no existe");
		}

	}
    return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	FILE *pFile = NULL;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		pFile = fopen(path, "rb");
		if(pFile != NULL)
		{
			if(!parser_PassengerFromBinary(pFile, pArrayListPassenger))
			{
				retorno = 0;
				printf("Correcta lectura del archivo, el mismo se cerro.\n");
			}
			fclose(pFile);
		}
		else
		{
			printf("El archivo no existe");
		}
	}
    return retorno;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile = NULL;
	Passenger* auxPasageroPuntero = NULL;

	int auxId;
	char auxNombre[LEN_NOMBRE];
	char auxApellido[LEN_APELLIDO];
	float auxPrecio;
	int auxTipoPasajero;
	char auxCodigoVuelo[LEN_CODIGO];
	int auxEstadoVuelo;
	char auxTipoPasajeroStr[50];
	char auxEstadoVueloStr[50];

	int len;
	int contador = -1;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		pFile = fopen(path,"w");
		len = ll_len(pArrayListPassenger);
		if(pFile != NULL)
		{
			contador = 0;
			for(int i=0; i<len; i++)
			{
				auxPasageroPuntero= ll_get(pArrayListPassenger, i);
				if(auxPasageroPuntero != NULL)
				{
					if(!Passenger_getId(auxPasageroPuntero, &auxId) &&
						!Passenger_getNombre(auxPasageroPuntero, auxNombre) &&
						!Passenger_getApellido(auxPasageroPuntero, auxApellido) &&
						!Passenger_getPrecio(auxPasageroPuntero, &auxPrecio) &&
						!Passenger_getTipoPasajero(auxPasageroPuntero, &auxTipoPasajero) &&
						!Passenger_getCodigoVuelo(auxPasageroPuntero, auxCodigoVuelo) &&
						!Passenger_getEstadoVuelo(auxPasageroPuntero, &auxEstadoVuelo) &&
						!Passenger_convertirTipoPasajeroStr(auxTipoPasajero, auxTipoPasajeroStr) &&
						!Passenger_convertirEstadoVueloStr(auxEstadoVuelo, auxEstadoVueloStr))
					{
						fprintf(pFile,"%d,%s,%s,%f,%s,%s,%s\n",auxId,auxNombre,auxApellido,auxPrecio,auxCodigoVuelo,auxTipoPasajeroStr,auxEstadoVueloStr);
						contador++;
					}
				}
			}
			fclose(pFile);
		}
	}
    return contador;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile = NULL;
	Passenger* auxPasageroPuntero = NULL;
	int len;
	int contador = -1;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		pFile = fopen(path,"wb");
		len = ll_len(pArrayListPassenger);
		if(pFile != NULL)
		{
			contador = 0; // tengo que cambiarlo hay , no olvidarme de no poner el >=0
			for(int i=0; i<len; i++)
			{
				auxPasageroPuntero= ll_get(pArrayListPassenger, i);
				if(auxPasageroPuntero != NULL)
				{
					fwrite(auxPasageroPuntero,sizeof(Passenger),1,pFile);
					contador++;
				}
			}
			fclose(pFile);
		}
	}
    return contador;
}
