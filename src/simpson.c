#include "simpson.h"

/* Calcule l'intégrale de la fonction sinus sur le sous-intervalle [a; b] grâce
 * à la formule de Simpson. Utilisée dans la méthode de Simpson
 * @param double a : Valeur de la borne inférieure
 * @param double b : Valeur de la borne supérieure
 * @return Le résultat de l'intégrale
 */
double formuleSimpsonSinus(double a, double b){
	return ( (b-a)/6 ) * ( sin(a) + 4*sin((a+b)/2) + sin(b) );
}

/* Calcule une approximation de l'intégrale de la fonction sinus sur l'intervalle
 * [a; b] en faisant la somme des intégrales sur des sous-intervalles
 * @param double a : Valeur de la borne inférieure
 * @param double b : Valeur de la borne supérieure
 * @param double pas : Largeur d'un sous-intervalle
 * @return Le résultat du polyôme
 */
double methodeSimpsonSinus(double a, double b, double nbPts){
	
	double integrale = 0.0;
	double i = a;
	double pas = (b-a)/ (2*nbPts);
	
	while(i <= b){
		integrale += formuleSimpsonSinus(i, i+pas);
		i+=pas;
	}
	
	return integrale;
}


/* 
 * Même principe que formuleSimpsonSinus, mais pour la fonction racine
 * carrée du logarithme népérien
 */
double formuleSimpsonRacineLn(double a, double b){
	return ( (b-a)/6 ) * ( racineLn(a) + 4*racineLn((a+b)/2) + racineLn(b) );
}

/* 
 * Même principe que methodeSimpsonSinus, mais pour la fonction racine
 * carrée du logarithme népérien (utilise formuleSimpsonRacineLn)
 */
double methodeSimpsonRacineLn(double a, double b, double nbPts){
	
	double integrale = 0.0;
	double i = a;
	double pas = (b-a)/ (2*nbPts);
	
	while(i <= b){
		integrale += formuleSimpsonRacineLn(i, i+pas);
		i+=pas;
	}
	
	return integrale;
}


/* 
 * Même principe que formuleSimpsonSinus, mais pour la fonction sinus cube
 */
double formuleSimpsonSinusCube(double a, double b){
	return ( (b-a)/6 ) * ( sinusCube(a) + 4*sinusCube((a+b)/2) + sinusCube(b) );
}

/* 
 * Même principe que methodeSimpsonSinus, mais pour la fonction sinus cube
 * (utilise formuleSimpsonSinusCube)
 */
double methodeSimpsonSinusCube(double a, double b, double nbPts){
	
	double integrale = 0.0;
	double i = a;
	double pas = (b-a)/ (2*nbPts);
	
	while(i <= b){
		integrale += formuleSimpsonSinusCube(i, i+pas);
		i+=pas;
	}
	
	return integrale;
}


/* 
 * Même principe que formuleSimpsonSinus, mais pour la fonction inverse 
 * de tan(x) au cube
 */
double formuleSimpsonInverseTanExpQuatre(double a, double b){
	return ( (b-a)/6 ) * ( inverseTanExpQuatre(a) + 4*inverseTanExpQuatre((a+b)/2) + inverseTanExpQuatre(b) );
}

/* 
 * Même principe que methodeSimpsonSinus, mais pour la fonction inverse 
 * de tan(x) au cube (utilise formuleSimpsonInverseTanExpQuatre)
 */
double methodeSimpsonInverseTanExpQuatre(double a, double b, double nbPts){
	
	double integrale = 0.0;
	double i = a;
	double pas = (b-a)/ (2*nbPts);
	
	while(i <= b){
		integrale += formuleSimpsonInverseTanExpQuatre(i, i+pas);
		i+=pas;
	}
	
	return integrale;
}


/* 
 * Même principe que formuleSimpsonSinus, mais pour la fonction cos²(x)*exp(x)
 */
double formuleSimpsonCosCarreExp(double a, double b){
	return ( (b-a)/6 ) * ( cosCarreExp(a) + 4*cosCarreExp((a+b)/2) + cosCarreExp(b) );
}

/* 
 * Même principe que methodeSimpsonSinus, mais pour la fonction cos²(x)*exp(x)
 * (utilise formuleSimpsonCosCarreExp)
 */
double methodeSimpsonCosCarreExp(double a, double b, double nbPts){
	
	double integrale = 0.0;
	double i = a;
	double pas = (b-a)/ (2*nbPts);
	
	while(i <= b){
		integrale += formuleSimpsonCosCarreExp(i, i+pas);
		i+=pas;
	}
	
	return integrale;
}


/* 
 * Même principe que formuleSimpsonSinus, mais pour un polynôme
 * @param double coef[] : Tableau des coefficients du polynome
 * @param int degre : Degré du polynôme
 */
double formuleSimpsonPolynome(double a, double b, double coef[], int degre){
	return ( (b-a)/6 ) * ( polynome(a, coef, degre) + 4*polynome((a+b)/2, coef, degre) + polynome(b, coef, degre) );
}

/* 
 * Même principe que methodeSimpsonSinus, mais pour un polynôme (utilise
 * formuleSimpsonCosCarreExp)
 * @param double coef[] : Tableau des coefficients du polynome
 * @param int degre : Degré du polynôme
 */
double methodeSimpsonPolynome(double a, double b, double nbPts, double coef[], int degre){
	
	double integrale = 0.0;
	double i = a;
	double pas = (b-a)/ (2*nbPts);
	
	while(i <= b){
		integrale += formuleSimpsonPolynome(i, i+pas, coef, degre);
		i+=pas;
	}
	
	return integrale;
}

	
