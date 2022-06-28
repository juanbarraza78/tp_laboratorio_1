/*
 * Passenger.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Passenger.h"
#include "utn.h"
#include "LinkedList.h"

/** \brief reserva espacio de memoria a un pasajero.
 * \return Passenger* retorna la direccion del espacio de memoria si encontro y NULL si no encontro
 *
 */
Passenger* Passenger_new()
{
	Passenger* auxPasageroPuntero = NULL;
	auxPasageroPuntero = (Passenger*) malloc(sizeof(Passenger)*1);
	return auxPasageroPuntero;
}

/** \brief reserva espacio de memoria a un pasajero y setea con los valores dados por parametro en formato str.
 *
 * \param idStr char* cadena para setear el id
 * \param nombre char* cadena para setear el nombre
 * \param apellido char* cadena para setear el apellido
 * \param precioStr char* cadena para setear el precioStr
 * \param tipoPasajeroStr char* cadena para setear el tipoPasajero
 * \param codigoVuelo char* cadena para setear el codigoVuelo
 * \param estadoVueloStr char* cadena para setear el estadoVuelo
 * \return Passenger* retorna la direccion del espacio de memoria si encontro y NULL si no encontro
 *
 */
Passenger* Passenger_newParametrosStr(char* idStr, char* nombre, char* apellido, char* precioStr,
		                              char* tipoPasajeroStr, char* codigoVuelo, char* estadoVueloStr)
{
	Passenger* auxPasageroPuntero = NULL;
	auxPasageroPuntero = Passenger_new();
	if(auxPasageroPuntero != NULL && idStr != NULL && nombre != NULL && apellido != NULL && precioStr != NULL &&
	   tipoPasajeroStr != NULL && codigoVuelo != NULL && estadoVueloStr != NULL)
	{
		if(Passenger_setIdStr(auxPasageroPuntero, idStr) || Passenger_setNombre(auxPasageroPuntero, nombre) ||
		   Passenger_setApellido(auxPasageroPuntero, apellido) || Passenger_setPrecioStr(auxPasageroPuntero, precioStr) ||
		   Passenger_setTipoPasajeroStr(auxPasageroPuntero, tipoPasajeroStr) || Passenger_setCodigoVuelo(auxPasageroPuntero, codigoVuelo) ||
		   Passenger_setEstadoVueloStr(auxPasageroPuntero, estadoVueloStr))
		{
			Passenger_delete(auxPasageroPuntero);
			auxPasageroPuntero = NULL;
		}
	}
	return auxPasageroPuntero;
}

/** \brief reserva espacio de memoria a un pasajero y setea con los valores dados por parametro.
 *
 * \param id int valor para setear el id
 * \param nombre char* cadena para setear el nombre
 * \param apellido char* cadena para setear el apellido
 * \param precio float valor para setear el precioStr
 * \param tipoPasajero int valor para setear el tipoPasajero
 * \param codigoVuelo char* cadena para setear el codigoVuelo
 * \param estadoVuelo int valor para setear el estadoVuelo
 * \return Passenger* retorna la direccion del espacio de memoria si encontro y NULL si no encontro
 *
 */
Passenger* Passenger_newParametros(int id, char* nombre, char* apellido, float precio,
		                              int tipoPasajero, char* codigoVuelo, int estadoVuelo)
{
	Passenger* auxPasageroPuntero = NULL;
	auxPasageroPuntero = Passenger_new();
	if(auxPasageroPuntero != NULL && nombre != NULL && apellido != NULL && codigoVuelo != NULL)
	{
		if(Passenger_setId(auxPasageroPuntero, id) || Passenger_setNombre(auxPasageroPuntero, nombre) ||
		   Passenger_setApellido(auxPasageroPuntero, apellido) || Passenger_setPrecio(auxPasageroPuntero, precio) ||
		   Passenger_setTipoPasajero(auxPasageroPuntero, tipoPasajero) || Passenger_setCodigoVuelo(auxPasageroPuntero, codigoVuelo) ||
		   Passenger_setEstadoVuelo(auxPasageroPuntero, estadoVuelo))
		{
			Passenger_delete(auxPasageroPuntero);
			auxPasageroPuntero = NULL;
		}
	}
	return auxPasageroPuntero;
}

/** \brief elimina un pasajero.
 *
 * \param this Passenger* dirrecion del pasajero a borrar
 * \return void
 *
 */
