/*
 *      Author: juanb
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "informes.h"
#include "utn.h"
#include "Passenger.h"

//TODOS LOS DE FILTRAR

int Passenger_sortApellido(void* parametro1, void* parametro2)
{
    int retorno = -1;
    char auxApellido1[LEN_APELLIDO];
    char auxApellido2[LEN_APELLIDO];

    if(parametro1 != NULL && parametro2 != NULL)
    {
    	Passenger_getApellido(parametro1, auxApellido1);
    	Passenger_getApellido(parametro2, auxApellido2);

		if(strcmp(auxApellido1,auxApellido2)>0)
		{
			retorno = 1;
		}
    }

    return retorno;
}
int Passenger_sortId(void* parametro1, void* parametro2)
{
    int retorno = -1;
    int auxId1;
    int auxId2;

    if(parametro1!=NULL && parametro2!=NULL)
    {
    	Passenger_getId(parametro1, &auxId1);
    	Passenger_getId(parametro2, &auxId2);
        if(auxId1 > auxId2)
        {
        	retorno = 1;
        }

    }
    return retorno;
}

int Passenger_sortTipoPasajero(void* parametro1, void* parametro2)
{
    int retorno = -1;
    int auxTipoPasajero1;
    int auxTipoPasajero2;

    if(parametro1!=NULL && parametro2!=NULL)
    {
    	Passenger_getTipoPasajero(parametro1, &auxTipoPasajero1);
    	Passenger_getTipoPasajero(parametro2, &auxTipoPasajero2);
        if(auxTipoPasajero1 > auxTipoPasajero2)
        {
        	retorno = 1;
        }

    }
    return retorno;
}

int Passenger_sortEstadoVuelo(void* parametro1, void* parametro2)
{
    int retorno = -1;
    int auxEstadoVuelo1;
    int auxEstadoVuelo2;

    if(parametro1!=NULL && parametro2!=NULL)
    {
    	Passenger_getEstadoVuelo(parametro1, &auxEstadoVuelo1);
    	Passenger_getEstadoVuelo(parametro2, &auxEstadoVuelo2);
        if(auxEstadoVuelo1 > auxEstadoVuelo2)
        {
        	retorno = 1;
        }

    }
    return retorno;
}

int Passenger_sortCodigoVuelo(void* parametro1, void* parametro2)
{
    int retorno = -1;
    char auxCodigoVuelo1 [LEN_CODIGO];
    char auxCodigoVuelo2 [LEN_CODIGO];

    if(parametro1 != NULL && parametro2 != NULL)
    {
    	Passenger_getCodigoVuelo(parametro1, auxCodigoVuelo1);
    	Passenger_getCodigoVuelo(parametro2, auxCodigoVuelo2);

		if(strcmp(auxCodigoVuelo1,auxCodigoVuelo2)>0)
		{
			retorno = 1;
		}
    }
    return retorno;
}

int ll_filtrarYMostrar(LinkedList* this, int (*pFunc)(void*,int))
{
    int returnAux = -1;
    LinkedList* auxLinkedList = ll_newLinkedList(); // creo una lista auxiliar
    int longitud;
    Passenger* auxPassenger = NULL;

    if(this != NULL && pFunc != NULL)
    {
    	longitud = ll_len(this);
    	if(longitud >= 0)
    	{
    		for(int i = 0; i<longitud; i++)
    		{
    			auxPassenger = ll_get(this, i);
    			if(pFunc(auxPassenger,1) == 0 && !ll_add(auxLinkedList, auxPassenger))
    			{
    				returnAux = 0;
    			}
    		}
    	}
    }
    Passenger_imprimirArray(auxLinkedList);
    return returnAux;
}

int Passenger_filtrarEstadoVuelo(void* parametro, int estadoVuelo)
{
	int retorno = -1;
	int auxEstadoVuelo;
	if(parametro != NULL)
	{
		Passenger_getEstadoVuelo(parametro, &auxEstadoVuelo);
		if(auxEstadoVuelo == estadoVuelo)
		{
			retorno = 0;
		}
	}
	return retorno;
}
