/*
 * calculos.h
 *
 *  Created on: 15 abr. 2022
 *      Author: juanb
 */

#ifndef BIBLIOTECACALCULOS_H_
#define BIBLIOTECACALCULOS_H_


/**
* \brief Solicita un número y un porcentaje de descuento y te lo calcula
* \param numeroIngresado Se carga el numero ingresado
* \param porcentajeDeDescuento Es el porsentaje a descontar
* \param pResultado es el resultado
* \return Si obtuvo un problema es [-1] si no [0]
*
*/
int hacerDescuentoflotante(float numeroIngresado, float porcentajeDeDescuento,float* pResultado);


/**
* \brief Solicita un número y un porcentaje de interes y te lo calcula
* \param numeroIngresado Se carga el numero ingresado
* \param porcentajeDeInteres Es el porsentaje a sumar
* \param pResultado es el resultado
* \return Si obtuvo un problema es [-1] si no [0]
*
*/
int hacerInteresflotante(float numeroIngresado, float porcentajeDeInteres,float* pResultado);


/**
* \brief Solicita un número tipo flotante al usuario y lo convierte a bitcoin
* \param input Se carga el numero ingresado
* \param pResultado es el resultado
* \return Si obtuvo un problema es [-1] si no [0]
*
*/
int convertirFloatABitcoin(float numeroIngresado,float* pResultado);


/**
* \brief Solicita dos numeros y obtiene el resultado de la divicion
* \param numeroDividendo es el dividendo del calculo
* \param numeroDivisor es el divisor del calculo
* \param pResultado es el resultado
* \return Si obtuvo un problema es [-1] si no [0]
*
*/
int dividirFloatInt(float numeroDividendo, int numeroDivisor,float* pResultado);


/**
* \brief Solicita dos numeros y obtiene la diferencia entre los dos numeros
* \param numeroUno primer numero ingresado
* \param numeroDos segundo numero ingresado
* \param pResultado es el resultado
* \return Si obtuvo un problema es [-1] si no [0]
*
*/
int buscarDiferenciaPositivos(float numeroUno, float numeroDos,float* pResultado);

#endif /* BIBLIOTECACALCULOS_H_ */
