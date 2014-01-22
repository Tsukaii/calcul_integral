#ifndef SIMPSON_H
#define SIMPSON_H

	#include <math.h>
	#include <stdio.h>
	#include "fonctions.h"

	double formuleSimpsonSinus(double a, double b);
	double methodeSimpsonSinus(double a, double b, double pas);
	
	double formuleSimpsonRacineLn(double a, double b);
	double methodeSimpsonRacineLn(double a, double b, double pas);
	
	double formuleSimpsonSinusCube(double a, double b);
	double methodeSimpsonSinusCube(double a, double b, double pas);
	
	double formuleSimpsonInverseTanExpQuatre(double a, double b);
	double methodeSimpsonInverseTanExpQuatre(double a, double b, double pas);
	
	double formuleSimpsonCosCarreExp(double a, double b);
	double methodeSimpsonCosCarreExp(double a, double b, double pas);

#endif
