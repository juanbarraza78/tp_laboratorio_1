#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "utn.h"

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
				break;
			case 2:
				printf("opcion2\n");
				break;
			case 3:
				if(!Passenger_agregarArray(listaPasajeros, 1, "juan", "barraza", 100, 1, "bc3", 1) &&
						!Passenger_agregarArray(listaPasajeros, 2, "aasd", "barraza", 200, 2, "bc3", 2) &&
						!Passenger_agregarArray(listaPasajeros, 3, "cbvsdfg", "cxasd", 10000, 2, "bc3", 3) &&
						!Passenger_agregarArray(listaPasajeros, 4, "asdfgsdg", "zasdas", 10, 3, "bc3", 4))
				{
					printf("lista ok\n");
				}
				break;
			case 4:
				if(!Passenger_modificarPorIdArray(listaPasajeros, 1))
				{
					printf("modificar ok\n");
				}
				break;
			case 5:
				printf("opcion5\n");
				break;
			case 6:
				Passenger_imprimirArray(listaPasajeros);
				break;
			case 7:
				printf("opcion7\n");
				break;
			case 8:
				printf("opcion8\n");
				break;
			case 9:
				printf("opcion9\n");
				break;
			}
		}
	}while(opciones != 10);
	return EXIT_SUCCESS;

}
