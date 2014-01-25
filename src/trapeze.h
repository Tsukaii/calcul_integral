#ifndef TRAPEZE_H
#define TRAPEZE_H

	#include <math.h>
	#include <stdio.h>
	#include "fonctions.h"

	double methodeTrapezeSinus(double a, double b, double nbPts);
	
	double methodeTrapezeRacineLn(double a, double b, double nbPts);
	
	double methodeTrapezeSinusCube(double a, double b, int nbPts);
	
	double methodeTrapezeInverseTanExpQuatre(double a, double b, int nbPts);
	
	double methodeTrapezeCosCarreExp(double a, double b, int nbPts);
	
	double methodeTrapezePolynome(double a, double b, int nbPts, double coef[], int degre);
	
#endif
