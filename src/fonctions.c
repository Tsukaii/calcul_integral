#include "fonctions.h"

/*
 * @param double x : Valeur de x utilisée dans la fonction
 * @return Le sinus de x
 */
double sinus(double x){
	return sin(x);
}

/*
 * @param double x : Valeur de x utilisée dans la fonction
 * @return La racine carrée du logarithme népérien de x
 */
double racineLn(double x){
	return sqrt( log(x) );
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
	return 1/pow( tan(x), 4);
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

int main(){
	double bla[] = {2, 3, 4, 6, -8};
	double a = polynome(23, bla, 4);
	
	printf("%lf\n", a);
	
	return 0;
}