void Passenger_delete(Passenger* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

/**************************************************************************************/

/** \brief lee un archivo scv y obtiene un id.
 *
 * \param path char* path del archivo.
 * \return Passenger* retorna -1 si no funciono correctamente o un id si se encuentra en el archivo.
 *
 */
int  Passenger_loadId(char* path)
{
	FILE* pFile = NULL;
	int cantidad;
	char auxIdStr[1000];
	int retorno = -1;

	if(path != NULL)
	{
		pFile = fopen(path,"r");
		if(pFile != NULL)
		{
			cantidad = fscanf(pFile, "%[^\n]\n",auxIdStr);
			if(cantidad == 1 && esNumerica(auxIdStr, 1000))
			{
				retorno = atoi(auxIdStr);
			}
			fclose(pFile);
		}
	}
	return retorno;
}

/** \brief guarda un id en un archivo scv.
 *
 * \param path char* path del archivo.
 * \param id int
 * \return int retorna -1 si no funciono correctamente o 0 si pudo guardar el id
 *
 */
int Passenger_saveId(char* path,int id)
{
	int retorno = -1;
	FILE* pFile = NULL;
	if(path != NULL && id >= 0)
	{
		pFile = fopen(path,"w");
		if(pFile != NULL)
		{
			fprintf(pFile,"%d",id);
			fclose(pFile);
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief carga y guarda un id en un archivo scv.
 *
 * \param path char* path del archivo.
 * \return int retorna -1 si no funciono correctamente o retorna el id mas 1
 *
 */
int  Passenger_idMaximo(char* path)
{
	int idAux;
	int retorno = -1;
	if(path != NULL)
	{
		idAux = Passenger_loadId("id.csv");
		if(idAux >= 0)
		{
			idAux++;
			if(!Passenger_saveId("id.csv", idAux))
			{
				retorno = idAux;
			}
		}
	}
	return retorno;
}

/**************************************************************************************/

/** \brief borra un pasajero en la posicion indicada.
 *
 * \param listaPasajeros LinkedList* es la linkedList
 * \param index int posicion a eliminar
 * \return int retorna 0 si funciono correctamente o retorna -1 sino
 *
 */
int Passenger_deleteIndexArray(LinkedList* listaPasajeros, int index)
{
	int retorno = -1;
	Passenger* pAuxPassager = NULL;
	if(listaPasajeros != NULL && index >= 0)
	{
		pAuxPassager = ll_get(listaPasajeros, index);
		if(pAuxPassager != NULL && !ll_remove(listaPasajeros, index))
		{
			Passenger_delete(pAuxPassager);
			retorno = 0;
		}

	}
	return retorno;
}

/** \brief vincula el campo tipoPasajero int a una cadena de texto
 *
 * \param tipoPasajero int es el campo del elemento pasajero
 * \param tipoPasajeroStr char* el resultado en formato str
 * \return int retorna 0 si funciono correctamente o retorna -1 sino
 *
 */
int Passenger_convertirTipoPasajeroStr(int tipoPasajero, char* tipoPasajeroStr)
{
	int retorno = -1;
	switch(tipoPasajero)
	{
	case 1:
		strcpy(tipoPasajeroStr,"FirstClass\0");
		retorno = 0;
		break;
	case 2:
		strcpy(tipoPasajeroStr,"ExecutiveClass\0");
		retorno = 0;
		break;
	case 3:
		strcpy(tipoPasajeroStr,"EconomyClass\0");
		retorno = 0;
		break;
	}
	return retorno;
}

/** \brief vincula el campo estadoVuelo int a una cadena de texto
 *
 * \param estadoVuelo int es el campo del elemento pasajero
 * \param estadoVueloStr char* el resultado en formato str
 * \return int retorna 0 si funciono correctamente o retorna -1 sino
 *
 */
int Passenger_convertirEstadoVueloStr(int estadoVuelo, char* estadoVueloStr)
{
	int retorno = -1;
	switch(estadoVuelo)
	{
	case 1:
		strcpy(estadoVueloStr,"Aterrizado\0");
		retorno = 0;
		break;
	case 2:
		strcpy(estadoVueloStr,"En Horario\0");
		retorno = 0;
		break;
	case 3:
		strcpy(estadoVueloStr,"En Vuelo\0");
		retorno = 0;
		break;
	case 4:
		strcpy(estadoVueloStr,"Demorado\0");
		retorno = 0;
		break;
	}
	return retorno;
}

/** \brief imprime un elemento pasajero con todos sus campos
 *
 * \param punteroPasagero Passenger* es el puntero al elemento pasajero a imprimir
 *
 */
void Passenger_imprimirUno(Passenger* punteroPasagero)
{
	int auxId;
	char auxNombre[LEN_NOMBRE];
	char auxApellido[LEN_APELLIDO];
	float auxPrecio;
	int auxTipoPasajero;
	char auxCodigoVuelo[LEN_CODIGO];
	int auxEstadoVuelo;

	char auxTipoPasajeroStr[50];
	char auxEstadoVueloStr[50];

	if(punteroPasagero != NULL)
	{
		if(	!Passenger_getId(punteroPasagero, &auxId) &&
			!Passenger_getNombre(punteroPasagero, auxNombre) &&
			!Passenger_getApellido(punteroPasagero, auxApellido) &&
			!Passenger_getPrecio(punteroPasagero, &auxPrecio) &&
			!Passenger_getTipoPasajero(punteroPasagero, &auxTipoPasajero) &&
			!Passenger_getCodigoVuelo(punteroPasagero, auxCodigoVuelo) &&
			!Passenger_getEstadoVuelo(punteroPasagero, &auxEstadoVuelo) &&
			!Passenger_convertirTipoPasajeroStr(auxTipoPasajero, auxTipoPasajeroStr) &&
			!Passenger_convertirEstadoVueloStr(auxEstadoVuelo, auxEstadoVueloStr))
		{
			printf("|%*d|%*s|%*s|%*.2f|%*s|%*s|%*s|\n", -15, auxId, -15, auxNombre, -15, auxApellido, -16, auxPrecio, -16, auxTipoPasajeroStr, -15, auxCodigoVuelo, -15, auxEstadoVueloStr);
		}
	}
}

/** \brief imprime una lista de pasageros
 *
 * \param listaPasajeros LinkedList* es la linkedlist a imprimir
 * \return int retorna 0 si funciono correctamente o retorna -1 sino
 *
 */
int Passenger_imprimirArray(LinkedList* listaPasajeros)
{
	int retorno = -1;
	int longitud;
	Passenger* pAuxPassager = NULL;

	if(listaPasajeros != NULL)
	{
		retorno = 0;
		longitud = ll_len(listaPasajeros);
		printf("+-----------------------------------------------------------------------------------------------------------------+");
		printf("\n|%*s|%*s|%*s|%*s|%*s|%*s|%*s|\n", -15,"ID DEL PASAJERO", -15, "NOMBRE", -15, "APELLIDO", -15, "PRECIO DEL VUELO", -15, "TIPO DE PASAJERO", -15, "CODIGO DE VUELO", -15, "ESTADO DE VUELO");
		printf("+---------------+---------------+---------------+----------------+----------------+-------------------------------+\n");
		if(longitud >= 0)
		{
			for(int i = 0; i < longitud ; i++)
			{
				pAuxPassager =ll_get(listaPasajeros, i);
				if(pAuxPassager != NULL)
				{
					Passenger_imprimirUno(pAuxPassager);
				}
			}
		}
	}
	return retorno;
}

/** \brief encuentra la posicion de un pajagero por medio de un id
 *
 * \param listaPasajeros LinkedList* es la linkedlist
 * \param id int es el id a encontrar
 * \return int retorna el index encontrado si funciono correctamente o retorna -1 sino
 *
 */
int Passenger_buscarPorIdArray(LinkedList* listaPasajeros, int id)
{
	int retorno = -1;
	int longitud;
	int auxId;
	Passenger* pAuxPassager = NULL;

	if(listaPasajeros != NULL && id >= 0)
	{
		longitud = ll_len(listaPasajeros);
		if(longitud >= 0)
		{
			for(int i = 0; i < longitud ; i++)
			{
				pAuxPassager = ll_get(listaPasajeros, i);
				Passenger_getId(pAuxPassager, &auxId);

				if(pAuxPassager != NULL && auxId == id)
				{
					retorno = i;
					break;
				}
			}
		}
	}
	return retorno;
}

/** \brief crea el espacio de memoria de un pasajero y lo agrega a una linkedlist
 *
 * \param listaPasajeros LinkedList* es la linkedlist
 * \param id int id del pasajero
 * \param nombre char* nombre del pasajero
 * \param apellido char* apellido del pasajero
 * \param precio float precio del pasajero
 * \param tipoPasajero int tipo de pasajero
 * \param codigoVuelo char* codigo del pasajero
 * \param estadoVuelo int estado del vuelo del pasajero
 * \return int retorna 0 si funciono correctamente o retorna -1 sino
 *
 */
int Passenger_agregarArray(LinkedList* listaPasajeros, int id, char* nombre, char* apellido, float precio,
		                  int tipoPasajero, char* codigoVuelo, int estadoVuelo)
{
	int retorno = -1;
	Passenger* pAuxPassager = NULL;
	if(listaPasajeros != NULL && id >= 0 && nombre != NULL && apellido != NULL && codigoVuelo != NULL)
	{
		pAuxPassager = Passenger_newParametros(id, nombre, apellido, precio, tipoPasajero, codigoVuelo, estadoVuelo);
		if(pAuxPassager != NULL)
		{
			if(!ll_add(listaPasajeros, pAuxPassager))
			{
				retorno = 0;
			}
			else
			{
				Passenger_delete(pAuxPassager);
			}
		}
	}
	return retorno;
}

/** \brief elimina a un pasajero por medio de un id
 *
 * \param listaPasajeros LinkedList* es la linkedlist
 * \param id int es el id a eliminar
 * \return int retorna 0 si funciono correctamente o retorna -1 sino
 *
 */
int Passenger_borrarPorIdArray(LinkedList* listaPasajeros, int id)
{
	int retorno = -1;
	int auxIndexBorrar;
	if(listaPasajeros != NULL && id >= 0)
	{
		auxIndexBorrar = Passenger_buscarPorIdArray(listaPasajeros, id);
		if(auxIndexBorrar >= 0)
		{
			if(!Passenger_deleteIndexArray(listaPasajeros, auxIndexBorrar))
			{
				retorno = 0;
			}
		}
	}
	return retorno;
}

/** \brief modifica algun campo de un pasajero por medio de un id
 *
 * \param listaPasajeros LinkedList* es la linkedlist
 * \param id int es el id a modificar
 * \return int retorna 0 si funciono correctamente o retorna -1 sino
 *
 */
int Passenger_modificarPorIdArray(LinkedList* listaPasajeros, int id)
{
	int retorno = -1;
	int auxOpcion;
	int auxIndexModificar;
	Passenger* pAuxPassager = NULL;

	char auxNombre[LEN_NOMBRE];
	char auxApellido[LEN_APELLIDO];
	float auxPrecio;
	int auxTipoPasajero;
	char auxCodigoVuelo[LEN_CODIGO];
	int auxEstadoVuelo;

	if(listaPasajeros != NULL && id >= 0)
	{
		auxIndexModificar = Passenger_buscarPorIdArray(listaPasajeros, id);
		if(auxIndexModificar >= 0)
		{
			pAuxPassager = ll_get(listaPasajeros, auxIndexModificar);
			if(pAuxPassager != NULL)
			{
				Passenger_imprimirUno(pAuxPassager);
				if(!utn_getNumero(&auxOpcion, "Que campo quiere modificar?\n 1)Nombre\n2)Apellido\n3)Precio\n4)Codigo\n5)Tipo\n6)Estado",
									"Error, opcion invalida\n", 1, 6, 1))
				{
					switch(auxOpcion)
					{
					case 1:
						if(!utn_getNombre(auxNombre, LEN_NOMBRE, "Ingrese el nombre del pasajero:\n", "Error, Nombre no valido\n", 0) &&
		                   !Passenger_setNombre(pAuxPassager, auxNombre))
						{
							retorno = 0;
						}
						break;
					case 2:
						if(!utn_getNombre(auxApellido, LEN_APELLIDO, "Ingrese el apellido del pasajero:\n", "Error, apellido no valido\n", 0) &&
						   !Passenger_setApellido(pAuxPassager, auxApellido))
						{
							retorno = 0;
						}
						break;
					case 3:
						if(!utn_getNumeroFlotante(&auxPrecio, "Ingrese el precio del vuelo:\n", "Error, precio no valido\n", 0, 100000, 0) &&
						   !Passenger_setPrecio(pAuxPassager, auxPrecio))
						{
							retorno = 0;
						}
						break;
					case 4:
						if(!utn_getNumero(&auxTipoPasajero, "Ingrese tipo de pasajero:\nFirst Class[1] - Executive Class[2] - Economy Class[3]\n", "Error, opcion no valida\n", 1, 3, 0) &&
						   !Passenger_setTipoPasajero(pAuxPassager, auxTipoPasajero))
						{
							retorno = 0;
						}
						break;
					case 5:
						if(!utn_getCodigo(auxCodigoVuelo, LEN_CODIGO, "Ingrese codigo del vuelo:\n", "Error, codigo no valido\n", 0) &&
						   !Passenger_setCodigoVuelo(pAuxPassager, auxCodigoVuelo))
						{
							retorno = 0;
						}
						break;
					case 6:
						if(!utn_getNumero(&auxEstadoVuelo, "Ingrese el estado del vuelo:\nAterrizado[1] - En Horario[2] - En Vuelo[3] - Demorado[4]\n", "Error, codigo no valido\n", 1, 4, 0) &&
						   !Passenger_setEstadoVuelo(pAuxPassager, auxEstadoVuelo))
						{
							retorno = 0;

						}
						break;
					}
				}
			}
		}
	}
	return retorno;
}

/**************************************************************************************/

/** \brief compara el id de dos pasajeros
 *
 * \param parametro1 void* primer pasajero
 * \param parametro2 void* segundo pasajero
 * \return int retorna 1 si el id es mayor que del segundo, 0 si son iguales y -1 si no se cumple ninguna de las 2
 *
 */
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
        else if(auxId1 ==auxId2)
        {
        	retorno = 0;
        }
    }
    return retorno;
}

/** \brief compara el nombre de dos pasajeros
 *
 * \param parametro1 void* primer pasajero
 * \param parametro2 void* segundo pasajero
 * \return int retorna 1 si el nombre es mayor que del segundo, 0 si son iguales y -1 si no se cumple ninguna de las 2
 *
 */
int Passenger_sortNombre(void* parametro1, void* parametro2)
{
    int retorno = -1;
    char auxNombre1[LEN_NOMBRE];
    char auxNombre2[LEN_NOMBRE];

    if(parametro1 != NULL && parametro2 != NULL)
    {
    	Passenger_getNombre(parametro1, auxNombre1);
    	Passenger_getNombre(parametro2, auxNombre2);

		if(stricmp(auxNombre1,auxNombre2)>0)
		{
			retorno = 1;
		}
        else if(strcmp(auxNombre1,auxNombre2) == 0)
        {
        	retorno = 0;
        }
    }

    return retorno;
}

/** \brief compara el apellido de dos pasajeros
 *
 * \param parametro1 void* primer pasajero
 * \param parametro2 void* segundo pasajero
 * \return int retorna 1 si el apellido es mayor que del segundo, 0 si son iguales y -1 si no se cumple ninguna de las 2
 *
 */
int Passenger_sortApellido(void* parametro1, void* parametro2)
{
    int retorno = -1;
    char auxApellido1[LEN_APELLIDO];
    char auxApellido2[LEN_APELLIDO];

    if(parametro1 != NULL && parametro2 != NULL)
    {
    	Passenger_getApellido(parametro1, auxApellido1);
    	Passenger_getApellido(parametro2, auxApellido2);

		if(stricmp(auxApellido1,auxApellido2)>0)
		{
			retorno = 1;
		}
        else if(strcmp(auxApellido1,auxApellido2) == 0)
        {
        	retorno = 0;
        }
    }
    return retorno;
}

/** \brief compara el precio de dos pasajeros
 *
 * \param parametro1 void* primer puntero pasajero
 * \param parametro2 void* segundo puntero pasajero
 * \return int retorna 1 si el precio del primero es mayor que del segundo, 0 si son iguales y -1 si no se cumple ninguna de las 2
 *
 */
int Passenger_sortprecio(void* parametro1, void* parametro2)
{
    int retorno = -1;
    float precio1;
    float precio2;

    if(parametro1!=NULL && parametro2!=NULL)
    {
    	Passenger_getPrecio(parametro1, &precio1);
    	Passenger_getPrecio(parametro2, &precio2);
        if(precio1 > precio2)
        {
        	retorno = 1;
        }
        else if(precio1 == precio2)
        {
        	retorno = 0;
        }
    }
    return retorno;
}

/** \brief compara el tipo de pasajero de dos pasajeros
 *
 * \param parametro1 void* primer puntero pasajero
 * \param parametro2 void* segundo puntero pasajero
 * \return int retorna 1 si el tipo de pasajero del primero es mayor que del segundo, 0 si son iguales y -1 si no se cumple ninguna de las 2
 *
 */
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
        else if(auxTipoPasajero1 == auxTipoPasajero2)
        {
        	retorno = 0;
        }
    }
    return retorno;
}

