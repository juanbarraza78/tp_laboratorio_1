/*
 * Biblioteca.h
 *
 *  Created on: 13 abr. 2022
 *      Author: juanb
 */

#ifndef BIBLIOTECAUTN_H_
#define BIBLIOTECAUTN_H_

/**
* \brief Solicita un número entero al usuario y lo valida
* \param pResultado Se carga el numero ingresado
* \param mensaje Es el mensaje a ser mostrado
* \param mensajeError Es el mensaje a ser mostrado en caso de error
* \param minimo Limite inferior a validar
* \param maximo Limite superior a validar
* \param reintentos es el numero de reintentos que tiene el usuario
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int utn_getInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);


/**
* \brief Solicita un número flotante al usuario y lo valida
* \param pResultado Se carga el numero ingresado
* \param mensaje Es el mensaje a ser mostrado
* \param mensajeError Es el mensaje a ser mostrado en caso de error
* \param minimo Limite inferior a validar
* \param maximo Limite superior a validar
* \param reintentos es el numero de reintentos que tiene el usuario
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int utn_getFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);


/**
* \brief Solicita un caracter al usuario y lo valida
* \param pResultado Se carga el caracter
* \param mensaje Es el mensaje a ser mostrado
* \param mensajeError Es el mensaje a ser mostrado en caso de error
* \param minimo Limite inferior a validar
* \param maximo Limite superior a validar
* \param reintentos es el numero de reintentos que tiene el usuario
* \return Si obtuvo el caracter [0] si no [-1]
*
*/
int utn_getChar(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);

#endif /* BIBLIOTECAUTN_H_ */
