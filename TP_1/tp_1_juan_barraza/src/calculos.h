/*
 * calculos.h
 *
 *  Created on: 15 abr. 2022
 *      Author: juanb
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

int hacerDescuentoflotante(float numeroIngresado, float porcentajeDeDescuento,float* pResultado);

int hacerInteresflotante(float numeroIngresado, float porcentajeDeInteres,float* pResultado);

int convertirFloatABitcoin(float numeroIngresado,float* pResultado);

int dividirFloatInt(float numeroDividendo, int numeroDivisor,float* pResultado);

int buscarDiferenciaPositivos(float numeroUno, float numeroDos,float* pResultado);

#endif /* CALCULOS_H_ */
