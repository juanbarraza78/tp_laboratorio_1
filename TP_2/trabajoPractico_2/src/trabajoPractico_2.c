/*
 ============================================================================
 Name        : trabajoPractico_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>

#include "ArrayPassenger.h"
#include "entrada_validaciones_datos.h"

#define PASSENGER_LEN 2000

#define PRIMERA_CLASE 0
#define CLASE_EJECUTIVA 1
#define CLASE_TURISTA 2

int main(void) {
	setbuf(stdout, NULL);

	Passenger passengersArray[PASSENGER_LEN];
	int opciones;

	int auxint;

	int auxId;
	char auxName[51];
	char auxLastName[51];
	float auxPrice;
	char auxFlycode[20];
	int auxTypePassenger;
	int auxStatusFlight;

	initPassengers(passengersArray, PASSENGER_LEN);

	do{
		printf("\n ---Menu---\n");
		printf("1) ALTA\n");
		printf("2) MODIFICAR\n");
		printf("3) BAJA\n");
		printf("4) INFORMAR\n");
		printf("5) ALTA FORZADA\n");
		printf("6) LISTAR\n");
		printf("7) Salir\n\n");
		if(!utn_getNumero(&opciones, "Ingrese una opcion\n", "Error, No existe esa opcion\n", 1, 7, 0))
		{
			switch(opciones)
			{
			case 1:
				if(!utn_getDatosPassager(auxName, 51, auxLastName, 51, &auxPrice, &auxTypePassenger, auxFlycode, 20, &auxStatusFlight) &&
						!addPassenger(passengersArray, PASSENGER_LEN, auxId, auxName, auxLastName, auxPrice, auxTypePassenger, auxFlycode, auxStatusFlight))
				{
					printf("El pasajero se cargo correctamente\n");
				}
				else
				{
					printf("El pasajero no se cargo correctamente\n");
				}
				break;
			case 2:
				if(hayAlgoCargado(passengersArray, PASSENGER_LEN) == 1)
				{
					if(!utn_getNumero(&auxint, "Ingrese el Id que quiere modificar\n", "Error, id incorrecto\n", 0, 4000, 1) &&
											!modificarPasajero(passengersArray, PASSENGER_LEN, auxint))
					{
						printf("Se pudo modificar correctamente\n");
					}
					else
					{
						printf("El id no existe\n");
					}
				}
				else
				{
					printf("No hay nada cargado\n");
				}
				break;
			case 3:
				if(hayAlgoCargado(passengersArray, PASSENGER_LEN) == 1)
				{
					if(!utn_getNumero(&auxint, "Ingrese el Id que quiere eliminar\n", "Error, id incorrecto\n", 0, 4000, 1) &&
											!removePassenger(passengersArray, PASSENGER_LEN, auxint))
					{
						printf("Se pudo eliminar correctamente\n");
					}
					else
					{
						printf("El id no existe\n");
					}
				}
				else
				{
					printf("No hay nada cargado\n");
				}
				break;
			case 4:
				if(hayAlgoCargado(passengersArray, PASSENGER_LEN) == 1)
				{
					if(sortPassengers(passengersArray, PASSENGER_LEN,1)>0)
					{
						printf("Ordenamiento completado\n");
					}
				}
				else
				{
					printf("No hay nada cargado\n");
				}
				break;
			case 5:
				if(!initPassengersForzado(passengersArray, PASSENGER_LEN, "juan", "barraza", 123.5, "b5q", 1, 2) &&
						!initPassengersForzado(passengersArray, PASSENGER_LEN, "pedro", "aomas", 143.5, "a71", 2, 1) &&
						!initPassengersForzado(passengersArray, PASSENGER_LEN, "ricardo", "contaner", 1263.5, "ass5", 3, 1) &&
						!initPassengersForzado(passengersArray, PASSENGER_LEN, "asd", "aomas", 1263.5, "ass5", 2, 1) &&
						!initPassengersForzado(passengersArray, PASSENGER_LEN, "asd", "aomas", 1263.5, "ass5", 1, 2) &&
						!initPassengersForzado(passengersArray, PASSENGER_LEN, "asd", "zontaner", 1263.5, "ass5", 3, 1))
				{
					printf("ah funcado chaval\n");
				}
				else
				{
					printf("noooo ah funcado chaval\n");
				}
				break;
			case 6:
				if(!printPassengers(passengersArray, PASSENGER_LEN))
				{
					printf("ah funcado chaval\n");
				}
				else
				{
					printf("no ah funcado chaval\n");
				}
				break;
			}
		}
	}while(opciones != 7);
	return EXIT_SUCCESS;
}
