/*
 * H
 */
#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#define LEN_NAME 51
#define LEN_LASTNAME 51
#define LEN_FLYCODE 20
#define LEN_STATUS_FLIGHT 124
#define LEN_TYPE_PASSENGER 124
#define PASSENGER_LEN 2000

typedef struct {
	int id;
	char name[LEN_NAME];
	char lastName[LEN_LASTNAME];
	float price;
	char flycode[LEN_FLYCODE];
	int typePassenger;
	int statusFlight;
	int isEmpty;
} Passenger;

int initPassengers(Passenger* list, int len);
int addPassengerForzado(Passenger pArray[], int len,int* id,char name[],char lastname[], float price,char flyCode[],int typePassenger, int statusFlight);
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[], int statusFlight);
int utn_getDatosPassager(int* id, char name[],int lenName, char lastName[],int lenLastName, float* price, int* typePassanger, char flyCode[], int lenFlyCode, int* statusFlight);
void mostrarPassenger(Passenger pasajero);
int printPassengers(Passenger pArray[], int len);
int modificarPasajero(Passenger pArray[], int len, int idPassenger);
int findPassengerById(Passenger* list, int len,int id);
int removePassenger(Passenger* list, int len, int id);
int hayAlgoCargado(Passenger pArray[], int len);
int sortPassengersByLastNameAndTypePassenger(Passenger* list, int len, int order);
int sortPassengersByCode(Passenger* list, int len, int order);
int MostrarPromedioYTotalDePrecioPasajeros(Passenger* list, int len);
int filtrarYMostrarPorStatusVuelo(Passenger* list, int len);
int convertirTipoPasajeroStr(int tipoPasajero, char* tipoPasajeroStr);
int convertirEstadoVueloStr(int estadoVuelo, char* estadoVueloStr);


#endif
