#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);
	LinkedList* listaPasajeros = ll_newLinkedList();
	int opciones;
	do
	{
		printf("\n ---Menu---\n");
		printf("1) CARGAR DATOS(MODO TEXTO)\n");
		printf("2) CARGAR DATOS(MODO BINARIO)\n");
		printf("3) ALTA\n");
		printf("4) MODIFICAR\n");
		printf("5) BAJA\n");
		printf("6) LISTAR\n");
		printf("7) ORDENAR\n");
		printf("8) GUARDAR DATOS(MODO TEXTO)\n");
		printf("9) GUARDAR DATOS(MODO BINARIO)\n");
		printf("10) SALIR\n\n");
		if(!utn_getNumero(&opciones, "Ingrese una opcion\n", "Error, Opcion invalida\n", 1, 10, 0))
		{
			switch(opciones)
			{
			case 1:
				printf("opcion1\n");
			  controller_loadFromText("data.csv",listaPasajeros);
				break;
			case 2:
				printf("opcion2\n");
				break;
			case 3:
				printf("opcion3\n");
				break;
			case 4:
				printf("opcion4\n");
				break;
			case 5:
				printf("opcion5\n");
				break;
			case 6:
				printf("opcion6\n");
				break;
			}
		}
	}while(opciones != 10);
	return EXIT_SUCCESS;

}
