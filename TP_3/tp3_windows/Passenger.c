/*
 * Passenger.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Passenger.h"
#include "utn.h"
#include "LinkedList.h"

Passenger* Passenger_new()
{
	Passenger* auxPasageroPuntero = NULL;
	auxPasageroPuntero = (Passenger*) malloc(sizeof(Passenger)*1);
	return auxPasageroPuntero;
}

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

void Passenger_delete(Passenger* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

/**************************************************************************************/

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

int Passenger_convertirTipoPasajeroStr(int tipoPasajero, char* tipoPasajeroStr)
{
	int retorno = -1;
	switch(tipoPasajero)
	{
	case 0:
		strcpy(tipoPasajeroStr,"FirstClass\0");
		retorno = 0;
		break;
	case 1:
		strcpy(tipoPasajeroStr,"ExecutiveClass\0");
		retorno = 0;
		break;
	case 2:
		strcpy(tipoPasajeroStr,"EconomyClass\0");
		retorno = 0;
		break;
	}
	return retorno;
}

int Passenger_convertirEstadoVueloStr(int estadoVuelo, char* estadoVueloStr)
{
	int retorno = -1;
	switch(estadoVuelo)
	{
	case 0:
		strcpy(estadoVueloStr,"Aterrizado\0");
		retorno = 0;
		break;
	case 1:
		strcpy(estadoVueloStr,"En Horario\0");
		retorno = 0;
		break;
	case 2:
		strcpy(estadoVueloStr,"En Vuelo\0");
		retorno = 0;
		break;
	case 3:
		strcpy(estadoVueloStr,"Demorado\0");
		retorno = 0;
		break;
	}
	return retorno;
}

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
			printf("id:%d - Nombre:%s - Apellido:%s - Precio:%f - Tipo:%s - Codigo:%s - Estado:%s\n",auxId,auxNombre,auxApellido,auxPrecio,auxTipoPasajeroStr,auxCodigoVuelo,auxEstadoVueloStr);
		}
	}
}

int Passenger_imprimirArray(LinkedList* listaPasajeros)
{
	int retorno = -1;
	int longitud;
	Passenger* pAuxPassager = NULL;

	if(listaPasajeros != NULL)
	{
		retorno = 0;
		longitud = ll_len(listaPasajeros);
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

int Passenger_buscarPorIdArray(LinkedList* listaPasajeros, int id)
{
	int retorno = -1;
	int longitud;
	int auxId;
	Passenger* pAuxPassager = NULL;

	if(listaPasajeros != NULL && id >= 0)
	{
		retorno = 0;
		longitud = ll_len(listaPasajeros);
		if(longitud >= 0)
		{
			for(int i = 0; i < longitud ; i++)
			{
				pAuxPassager = ll_get(listaPasajeros, i);

				if(pAuxPassager != NULL && !Passenger_getId(pAuxPassager, &auxId) && auxId == id)
				{
					retorno = i;
					break;
				}
			}
		}
	}
	return retorno;
}


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

int Passenger_borrarPorIdArray(LinkedList* listaPasajeros, int id)
{
	int retorno = -1;
	int auxIndexBorrar;
	if(listaPasajeros != NULL && id >= 0)
	{
		auxIndexBorrar = Passenger_buscarPorIdArray(listaPasajeros, id);
		if(auxIndexBorrar >= 0)
		{
			if(Passenger_deleteIndexArray(listaPasajeros, auxIndexBorrar))
			{
				retorno = 0;
			}
		}
	}
	return retorno;
}

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
									"Error, opcion invalida", 1, 6, 1))
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

int Passenger_setNombre(Passenger* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL) // ver que me falta (isValidName)
	{
		strncpy(this->nombre,nombre,LEN_NOMBRE);
		retorno = 0;
	}
	return retorno;
}
int Passenger_getNombre(Passenger* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre,this->nombre);
		retorno = 0;
	}
	return retorno;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int retorno = -1;
	if(this != NULL && apellido != NULL)
	{
		strncpy(this->apellido,apellido,LEN_APELLIDO);
		retorno = 0;
	}
	return retorno;
}
int Passenger_getApellido(Passenger* this,char* apellido)
{
	int retorno = -1;
	if(this != NULL && apellido != NULL)
	{
		strcpy(apellido,this->apellido);
		retorno = 0;
	}
	return retorno;
}

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

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int retorno = -1;
	if(this != NULL && tipoPasajero >= 0 && tipoPasajero <= 2)
	{
		this->tipoPasajero = tipoPasajero;
		retorno = 0;
	}
	return retorno;
}
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

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = -1;
	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(this->codigoVuelo,codigoVuelo);
		retorno = 0;
	}
	return retorno;
}
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

int Passenger_setEstadoVuelo(Passenger* this,int estadoVuelo)
{
	int retorno = -1;
	if(this != NULL && estadoVuelo >= 0 && estadoVuelo <= 3)
	{
		this->estadoVuelo = estadoVuelo;
		retorno = 0;
	}
	return retorno;
}
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

int Passenger_setTipoPasajeroStr(Passenger* this,char* tipoPasajero)
{
	int retorno = -1;
	int auxTipoPasajero;
	if(this != NULL && tipoPasajero != NULL && esNumerica(tipoPasajero, sizeof(tipoPasajero)))
	{
		auxTipoPasajero = atoi(tipoPasajero);
		if(auxTipoPasajero >= 0 && auxTipoPasajero <= 2)
		{
			this->tipoPasajero = auxTipoPasajero;
			retorno = 0;
		}
	}
	return retorno;
}

int Passenger_setEstadoVueloStr(Passenger* this,char* estadoVuelo)
{
	int retorno = -1;
	int auxEstadoVuelo;
	if(this != NULL && estadoVuelo != NULL && esNumerica(estadoVuelo, sizeof(estadoVuelo)))
	{
		auxEstadoVuelo = atoi(estadoVuelo);
		if(auxEstadoVuelo >= 0 && auxEstadoVuelo <= 3)
		{
			this->estadoVuelo = auxEstadoVuelo;
			retorno = 0;
		}
	}
	return retorno;
}


