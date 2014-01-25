#include "fonctions.h"

/*
 * @param double x : Valeur de x utilisée dans la fonction
 * @return La racine carrée du logarithme népérien de x
 */
double racineLn(double x){
	double valeur = 0.0;
	if (x <= 0)
		printf("Valeur interdite !\n");
	else
		valeur = sqrt( log(x) );
		
	return valeur;
}

/*
 * @param double x : Valeur de x utilisée dans la fonction
 * @return Le sinus au cube de x
 */
double sinusCube(double x){
	return pow( sin(x), 3);
}

/*
 * @param double x : Valeur de x utilisée dans la fonction
 * @return L'inverse de tan(x) au cube
 */
double inverseTanExpQuatre(double x){
	double valeur = 0.0;
	if (x == 0.0)
		printf("Valeur interdite !\n");
	else
		valeur = 1/pow( tan(x), 4);
		
	return valeur;
}

/*
 * @param double x : Valeur de x utilisée dans la fonction
 * @return Le produit cos²(x)*exp(x)
 */
double cosCarreExp(double x){
	return pow( cos(x), 2 )* exp(x);
}

/*
 * @param double x : Valeur de x utilisée dans la fonction
 * @param double coef[] : Tableau des coefficients du polynome
 * @return Le résultat du polyôme
 */
double polynome(double x, double coef[], int degre){
	int cpt;
	double polynome = 0;
	for (cpt = 0; cpt <= degre; cpt++)
		polynome += ( coef[cpt] * pow(x, cpt) );
	
	return polynome;
}

