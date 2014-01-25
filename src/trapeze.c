#include "trapeze.h"

/* Calcule l'intégrale de la fonction sinus sur l'intervalle [a; b] grâce
 * à la méthode des trapèze
 * @param double a : Valeur de la borne inférieure
 * @param double b : Valeur de la borne supérieure
 * @param int nbPts : Nombre de sous-intervalles
 * @return Le résultat de l'intégrale
 */
double methodeTrapezeSinus(double a, double b, double nbPts){
	double pas = (b-a)/nbPts;
	double integrale = ( sin(a) + sin(b) )/2;
	
	double cpt;
	
	for (cpt=a; cpt <= b+pas; cpt+=pas)
		integrale += sin(cpt);
	
	return integrale*pas;
}

/* 
 * Même principe que methodeTrapezeSinus, mais pour la fonction racine
 * carrée du logarithme népérien
 */
double methodeTrapezeRacineLn(double a, double b, double nbPts){
	double pas = (b-a)/nbPts; 
	double integrale = 0; 
	double cpt;
	
	for (cpt=a; cpt <= b+pas; cpt+=pas)
		integrale += racineLn(cpt);
	
	return integrale*pas;
}


/* 
 * Même principe que methodeTrapezeSinus, mais pour la fonction sinus cube
 */
double methodeTrapezeSinusCube(double a, double b, int nbPts){
	double pas = (b-a)/nbPts;
	double integrale = ( sinusCube(a) + sinusCube(b) )/2;
	double cpt;
	
	for (cpt=a; cpt <= b+pas; cpt+=pas)
		integrale += sinusCube(cpt);
	
	return integrale*pas;
}

/* 
 * Même principe que methodeTrapezeSinus, mais pour la fonction inverse 
 * de tan(x) au cube
 */
double methodeTrapezeInverseTanExpQuatre(double a, double b, int nbPts){
	double pas = (b-a)/nbPts;
	double integrale = ( inverseTanExpQuatre(a) + inverseTanExpQuatre(b) )/2;
	double cpt;
	
	for (cpt=a; cpt <= b+pas; cpt+=pas)
		integrale += inverseTanExpQuatre(cpt);

	return integrale*pas;
}

/* 
 * Même principe que methodeTrapezeSinus, mais pour la fonction cos²(x)*exp(x)
 */
double methodeTrapezeCosCarreExp(double a, double b, int nbPts){
	double pas = (b-a)/nbPts;
	double integrale = ( cosCarreExp(a) + cosCarreExp(b) )/2;
	double cpt;
	
	for (cpt=a; cpt <= b+pas; cpt+=pas)
		integrale += cosCarreExp(cpt);
	
	return integrale*pas;
}

/* 
 * Même principe que methodeTrapezeSinus, mais pour un polynôme
 * @param double coef[] : Tableau des coefficients du polynome
 * @param int degre : Degré du polynôme
 */
double methodeTrapezePolynome(double a, double b, int nbPts, double coef[], int degre){
	double pas = (b-a)/nbPts;
	double integrale = ( polynome(a, coef, degre) + polynome(b, coef, degre) )/2;
	double cpt;
	
	for (cpt=a; cpt <= b+pas; cpt+=pas)
		integrale += polynome(cpt, coef, degre);
	
	return integrale*pas;
}
