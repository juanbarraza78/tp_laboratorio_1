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
#include "Biblioteca.h"

int main(void) {
	setbuf(stdout, NULL);



	int opciones;
	int validacionDeRetorno;
	do{
		validacionDeRetorno = utn_getInt(&opciones,"Eliga la opcion correspondiente:\n\nOpcion 1: Ingresar Kilómetros.\nOpcion 2: Ingresar Precio de Vuelos.\nOpcion 3: Calcular todos los costos.\nOpcion 4: Informar Resultados.\nOpcion 5: Carga forzada de datos.\nOpcion 6: Salir.\n","Error, Opcion no valida\n\n", 1, 6, 2);
		if (validacionDeRetorno == 0)
		{
			switch (opciones)
			{
			case 1:
				printf("caso 1");
				break;
			case 2:
				printf("caso 2");
				break;
			case 3:
				printf("caso 3");
				break;
			case 4:
				printf("caso 4");
				break;
			case 5:
				printf("caso 5");
				break;
			}
		}
		else
		{
			break;
		}
	}while(opciones != 6);
	return EXIT_SUCCESS;
}
