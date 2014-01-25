#include "romberg.h"

/* Calcule l'intégrale de la fonction sinus sur le sous-intervalle [a; b] 
 * grâce à la méthode de Romberg. Utilise methodeTrapezeSinus
 * @param double a : Valeur de la borne inférieure
 * @param double b : Valeur de la borne supérieure
 * @param i : Utilisé pour la précision de la méthode
 * @param precision: Précision de la méthode (utilisé pour calculer le 
 * nombre de sous-intervalles)
 * @return Le résultat de l'intégrale
 */
double methodeRombergSinus(double a, double b, double i, double precision){
	if (i <= 0)
		return methodeTrapezeSinus(a, b, pow(2, precision) );
	else
		return ( pow(4, i) * methodeRombergSinus(a, b, i-1, precision) - methodeRombergSinus(a, b, i-1, precision-1) ) / ( pow(4, i) - 1 );
}


/* 
 * Même principe que methodeRombergSinus, mais pour la fonction racine
 * carrée du logarithme népérien
 */
double methodeRombergRacineLn(double a, double b, double i, double precision){
	if (i <= 0)
		return methodeTrapezeRacineLn(a, b, pow(2, precision) );
	else
		return ( pow(4, i) * methodeRombergRacineLn(a, b, i-1, precision) - methodeRombergRacineLn(a, b, i-1, precision-1) ) / ( pow(4, i) - 1 );
}


/* 
 * Même principe que methodeRombergSinus, mais pour la fonction sinus
 * cube
 */
double methodeRombergSinusCube(double a, double b, double i, double precision){
	if (i <= 0)
		return methodeTrapezeSinusCube(a, b, pow(2, precision) );
	else
		return ( pow(4, i) * methodeRombergSinusCube(a, b, i-1, precision) - methodeRombergSinusCube(a, b, i-1, precision-1) ) / ( pow(4, i) - 1 );
}


/* 
 * Même principe que methodeRombergSinus, mais pour la fonction inverse 
 * de tan(x) au cube
 */
double methodeRombergInverseTanExpQuatre(double a, double b, double i, double precision){
	if (i <= 0)
		return methodeTrapezeInverseTanExpQuatre(a, b, pow(2, precision) );
	else
		return ( pow(4, i) * methodeRombergInverseTanExpQuatre(a, b, i-1, precision) - methodeRombergInverseTanExpQuatre(a, b, i-1, precision-1) ) / ( pow(4, i) - 1 );
}


/* 
 * Même principe que methodeRombergSinus, mais pour la fonction cos²(x)*exp(x)
 */
double methodeRombergCosCarreExp(double a, double b, double i, double precision){
	if (i <= 0)
		return methodeTrapezeCosCarreExp(a, b, pow(2, precision) );
	else
		return ( pow(4, i) * methodeRombergCosCarreExp(a, b, i-1, precision) - methodeRombergCosCarreExp(a, b, i-1, precision-1) ) / ( pow(4, i) - 1 );
}


/* 
 * Même principe que methodeRombergSinus, mais pour un polynôme
 * @param double coef[] : Tableau des coefficients du polynome
 * @param int degre : Degré du polynôme
 */
double methodeRombergPolynome(double a, double b, double i, double precision, double coef[], int degre){
	if (i <= 0)
		return methodeTrapezePolynome(a, b, pow(2, precision), coef, degre );
	else
		return ( pow(4, i) * methodeRombergPolynome(a, b, i-1, precision, coef, degre) - methodeRombergPolynome(a, b, i-1, precision-1, coef, degre) ) / ( pow(4, i) - 1);
}
