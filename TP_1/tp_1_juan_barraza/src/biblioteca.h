/*
 * Biblioteca.h
 *
 *  Created on: 13 abr. 2022
 *      Author: juanb
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

int utn_getInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

int utn_getFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);

int utn_getChar(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);

#endif /* BIBLIOTECA_H_ */
