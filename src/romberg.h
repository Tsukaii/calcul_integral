#ifndef ROMBERG_H
#define ROMBERG_H

	#include <stdio.h>
	#include <math.h>
	#include "fonctions.h"
	#include "trapeze.h"

	double methodeRombergSinus(double a, double b, double i, double precision);
	
	double methodeRombergRacineLn(double a, double b, double i, double precision);
	
	double methodeRombergSinusCube(double a, double b, double i, double precision);
	
	double methodeRombergInverseTanExpQuatre(double a, double b, double i, double precision);
	
	double methodeRombergCosCarreExp(double a, double b, double i, double precision);
	
	double methodeRombergPolynome(double a, double b, double i, double precision, double coef[], int degre);
	
#endif
