/*
 * H
 */
#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

typedef struct {
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[20];
	int typePassenger;
	int statusFlight;
	int isEmpty;
} Passenger;

int initPassengers(Passenger* list, int len);
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[], int statusFlight);
int idIncrementalPassager();
void mostrarPassenger(Passenger alumno);
int printPassengers(Passenger pArray[], int len);
int initPassengersForzado(Passenger pArray[], int len,char name[],char lastname[], float price,char flyCode[],int typePassenger, int statusFlight);

int utn_getDatosPassager(char name[],int lenName, char lastName[],int lenLastName, float* price, int* typePassanger, char flyCode[], int lenFlyCode, int* statusFlight);

int modificarPasajero(Passenger pArray[], int len, int idPassenger);
int findPassengerById(Passenger* list, int len,int id);

int removePassenger(Passenger* list, int len, int id);

#endif
