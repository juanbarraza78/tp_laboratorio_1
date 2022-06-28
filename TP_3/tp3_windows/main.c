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
	int flagGuardar = 0;
	int flagCerrar = 0;
	int flagCargar = 0;
	int opciones;
	int cantidadGuardada;
	do
	{
		flagCerrar = 0;
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
				if(flagCargar == 0)
				{
					controller_loadFromText("data.csv", listaPasajeros);
					flagCargar = 1;
				}
				else
				{
					printf("Ya se cargo anteriormente\n");
				}
				break;
			case 2:
				if(flagCargar == 0)
				{
					controller_loadFromBinary("dataBinario.csv", listaPasajeros);
					flagCargar = 1;
				}
				else
				{
					printf("Ya se cargo anteriormente\n");
				}
				break;
			case 3:
				if(!controller_addPassenger(listaPasajeros))
				{
					printf("Pasagero agregado\n");
				}
				break;
			case 4:
				if(ll_isEmpty(listaPasajeros) == 0)
				{
					if(!controller_editPassenger(listaPasajeros))
					{
						printf("modificar ok\n");
					}
				}
				else
				{
					printf("No hay nada guardado\n");
				}

				break;
			case 5:
				if(ll_isEmpty(listaPasajeros) == 0)
				{
					if(!controller_removePassenger(listaPasajeros))
					{
						printf("remove ok\n");
					}
				}
				else
				{
					printf("No hay nada guardado\n");
				}

				break;
			case 6:
				if(ll_isEmpty(listaPasajeros) == 0)
				{
					controller_ListPassenger(listaPasajeros);
				}
				else
				{
					printf("No hay nada guardado\n");
				}
				break;
			case 7:
				if(ll_isEmpty(listaPasajeros) == 0)
				{
					controller_sortPassenger(listaPasajeros);
				}
				else
				{
					printf("No hay nada guardado\n");
				}
				break;
			case 8:
				if(ll_isEmpty(listaPasajeros) == 0)
				{
					cantidadGuardada = controller_saveAsText("data.csv", listaPasajeros);
					if(cantidadGuardada >= 0)
					{
						printf("se pudo guardar correctamente %d elementos\n", cantidadGuardada);
						flagGuardar = 1;
					}
				}
				else
				{
					printf("No hay nada guardado\n");
				}
				break;
			case 9:
				if(ll_isEmpty(listaPasajeros) == 0)
				{
					cantidadGuardada = controller_saveAsBinary("dataBinario.csv", listaPasajeros);
					if(cantidadGuardada >= 0)
					{
						printf("se pudo guardar correctamente %d elementos\n", cantidadGuardada);
						flagGuardar = 1;
					}
				}
				else
				{
					printf("No hay nada guardado\n");
				}
				break;
			case 10:
				flagCerrar = 1;
				break;
			}
		}
	}while(!(flagCerrar == 1 && flagGuardar ==1));
	return EXIT_SUCCESS;

}
