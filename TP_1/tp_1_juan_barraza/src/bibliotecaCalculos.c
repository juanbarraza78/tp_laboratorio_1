/*
 * calculos.c
 *
 *  Created on: 15 abr. 2022
 *      Author: juanb
 */

#include <stdio.h>
#include <stdlib.h>

int hacerDescuentoflotante(float numeroIngresado, float porcentajeDeDescuento,float* pResultado){
	float auxiliar;
	int retorno;
	retorno = -1;
	if(pResultado != NULL && porcentajeDeDescuento > 0 && porcentajeDeDescuento <= 100 && numeroIngresado > 0){
		auxiliar = (1 - porcentajeDeDescuento/100)*numeroIngresado;
		*pResultado = auxiliar;
		retorno = 0;
	}
	return retorno;
}

int hacerInteresflotante(float numeroIngresado, float porcentajeDeInteres,float* pResultado){
	float auxiliar;
	int retorno;
	retorno = -1;
	if(pResultado != NULL && porcentajeDeInteres > 0 && numeroIngresado > 0){
		auxiliar = (1 + porcentajeDeInteres/100)*numeroIngresado;
		*pResultado = auxiliar;
		retorno = 0;
	}
	return retorno;
}

int convertirFloatABitcoin(float numeroIngresado,float* pResultado){
	float auxiliar;
	int retorno;
	retorno = -1;
	if(pResultado != NULL && numeroIngresado > 0){
		auxiliar= numeroIngresado / 4606954.55;
		*pResultado = auxiliar;
		retorno = 0;
	}
	return retorno;
}

int dividirFloatInt(float numeroDividendo, int numeroDivisor,float* pResultado){
	float auxiliar;
	int retorno;
	retorno = -1;
	if(pResultado != NULL && numeroDivisor != 0 ){
		auxiliar = numeroDividendo / numeroDivisor;
		*pResultado = auxiliar;
		retorno = 0;
	}
	return retorno;
}

int buscarDiferenciaPositivos(float numeroUno, float numeroDos,float* pResultado){
	float auxiliar;
	int retorno;
	retorno = -1;
	if(pResultado != NULL && numeroUno >= 0 && numeroDos >= 0){
		if(numeroUno > numeroDos){
		auxiliar = numeroUno - numeroDos;
		}
		else{
			auxiliar = numeroDos- numeroUno;
		}
		*pResultado = auxiliar;
		retorno = 0;
	}
	return retorno;
}