/** \brief compara el codigo de vuelo de dos pasajeros
 *
 * \param parametro1 void* primer puntero pasajero
 * \param parametro2 void* segundo puntero pasajero
 * \return int retorna 1 si el codigo de vuelo del primero es mayor que del segundo, 0 si son iguales y -1 si no se cumple ninguna de las 2
 *
 */
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
        else if(strcmp(auxCodigoVuelo1,auxCodigoVuelo2) == 0)
        {
        	retorno = 0;
        }
    }
    return retorno;
}

/** \brief compara el estado de vuelo de dos pasajeros
 *
 * \param parametro1 void* primer puntero pasajero
 * \param parametro2 void* segundo puntero pasajero
 * \return int retorna 1 si el estado de vuelo del primero es mayor que del segundo, 0 si son iguales y -1 si no se cumple ninguna de las 2
 *
 */
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
        else if(auxEstadoVuelo1 == auxEstadoVuelo2)
        {
        	retorno = 0;
        }

    }
    return retorno;
}

/**************************************************************************************/

/** \brief convierte una cadena de texto vinculada al campo tipo de pasajero a un numero
 *
 * \param tipoPasajeroStr char* cadena de texto puede ser: "FirstClass","ExecutiveClass","EconomyClass"
 * \return int retorna 0 si funciono correctamente o -1 sino
 *
 */
