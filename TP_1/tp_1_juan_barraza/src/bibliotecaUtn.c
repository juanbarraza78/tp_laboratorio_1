/*
 * Biblioteca.c
 *
 *  Created on: 13 abr. 2022
 *      Author: juanb
 */
#include <stdio.h>
#include <stdlib.h>

int utn_getInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int auxiliarResultado;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo<=maximo && reintentos >= 0)
	{
		do{
			printf("%s",mensaje);
			scanf("%d",&auxiliarResultado);
			if(auxiliarResultado >= minimo && auxiliarResultado <= maximo)
			{
				*pResultado = auxiliarResultado;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos --;
			}
	}while(reintentos >= 0);
	}
	return retorno;
}

int utn_getFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	int retorno = -1;
	float auxiliarResultado;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo<=maximo && reintentos >= 0)
	{
		do{
			printf("%s",mensaje);
			scanf("%f",&auxiliarResultado);
			if(auxiliarResultado >= minimo && auxiliarResultado <= maximo)
			{
				*pResultado = auxiliarResultado;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos --;
			}
	}while(reintentos >= 0);
	}
	return retorno;
}

int utn_getChar(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos)
{
	int retorno = -1;
	char auxiliarResultado;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo<=maximo && reintentos >= 0)
	{
		do{
			printf("%s",mensaje);
			fflush(stdin);
			scanf("%c",&auxiliarResultado);
			if(auxiliarResultado >= minimo && auxiliarResultado <= maximo)
			{
				*pResultado = auxiliarResultado;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos --;
			}
	}while(reintentos >= 0);
	}
	return retorno;
}







