/*
 * C
 */
#include "ArrayPassenger.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entrada_validaciones_datos.h"

/** \brief To indicate that all position in the array are empty,* this function put the flag (isEmpty) in TRUE in all* position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok*
*/
int initPassengers(Passenger* list, int len)
{
	int retorno = -1;
	if (list != NULL && len > 0)
	{
		for (int i = 0; i < len; i++)
		{
			list[i].isEmpty = 1;
		}
		retorno = 0;
	}
	return retorno;
}


/** \brief add in a existing list of passengers the values received as parameters* in the first empty position
* \param list passenger*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*/
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[], int statusFlight)
{
	int retorno = -1;
	int i;

	if (list != NULL && len > 0 && name != NULL && lastName != NULL && flycode != NULL)
	{
		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == 1)
			{

				list[i].id = idIncrementalPassager();
				strcpy(list[i].name,name);
				strcpy(list[i].lastName,lastName);
				list[i].price = price;
				strcpy(list[i].flycode,flycode);
				list[i].typePassenger = typePassenger;
				list[i].statusFlight = statusFlight;
				list[i].isEmpty = 0;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int utn_getDatosPassager(char name[],int lenName, char lastName[],int lenLastName, float* price, int* typePassanger, char flyCode[], int lenFlyCode, int* statusFlight)
{
	int retorno = -1;
	if(!utn_getNombre(name, lenName, "Ingrese su nombre del pasajero:\n", "Error, Nombre no valido\n", 2) &&
			!utn_getNombre(lastName, lenLastName, "Ingrese su apellido del pasajero:\n", "Error, apellido no valido\n", 2) &&
			!utn_getNumeroFlotante(price, "Ingrese precio del vuelo:\n", "Error, precio no valido\n", 0, 1000000, 2) &&
			!utn_getNumero(typePassanger, "Ingrese tipo de pasajero:\nPrimera clase[1] - Clase ejecutiva[2] - Clase turista[3]\n", "Error, opcion no valida\n", 1, 3, 2) &&
			!utn_getCodigo(flyCode, lenFlyCode, "Ingrese codigo del vuelo:\n", "Error, codigo no valido\n", 2) &&
			!utn_getNumero(statusFlight, "Ingrese estado del vuelo: ACTIVO[1] - INACTIVO[2]\n", "Error, opcion no valida\n", 1, 2, 2))
	{
		retorno = 0;
	}
	return retorno;
}

int idIncrementalPassager()
{
    static int idPassager = 0;
    idPassager++;
    return idPassager;
}

void mostrarPassenger(Passenger pasajero)
{
	if (pasajero.isEmpty == 0)
	{
		printf("Id: %d - Nombre: %s - Apellido: %s -  Precio: %f - Codigo: %s - Tipo %d - Estado %d \n",
				pasajero.id, pasajero.name, pasajero.lastName, pasajero.price, pasajero.flycode, pasajero.typePassenger, pasajero.statusFlight);
	}
}

int printPassengers(Passenger pArray[], int len)
{
	int retorno = -1;
	if (pArray != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			mostrarPassenger(pArray[i]);
		}
		retorno = 0;
	}
	return retorno;
}

int initPassengersForzado(Passenger pArray[], int len,char name[],char lastname[], float price,char flyCode[],int typePassenger, int statusFlight)
{
	int retorno = -1;
	int i;
	if (pArray != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			if(pArray[i].isEmpty == 1)
			{
				pArray[i].id = idIncrementalPassager();
				strcpy(pArray[i].name,name);
				strcpy(pArray[i].lastName,lastname);
				pArray[i].price = price;
				strcpy(pArray[i].flycode, flyCode);
				pArray[i].typePassenger = typePassenger;
				pArray[i].statusFlight = statusFlight;
				pArray[i].isEmpty = 0;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int modificarPasajero(Passenger pArray[], int len, int idPassenger)
{
	int retorno = -1;
	int index;
	int opcionesBuffer;

	if(pArray != NULL && len > 0 && idPassenger > 0)
	{
		index = findPassengerById(pArray, len, idPassenger);
		if(index != -1)
		{
			mostrarPassenger(pArray[index]);
			do{
				if(utn_getNumero(&opcionesBuffer, "Que campo quiere modificar?\nNombre[1] - Apellido[2] - Precio[3] - Tipo de pasajero[4] - codigo de vuelo[5] - salir[6]\n",
									"Opcion no valida\n", 1, 6, 0) == 0)
							{
								switch(opcionesBuffer)
								{
								case 1:
									if(!utn_getNombre(pArray[index].name, 51, "Ingrese el nombre del pasajero:\n", "Error, Nombre no valido\n", 2))
									{
										retorno = 0;
									}
									break;
								case 2:
									if(!utn_getNombre(pArray[index].lastName, 51, "Ingrese el apellido del pasajero:\n", "Error, apellido no valido\n", 2))
									{
										retorno = 0;
									}
									break;
								case 3:
									if(!utn_getNumeroFlotante(&pArray[index].price, "Ingrese el precio del vuelo:\n", "Error, precio no valido\n", 0, 100000, 2))
									{
										retorno = 0;
									}
									break;
								case 4:
									if(!utn_getNumero(&pArray[index].typePassenger, "Ingrese tipo de pasajero:\nPrimera clase[1] - Clase ejecutiva[2] - Clase turista[3]\n", "Error, opcion no valida\n", 1, 3, 2))
									{
										retorno = 0;
									}
									break;
								case 5:
									if(!utn_getCodigo(pArray[index].flycode, 20, "Ingrese codigo del vuelo:\n", "Error, codigo no valido\n", 2))
									{
										retorno = 0;
									}
									break;
								}
							}
			}while(opcionesBuffer != 6);
		}
	}
	return retorno;
}

int findPassengerById(Passenger* list, int len,int id)
{
	int retorno = -1;
	if (list != NULL && len > 0 && id > 0)
	{
		for (int i = 0; i < len; i++)
		{
			if (list[i].id == id && list[i].isEmpty == 0)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
int removePassenger(Passenger* list, int len, int id)
{
	int retorno = -1;
	int index;
	int opcionesBuffer;
	if(list != NULL && len > 0 && id > 0)
	{
		index = findPassengerById(list, len, id);
		if(index != -1)
		{
			printf("Estas seguro de eliminar a: ");
			mostrarPassenger(list[index]);
			if(utn_getNumero(&opcionesBuffer, "SI[1] - NO[2]\n", "Opcion no valida\n", 1, 2, 1) == 0 && opcionesBuffer == 1)
			{
				list[index].isEmpty = 1;
				retorno = 0;
			}
		}

	}
	return retorno;
}

int hayAlgoCargado(Passenger pArray[], int len)
{
	int retorno = 0;
	if (pArray != NULL && len > 0)
	{
		for (int i = 0; i < len; i++)
		{
			if (pArray[i].isEmpty == 0)
			{
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}


/** \brief Sort the elements in the array of passengers, the argument order indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
*/
int sortPassengers(Passenger* list, int len, int order)
{
	int flagSwap;
	int i;
	int contador = 0;
	int retorno = -1;
	Passenger bufferPassenger;
	int nuevoLimite;
	if(list != NULL && len >= 0)
	{
		nuevoLimite = len - 1;
		do{
			flagSwap = 0;
					for(i = 0; i < nuevoLimite; i++)
					{
						contador++;
						if(order == 0)
						{
							if(strcmp(list[i].lastName,list[i+1].lastName) < 0)
							{
								flagSwap = 1;
								bufferPassenger = list[i];
								list[i] = list[i+1];
								list[i+1] = bufferPassenger;
							}
							else if(strcmp(list[i].lastName,list[i+1].lastName) == 0 &&
									list[i].typePassenger < list[i+1].typePassenger)
							{
								flagSwap = 1;
								bufferPassenger = list[i];
								list[i] = list[i+1];
								list[i+1] = bufferPassenger;
							}
						}
						else if(order == 1)
						{
							if(strcmp(list[i].lastName,list[i+1].lastName) > 0)
							{
								flagSwap = 1;
								bufferPassenger = list[i];
								list[i] = list[i+1];
								list[i+1] = bufferPassenger;
							}
							else if(strcmp(list[i].lastName,list[i+1].lastName) == 0 &&
									list[i].typePassenger > list[i+1].typePassenger)
							{
								flagSwap = 1;
								bufferPassenger = list[i];
								list[i] = list[i+1];
								list[i+1] = bufferPassenger;
							}
						}

						nuevoLimite--;
					}
		}while(flagSwap);
		retorno = contador;
	}
	return retorno;
}

int promedioPrecioPasajeros(Passenger* list, int len)
{
	int retorno = -1;
	int contador = 0;
	float acomulador = 0;
	float promedio;
	int contadorPromedioSuperado = 0;

	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == 0)
			{
				contador++;
				acomulador += list[i].price;
			}
		}
		if(contador != 0)
		{
			promedio = acomulador/contador;

			for(int i = 0; i < len; i++)
			{
				if(list[i].isEmpty == 0 && list[i].price > promedio)
				{
					contadorPromedioSuperado++;
				}
			}
			printf("El total de los precios de los vuelos es: %f\n",acomulador);
			printf("El promedio de los precios de los vuelos es: %f\n",promedio);
			printf("La cantidad de personas que superan el promedio de precios es: %d\n",contadorPromedioSuperado);
			retorno = 0;
		}

	}
	return retorno;
}