int Passenger_convertirTipoPasajeroint(char* tipoPasajeroStr)
{
	int retorno = -1;
	if(tipoPasajeroStr != NULL)
	{
		if(strcmp(tipoPasajeroStr,"FirstClass") == 0)
		{
			strcpy(tipoPasajeroStr,"1\0");
			retorno = 0;
		}
		else if(strcmp(tipoPasajeroStr,"ExecutiveClass") == 0)
		{
			strcpy(tipoPasajeroStr,"2\0");
			retorno = 0;
		}
		else if(strcmp(tipoPasajeroStr,"EconomyClass") == 0)
		{
			strcpy(tipoPasajeroStr,"3\0");
			retorno = 0;
		}

	}
	return retorno;
}

/** \brief convierte una cadena de texto vinculada al campo estado de vuelo a un numero
 *
 * \param estadoVueloStr char* cadena de texto puede ser: "Aterrizado","En Horario","En Vuelo","Demorado"
 * \return int retorna 0 si funciono correctamente o -1 sino
 *
 */
int Passenger_convertirEstadoVueloSint(char* estadoVueloStr)
{
	int retorno = -1;
	if(strcmp(estadoVueloStr,"Aterrizado") == 0)
	{
		strcpy(estadoVueloStr,"1\0");
		retorno = 0;
	}
	else if(strcmp(estadoVueloStr,"En Horario") == 0)
	{
		strcpy(estadoVueloStr,"2\0");
		retorno = 0;
	}
	else if(strcmp(estadoVueloStr,"En Vuelo") == 0)
	{
		strcpy(estadoVueloStr,"3\0");
		retorno = 0;
	}
	else if(strcmp(estadoVueloStr,"Demorado") == 0)
	{
		strcpy(estadoVueloStr,"4\0");
		retorno = 0;
	}
	return retorno;
}

