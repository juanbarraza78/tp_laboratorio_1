/*
 ============================================================================
 Name        : tp_1_juan_barraza.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "bibliotecaCalculos.h"
#include "bibliotecaUtn.h"

#define PORCENTAJE_DE_DESCUENTO 10
#define PORCENTAJE_DE_INTERES 25

int main(void) {
	setbuf(stdout, NULL);

	int kilometros;
	int opciones;
	int opcionesCaso2;

	int flagKilometros = 0;
	int flagAerolineas = 0;
	int flagLatam = 0;

	int flagCalculoAerolineas = 0;
	int flagCalculoLatam = 0;

	float precioAerolineas;
	float precioAerolineasDescuento;
	float precioAerolineasInteres;
	float precioAerolineasBitcoin;
	float precioAerolineasUnitario;

	float diferenciaAerolineasLatam;

	float precioLatam;
	float precioLatamDescuento;
	float precioLatamInteres;
	float precioLatamBitcoin;
	float precioLatamUnitario;

	do {
		if (!utn_getInt(&opciones,"\nEliga la opcion correspondiente:\n\nOpcion 1: Ingresar Kilómetros.\nOpcion 2: Ingresar Precio de Vuelos.\nOpcion 3: Calcular todos los costos.\n"
						"Opcion 4: Informar Resultados.\nOpcion 5: Carga forzada de datos.\nOpcion 6: Salir.\n","Error, Opcion no valida\n\n", 1, 6, 0)) {
			switch (opciones) {
			case 1:
				if (!utn_getInt(&kilometros, "Ingrese los kilometros\n","Error, Kilometros no validos\n", 1, 1000000, 2)) {
					printf("se pudo ingresar los kilometros correctamente\n");
					flagKilometros = 1;
				}
				else {
					printf("No se pudo ingresar los kilometros correctamente. Se lo enviara al menu nuevamente\n");
				}
				break;

			case 2:
				do {
					if (!utn_getInt(&opcionesCaso2,"\nEliga la opcion:\n\nOpcion 1: Precio de Aerolineas Argentinas.\nOpcion 2: Precio de Latam.\n""Opcion 3: Salir.\n","Error, Opcion no valida\n\n", 1, 3, 0)) {
						switch (opcionesCaso2) {
						case 1:
							if (!utn_getFloat(&precioAerolineas,"Ingrese el precio de Aerolineas Argentinas\n","Error. Monto incorrecto\n", 1, 100000000,1)) {
								printf("se pudo ingresar el precio de aerolineas correctamente\n");
								flagAerolineas = 1;
							}
							else {
								printf("No se pudo ingresar el precio de aerolineas correctamente, Se lo enviara al menu nuevamente\n");
							}
							break;
						case 2:
							if (!utn_getFloat(&precioLatam,"Ingrese el precio de Latam\n","Error. Monto incorrecto\n", 1, 100000000,1)) {
								printf("se pudo ingresar el precio de latam correctamente\n");
								flagLatam = 1;
							} else {
								printf("No se pudo ingresar el precio de latam correctamente, Se lo enviara al menu nuevamente\n");
							}
							break;
						}
					}
				} while (opcionesCaso2 != 3);
				break;
			case 3:
				if (flagKilometros == 1 && flagAerolineas == 1 && !hacerDescuentoflotante(precioAerolineas,PORCENTAJE_DE_DESCUENTO,&precioAerolineasDescuento)&& !hacerInteresflotante(precioAerolineas, PORCENTAJE_DE_INTERES, &precioAerolineasInteres)
						&& !convertirFloatABitcoin(precioAerolineas,&precioAerolineasBitcoin) && !dividirFloatInt(precioAerolineas, kilometros, &precioAerolineasUnitario)) {
					printf("Se calcularon correctamente los datos de Aerolineas\n");
					flagCalculoAerolineas = 1;
				}
				else {
					printf("no Se calcularon correctamente los datos de Aerolineas. Faltan datos\n");
				}

				if (flagKilometros == 1 && flagLatam == 1 && !hacerDescuentoflotante(precioLatam, PORCENTAJE_DE_DESCUENTO, &precioLatamDescuento) && !hacerInteresflotante(precioLatam,PORCENTAJE_DE_INTERES, &precioLatamInteres)
						&& !convertirFloatABitcoin(precioLatam, &precioLatamBitcoin) && !dividirFloatInt(precioLatam, kilometros, &precioLatamUnitario)){
					printf("Se calcularon correctamente los datos de Latam\n");
					flagCalculoLatam = 1;
				}
				else {
					printf("no Se calcularon correctamente los datos de latam. Faltan datos\n");
				}

				if (flagKilometros == 1 && flagAerolineas == 1 && flagLatam == 1 && !buscarDiferenciaPositivos(precioAerolineas,precioLatam, &diferenciaAerolineasLatam)) {
				}
				break;
			case 4:
				if(flagCalculoAerolineas == 1){
					printf("Precio Aerolineas: $%.2f\n",precioAerolineas);
					printf("a)Precio con tarjeta de debito: $ %.2f\n",precioAerolineasDescuento);
					printf("b)Precio con tarjeta de credito: $ %.2f\n",precioAerolineasInteres);
					printf("c)Precio pagando con bitcoin: $ %.2f BTC\n",precioAerolineasBitcoin);
					printf("d)Mostrar precio unitario: $ %.2f\n\n",precioAerolineasUnitario);
				}
				else{
					printf("Faltan datos para mostrar los metodos de pago de Aerolineas\n");
				}
				if(flagCalculoLatam == 1){
					printf("Precio Latam: $%.2f\n",precioLatam);
					printf("a)Precio con tarjeta de debito: $ %.2f\n",precioLatamDescuento);
					printf("b)Precio con tarjeta de credito: $ %.2f\n",precioLatamInteres);
					printf("c)Precio pagando con bitcoin: $ %.2f BTC\n",precioLatamBitcoin);
					printf("d)Mostrar precio unitario: $ %.2f\n\n",precioLatamUnitario);
				}
				else{
					printf("Faltan datos para mostrar los metodos de pago de Latam\n");
				}
				if(flagCalculoAerolineas == 1 && flagCalculoLatam == 1){
					printf("La diferencia de precio es: $ %.2f\n\n",diferenciaAerolineasLatam);
				}
				break;
			case 5:
				precioAerolineas = 162965;
				precioLatam = 159339;
				kilometros = 7090;

				hacerDescuentoflotante(precioAerolineas, PORCENTAJE_DE_DESCUENTO, &precioAerolineasDescuento);
				hacerInteresflotante(precioAerolineas, PORCENTAJE_DE_INTERES, &precioAerolineasInteres);
				convertirFloatABitcoin(precioAerolineas, &precioAerolineasBitcoin);
				dividirFloatInt(precioAerolineas, kilometros, &precioAerolineasUnitario);
				hacerDescuentoflotante(precioLatam, PORCENTAJE_DE_DESCUENTO, &precioLatamDescuento);
				hacerInteresflotante(precioLatam, PORCENTAJE_DE_INTERES, &precioLatamInteres);
				convertirFloatABitcoin(precioLatam, &precioLatamBitcoin);
				dividirFloatInt(precioLatam, kilometros, &precioLatamUnitario);
				buscarDiferenciaPositivos(precioAerolineas, precioLatam, &diferenciaAerolineasLatam);

				printf("Precio Aerolineas: $%.2f\n",precioAerolineas);
				printf("a)Precio con tarjeta de debito: $ %.2f\n",precioAerolineasDescuento);
				printf("b)Precio con tarjeta de credito: $ %.2f\n",precioAerolineasInteres);
				printf("c)Precio pagando con bitcoin: $ %.2f BTC\n",precioAerolineasBitcoin);
				printf("d)Mostrar precio unitario: $ %.2f\n\n",precioAerolineasUnitario);
				printf("Precio Latam: $%.2f\n",precioLatam);
				printf("a)Precio con tarjeta de debito: $ %.2f\n",precioLatamDescuento);
				printf("b)Precio con tarjeta de credito: $ %.2f\n",precioLatamInteres);
				printf("c)Precio pagando con bitcoin: $ %.2f BTC\n",precioLatamBitcoin);
				printf("d)Mostrar precio unitario: $ %.2f\n\n",precioLatamUnitario);
				printf("La diferencia de precio es: $ %.2f\n\n",diferenciaAerolineasLatam);
				break;
			}
		}
	} while (opciones != 6);

	return EXIT_SUCCESS;
}

