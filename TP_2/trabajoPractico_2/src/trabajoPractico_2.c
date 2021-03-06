/*
 ============================================================================
 Name        : trabajoPractico_2.c
 Author      : Juan Ignacio Barraza
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "ArrayPassenger.h"
#include "entrada_validaciones_datos.h"

int main(void) {
	setbuf(stdout, NULL);

	Passenger passengersArray[PASSENGER_LEN];

	int opciones;
	int opcionesDos;
	int auxId;
	char auxName[51];
	char auxLastName[51];
	float auxPrice;
	char auxFlycode[20];
	int auxTypePassenger;
	int auxStatusFlight;
	int opcionOrden;
	int idPassengers = 0;

	initPassengers(passengersArray, PASSENGER_LEN);

	do{
		printf("\n ---Menu---\n");
		printf("1) ALTA\n");
		printf("2) MODIFICAR\n");
		printf("3) BAJA\n");
		printf("4) INFORMAR\n");
		printf("5) ALTA FORZADA\n");
		printf("6) LISTAR\n");
		printf("7) SALIR\n\n");
		if(!utn_getNumero(&opciones, "Ingrese una opcion\n", "Error, No existe esa opcion\n", 1, 7, 0))
		{
			switch(opciones)
			{
			case 1:
				if(!utn_getDatosPassager(&idPassengers, auxName, LEN_NAME, auxLastName, LEN_LASTNAME, &auxPrice, &auxTypePassenger, auxFlycode, LEN_FLYCODE, &auxStatusFlight) &&
						!addPassenger(passengersArray, PASSENGER_LEN, idPassengers, auxName, auxLastName, auxPrice, auxTypePassenger, auxFlycode, auxStatusFlight))
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
					printPassengers(passengersArray, PASSENGER_LEN);

					if(!utn_getNumero(&auxId, "\nIngrese el Id que quiere modificar\n", "Error, id incorrecto\n", 0, 4000, 2) &&
											!modificarPasajero(passengersArray, PASSENGER_LEN, auxId))
					{
						printf("Se pudo modificar correctamente\n");
					}
					else
					{
						printf("No se pudo modificar correctamente\n");
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
					printPassengers(passengersArray, PASSENGER_LEN);

					if(!utn_getNumero(&auxId, "Ingrese el Id que quiere eliminar\n", "Error, id incorrecto\n", 0, 4000, 2) &&
									 removePassenger(passengersArray, PASSENGER_LEN, auxId) == 0)
					{
						printf("Se pudo eliminar correctamente\n");
					}
					else
					{
						printf("No se pudo eliminar correctamente\n");
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
					printf("------INFORMAR------\n");
					printf("1) Listado de los pasajeros ordenados alfabeticamente por apellido y tipo de pasajero\n");
					printf("2) Total y promedio de los precios de los pasajes y la cantidad que lo supera\n");
					printf("3) Listado de los pasajeros por codigo de vuelo y estado de vuelo activo\n");
					if(!utn_getNumero(&opcionesDos, "Ingrese una opcion\n", "Error, No existe esa opcion\n", 1, 3, 2))
					{
						switch(opcionesDos)
						{
						case 1:
							if(!utn_getNumero(&opcionOrden, "Ingrese una opcion\n1)Decendente\n2)Asendente\n", "Error, opcion invalida", 1, 2, 1))
							{
								sortPassengersByLastNameAndTypePassenger(passengersArray, PASSENGER_LEN,(opcionOrden-1));
								printPassengers(passengersArray, PASSENGER_LEN);
							}
							break;
						case 2:
							MostrarPromedioYTotalDePrecioPasajeros(passengersArray, PASSENGER_LEN);
							break;
						case 3:
							filtrarYMostrarPorStatusVuelo(passengersArray, PASSENGER_LEN);
							break;
						}
					}
				}
				else
				{
					printf("No hay nada cargado\n");
				}
				break;
			case 5:
				addPassengerForzado(passengersArray, PASSENGER_LEN,&idPassengers, "Mariela", "Gomez", 20000, "AA200", 1, 1);
				addPassengerForzado(passengersArray, PASSENGER_LEN,&idPassengers, "Juan Pablo", "Martinez", 30000, "LA201", 2, 1);
				addPassengerForzado(passengersArray, PASSENGER_LEN,&idPassengers, "Mauro", "Gomez", 18000, "AA200", 2, 1);
				addPassengerForzado(passengersArray, PASSENGER_LEN,&idPassengers, "Yolanda", "Alberdi", 32000, "LA200", 1, 1);
				addPassengerForzado(passengersArray, PASSENGER_LEN,&idPassengers, "Fabio", "Benitez", 45000, "AA220", 2, 2);
				break;
			case 6:
				printPassengers(passengersArray, PASSENGER_LEN);
				break;
			}
		}
	}while(opciones != 7);
	return EXIT_SUCCESS;
}