/**************************************************************************************/

/** \brief setea el id en un pasajero
 *
 * \param this Passenger* puntero pasajero
 * \param id int id a setear
 * \return int retorno 0 si funciono correctamente o -1 sino
 *
 */
int Passenger_setId(Passenger* this,int id)
{
	int retorno = -1;
	if(this != NULL && id >= 0)
	{
		this->id = id;
		retorno = 0;
	}
	return retorno;
}

/** \brief obtiene el id de un pasajero
 *
 * \param this Passenger* puntero pasajero
 * \param id int* dirreccion donde se encuentra el id obtenido
 * \return int retorno 0 si funciono correctamente o -1 sino
 *
 */
int Passenger_getId(Passenger* this,int* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

/** \brief setea el nombre en un pasajero
 *
 * \param this Passenger* puntero pasajero
 * \param nombre char* nombre a setear
 * \return int retorno 0 si funciono correctamente o -1 sino
 *
 */
int Passenger_setNombre(Passenger* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL && esNombre(nombre, LEN_NOMBRE))
	{
		strncpy(this->nombre,nombre,LEN_NOMBRE);
		retorno = 0;
	}
	return retorno;
}

/** \brief obtiene el nombre en un pasajero
 *
 * \param this Passenger* puntero pasajero
 * \param nombre char* dirreccion donde se encuentra el nombre obtenido
 * \return int retorno 0 si funciono correctamente o -1 sino
 *
 */
