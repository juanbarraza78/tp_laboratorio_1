/*
 * C
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entrada_validaciones_datos.h"

/*
 * NUMEROS INT
 */

int myGets(char cadena[], int longitud)
{
	int retorno = -1;
	char bufferString[256];
	if(cadena != NULL && longitud > 0)
	{
		setbuf(stdout, NULL);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString)) - 1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString)) - 1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena,bufferString,longitud);
				retorno = 0;
			}
		}
	}
	return retorno;
}

int getInt(int* pResultado)
{
	int retorno = -1;
	char bufferString[50];

	if(pResultado != NULL &&
			myGets(bufferString,sizeof(bufferString)) == 0 &&
			esNumerica(bufferString,sizeof(bufferString)) == 1)
	{
		retorno = 0;
		*pResultado = atoi(bufferString);
	}

	return retorno;
}

int esNumerica(char* cadena, int limite)
{
	int retorno = 1;
	if(cadena != NULL)
	{
		for(int i = 0; i<limite && cadena[i] != '\0'; i++ )
		{
			if(cadena[0] == '-' || cadena[0] == '+')
			{
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int utn_getNumero(int *pResultado, char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;
	do
	{
		printf("%s",mensaje);
		if(getInt(&bufferInt) == 0 && bufferInt >= minimo && bufferInt <= maximo)
		{
			retorno = 0;
			*pResultado = bufferInt;
			break;
		}
		else
		{
			printf("%s",mensajeError);
		}
		reintentos --;
	}while(reintentos >= 0);
	return retorno;
}

/*
 * NUMEROS FLOAT
 */

int utn_getNumeroFlotante(float *pResultado, char mensaje[], char mensajeError[], float minimo, float maximo, int reintentos)
{
	int retorno = -1;
	float bufferfloat;
	do
	{
		printf("%s",mensaje);
		if(getFloat(&bufferfloat) == 0 && bufferfloat >= minimo && bufferfloat <= maximo)
		{
			retorno = 0;
			*pResultado = bufferfloat;
			break;
		}
		else
		{
			printf("%s",mensajeError);
		}
		reintentos --;
	}while(reintentos >= 0);
	return retorno;
}

int esNumeroFlotante(char* cadena, int limite)
{
	int retorno = 1;
	int contadorComa = 0;
	if(cadena != NULL)
	{
		for(int i = 0; i<limite && cadena[i] != '\0'; i++ )
		{
			if(cadena[0] == '-' || cadena[0] == '+')
			{
				continue;
			}
			if(cadena[i] == '.')
			{
				contadorComa++;
				if(contadorComa >= 2)
				{
					retorno = 0;
					break;
				}
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int getFloat(float* pResultado)
{
	int retorno = -1;
	char bufferString[50];

	if(pResultado != NULL &&
			myGets(bufferString,sizeof(bufferString)) == 0 &&
			esNumeroFlotante(bufferString,sizeof(bufferString)) == 1)
	{
		retorno = 0;
		*pResultado = atof(bufferString);
	}
	return retorno;
}

/*
 * EMAIL
 */

int utn_getEmail(char email[], int len, char mensaje[], char mensajeError[], int reintentos)
{
	int retorno = -1;
	char bufferString[256];
	do
		{
			printf("%s",mensaje);
			if(getEmail(bufferString,sizeof(bufferString)) == 0)
			{
				strncpy(email,bufferString,len);
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
			}
			reintentos --;
		}while(reintentos >= 0);
	return retorno;
}

int esMail(char* cadena, int limite)
{
	int retorno = 1;
	int contadorArobas = 0;
	if(cadena != NULL && limite > 0)
	{
		for(int i = 0; i<limite && cadena[i] != '\0'; i++ )
		{
			if(cadena[i] == '@')
			{
				contadorArobas++;
				if(contadorArobas>1)
				{
					retorno = 0;
					break;
				}
			}
			if((cadena[i] < 'a' || cadena[i] > 'z') &&
					(cadena[i] < 'A' || cadena[i] > 'Z') &&
					(cadena[i] < '0' || cadena[i] > '9') &&
					cadena[i] !='.' &&
					cadena[i] !='@' &&
					cadena[i] !='_' &&
					cadena[i] !='-' )
			{
				retorno = 0;
				break;
			}

		}
	}
	return retorno;
}

int getEmail(char email[], int len)
{
	int retorno = -1;
	char bufferString[256];

	if(email != NULL &&
			len > 0 &&
			myGets(bufferString,sizeof(bufferString)) == 0 &&
			esMail(bufferString,sizeof(bufferString)) == 1 )
	{
		retorno = 0;
		strncpy(email,bufferString,len);
	}
	return retorno;
}

/*
 * NOMBRE
 */

int utn_getNombre(char nombre[], int len, char mensaje[], char mensajeError[], int reintentos)
{
	int retorno = -1;
	char bufferString[256];
	do
		{
			printf("%s",mensaje);
			if(getNombre(bufferString,sizeof(bufferString)) == 0)
			{
				strncpy(nombre,bufferString,len);
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
			}
			reintentos --;
		}while(reintentos >= 0);
	return retorno;
}

int esNombre(char* cadena, int limite)
{
	int retorno = 1;
	if(cadena != NULL && limite > 0)
	{
		for(int i = 0; i<limite && cadena[i] != '\0'; i++ )
		{
			if((cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z'))
			{
				retorno = 0;
				break;
			}

		}
	}
	return retorno;
}

int getNombre(char nombre[], int len)
{
	int retorno = -1;
	char bufferString[256];

	if(nombre != NULL &&
			len > 0 &&
			myGets(bufferString,sizeof(bufferString)) == 0 &&
			esNombre(bufferString,sizeof(bufferString)) == 1 )
	{
		retorno = 0;
		strncpy(nombre,bufferString,len);
	}
	return retorno;
}
/*
 * CUIL
 */

int utn_getCuil(int *pResultado ,char mensaje[], char mensajeError[], int reintentos) //funca mal )=
{
	int retorno = -1;
	int bufferInt;
	do
		{
			printf("%s",mensaje);
			if(getCuil(&bufferInt) == 0)
			{
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
			}
			reintentos --;
		}while(reintentos >= 0);
	return retorno;
}

int esCuil(char* cadena, int limite)
{
	int retorno = 1;
	if(cadena != NULL)
	{
		if(strlen(cadena) != 11)
		{
			retorno = 0;
		}
		for(int i = 0; i<limite && cadena[i] != '\0'; i++ )
		{
			if(cadena[i] < '0' || cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int getCuil(int *pCuil)
{
	int retorno = -1;
	char bufferString[13];

	if(pCuil != NULL &&
			myGets(bufferString,sizeof(bufferString)) == 0 &&
			esCuil(bufferString,sizeof(bufferString)) == 1 )
	{
		retorno = 0;
		*pCuil = atoi(bufferString);
	}
	return retorno;
}

/*
 * CODIGO
 */

int utn_getCodigo(char codigo[], int len, char mensaje[], char mensajeError[], int reintentos)
{
	int retorno = -1;
	char bufferString[256];
	do
		{
			printf("%s",mensaje);
			if(getCodigo(bufferString,sizeof(bufferString)) == 0)
			{
				strncpy(codigo,bufferString,len);
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
			}
			reintentos --;
		}while(reintentos >= 0);
	return retorno;
}

int esCodigo(char* cadena, int limite)
{
	int retorno = 1;
	if(cadena != NULL && limite > 0)
	{
		for(int i = 0; i<limite && cadena[i] != '\0'; i++ )
		{
			if((cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i] < '1' || cadena[i] > '9') && cadena[i] != ' ')
			{
				retorno = 0;
				break;
			}

		}
	}
	return retorno;
}

int getCodigo(char codigo[], int len)
{
	int retorno = -1;
	char bufferString[256];

	if(codigo != NULL &&
			len > 0 &&
			myGets(bufferString,sizeof(bufferString)) == 0 &&
			esCodigo(bufferString,sizeof(bufferString)) == 1 )
	{
		retorno = 0;
		strncpy(codigo,bufferString,len);
	}
	return retorno;
}