int Passenger_getNombre(Passenger* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		strncpy(nombre,this->nombre,LEN_NOMBRE);
		retorno = 0;
	}
	return retorno;
}

/** \brief setea el apellido en un pasajero
 *
 * \param this Passenger* puntero pasajero
 * \param apellido char* apellido a setear
 * \return int retorno 0 si funciono correctamente o -1 sino
 *
 */
int Passenger_setApellido(Passenger* this,char* apellido)
{
	int retorno = -1;
	if(this != NULL && apellido != NULL && esNombre(apellido, LEN_APELLIDO))
	{
		strncpy(this->apellido,apellido,LEN_APELLIDO);
		retorno = 0;
	}
	return retorno;
}

/** \brief obtiene el apellido en un pasajero
 *
 * \param this Passenger* puntero pasajero
 * \param apellido char* dirreccion donde se encuentra el apellido obtenido
 * \return int retorno 0 si funciono correctamente o -1 sino
 *
 */
int Passenger_getApellido(Passenger* this,char* apellido)
{
	int retorno = -1;
	if(this != NULL && apellido != NULL)
	{
		strncpy(apellido,this->apellido,LEN_APELLIDO);
		retorno = 0;
	}
	return retorno;
}

/** \brief setea el precio en un pasajero
 *
 * \param this Passenger* puntero pasajero
 * \param precio float precio a setear
 * \return int retorno 0 si funciono correctamente o -1 sino
 *
 */
int Passenger_setPrecio(Passenger* this,float precio)
{
	int retorno = -1;
	if(this != NULL && precio >= 0 && precio <= 100000)
	{
		this->precio = precio;
		retorno = 0;
	}
	return retorno;
}

/** \brief obtiene el precio en un pasajero
 *
 * \param this Passenger* puntero pasajero
 * \param precio float* dirreccion donde se encuentra el precio obtenido
 * \return int retorno 0 si funciono correctamente o -1 sino
 *
 */
int Passenger_getPrecio(Passenger* this,float* precio)
{
	int retorno = -1;
	if(this != NULL && precio != NULL)
	{
		*precio = this->precio;
		retorno = 0;
	}
	return retorno;
}

/** \brief setea el tipoPasajero en un pasajero
 *
 * \param this Passenger* puntero pasajero
 * \param tipoPasajero int tipoPasajero a setear
 * \return int retorno 0 si funciono correctamente o -1 sino
 *
 */
int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int retorno = -1;
	if(this != NULL && tipoPasajero >= 1 && tipoPasajero <= 3)
	{
		this->tipoPasajero = tipoPasajero;
		retorno = 0;
	}
	return retorno;
}

/** \brief obtiene el tipoPasajero en un pasajero
 *
 * \param this Passenger* puntero pasajero
 * \param tipoPasajero int* dirreccion donde se encuentra el tipoPasajero obtenido
 * \return int retorno 0 si funciono correctamente o -1 sino
 *
 */
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int retorno = -1;
	if(this != NULL && tipoPasajero != NULL)
	{
		*tipoPasajero = this->tipoPasajero;
		retorno = 0;
	}
	return retorno;
}

/** \brief setea el codigoVuelo en un pasajero
 *
 * \param this Passenger* puntero pasajero
 * \param codigoVuelo char* codigoVuelo a setear
 * \return int retorno 0 si funciono correctamente o -1 sino
 *
 */
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = -1;
	if(this != NULL && codigoVuelo != NULL && esCodigo(codigoVuelo, LEN_CODIGO))
	{
		strncpy(this->codigoVuelo,codigoVuelo,LEN_CODIGO);
		retorno = 0;
	}
	return retorno;
}

/** \brief obtiene el codigoVuelo en un pasajero
 *
 * \param this Passenger* puntero pasajero
 * \param codigoVuelo char* dirreccion donde se encuentra el codigoVuelo obtenido
 * \return int retorno 0 si funciono correctamente o -1 sino
 *
 */
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = -1;
	if(this != NULL && codigoVuelo != NULL)
	{
		strncpy(codigoVuelo,this->codigoVuelo,LEN_CODIGO);
		retorno = 0;
	}
	return retorno;
}

/** \brief setea el estadoVuelo en un pasajero
 *
 * \param this Passenger* puntero pasajero
 * \param estadoVuelo int estadoVuelo a setear
 * \return int retorno 0 si funciono correctamente o -1 sino
 *
 */
int Passenger_setEstadoVuelo(Passenger* this,int estadoVuelo)
{
	int retorno = -1;
	if(this != NULL && estadoVuelo >= 1 && estadoVuelo <= 4)
	{
		this->estadoVuelo = estadoVuelo;
		retorno = 0;
	}
	return retorno;
}

/** \brief obtiene el estadoVuelo en un pasajero
 *
 * \param this Passenger* puntero pasajero
 * \param estadoVuelo int* dirreccion donde se encuentra el estadoVuelo obtenido
 * \return int retorno 0 si funciono correctamente o -1 sino
 *
 */
int Passenger_getEstadoVuelo(Passenger* this,int* estadoVuelo)
{
	int retorno = -1;
	if(this != NULL && estadoVuelo != NULL)
	{
		*estadoVuelo = this->estadoVuelo;
		retorno = 0;
	}
	return retorno;
}

/**********************/

/** \brief setea el id en un pasajero en formato str
 *
 * \param this Passenger* puntero pasajero
 * \param char* int id a setear en formato str
 * \return int retorno 0 si funciono correctamente o -1 sino
 *
 */
int Passenger_setIdStr(Passenger* this,char* id)
{
	int retorno = -1;
	int auxId;
	if(this != NULL && id != NULL && esNumerica(id, sizeof(id)))
	{
		auxId = atoi(id);
		if(auxId >= 0)
		{
			this->id = auxId;
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief setea el precio en un pasajero en formato str
 *
 * \param this Passenger* puntero pasajero
 * \param precio char* precio a setear en formato str
 * \return int retorno 0 si funciono correctamente o -1 sino
 *
 */
int Passenger_setPrecioStr(Passenger* this,char* precio)
{
	int retorno = -1;
	float auxPrecio;
	if(this != NULL && precio != NULL && esNumeroFlotante(precio, sizeof(precio)))
	{
		auxPrecio = atof(precio);
		if(auxPrecio >= 0 && auxPrecio <= 100000)
		{
			this->precio = auxPrecio;
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief setea el tipoPasajero en un pasajero en formato str
 *
 * \param this Passenger* puntero pasajero
 * \param tipoPasajero char* tipoPasajero a setear en formato str
 * \return int retorno 0 si funciono correctamente o -1 sino
 *
 */
int Passenger_setTipoPasajeroStr(Passenger* this,char* tipoPasajero)
{
	int retorno = -1;
	int auxTipoPasajero;
	if(this != NULL && tipoPasajero != NULL && esNumerica(tipoPasajero, sizeof(tipoPasajero)))
	{
		auxTipoPasajero = atoi(tipoPasajero);
		if(auxTipoPasajero >= 1 && auxTipoPasajero <= 3)
		{
			this->tipoPasajero = auxTipoPasajero;
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief setea el estadoVuelo en un pasajero en formato str
 *
 * \param this Passenger* puntero pasajero
 * \param estadoVuelo char* estadoVuelo a setear en formato str
 * \return int retorno 0 si funciono correctamente o -1 sino
 *
 */
int Passenger_setEstadoVueloStr(Passenger* this,char* estadoVuelo)
{
	int retorno = -1;
	int auxEstadoVuelo;
	if(this != NULL && estadoVuelo != NULL && esNumerica(estadoVuelo, sizeof(estadoVuelo)))
	{
		auxEstadoVuelo = atoi(estadoVuelo);
		if(auxEstadoVuelo >= 1 && auxEstadoVuelo <= 4)
		{
			this->estadoVuelo = auxEstadoVuelo;
			retorno = 0;
		}
	}
	return retorno;
}


