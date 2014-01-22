#include <stdio.h>
#include <stdlib.h>
#include "simpson.h"

//Options du menu des fonctions
#define POLYNOME 1
#define SINUS 2
#define RACINELN 3
#define SINUSCUBE 4
#define INVTAN4 5
#define COS2EXP 6

double* saisiePolynome(){
	int degre = 0;
	int cpt;
	double *polynome;
	
	printf("Entrez le degré de votre polynôme\n");
	scanf("%d", &degre);

	polynome = malloc( sizeof(double)* (degre + 1) ); //Déclaration du tableau de coef dans le tas pour pouvoir ensuite le retourner

	for (cpt = 0; cpt<=degre; cpt++){
		printf("Saisissez le coefficicent du terme de degré %d\n", cpt);
		scanf("%lf", &polynome[cpt]);
	}
	
	return polynome;
}

int main(int argc, char *argv[]){
	int fonction = 0;
	int saisieCorrecte = 0;
	double *polynome; //Tableau des coefficients du polynôme saisi par l'utilisateur
	
	double integrale_s = 0.0; //Intégrale calculée avec la méthode Simpson
	double integrale_r = 0.0; //Intégrale calculée avec la méthode Romberg
	
	double borneInf = 0.0; //Borne inférieure de l'intervalle
	double borneSup = 0.0; //Borne inférieure de l'intervalle
	double pas = 0.0; //Largeur d'un sous-intervalle
	
	printf("------------------------------------------\n");
	printf("Calcul de l'approximation d'une intégrale\n");
	printf("------------------------------------------\n");
	
	printf("Appuyer sur le numéro correspondant à votre choix\n");
	
	
	/***** Choix de la fonction à utiliser *****/
	printf("\nVoulez-vous\n");
	
	while ( (fonction != POLYNOME && fonction != SINUS && fonction != RACINELN && fonction != SINUSCUBE
		&& fonction != INVTAN4 && fonction != COS2EXP) && (!saisieCorrecte) ) {
			
		printf("%d. Entrez le polynôme de votre choix\n\n", POLYNOME);
		printf("...ou calculer l'intégrale d'une fonction prédéfinie : \n");
		printf("%d. sin(x)\n", SINUS);
		printf("%d. racine carrée de ln(x)\n", RACINELN);
		printf("%d. sin³(x)\n", SINUSCUBE);
		printf("%d. 1/tan⁴(x)\n", INVTAN4);
		printf("%d. cos²(x)*exp(x)\n", COS2EXP);
		scanf("%d", &fonction);
		
		if ((fonction != POLYNOME && fonction != SINUS && fonction != RACINELN && fonction != SINUSCUBE
			&& fonction != INVTAN4 && fonction != COS2EXP))
			printf("Choix incorrect, veuillez recommencer\n\n");
		else
			saisieCorrecte = 1;
	}
	
	/*printf("Veuillez maintenant entrer les bornes de l'intervalle sur lequel vous voulez intégrer, ainsi que le pas (largeur d'un sous-intervalle)\n");
	printf("Borne inférieure :");
	scanf("");*/
	
	//Traitement suivant la fonction à utiliser
	switch (fonction) {
		case POLYNOME : //L'utilisateur entre son polynôme
			polynome = saisiePolynome();
			break;
			
		case SINUS :
			integrale_s = methodeSimpsonSinus(borneInf, borneSup, pas);
			break;
			
		case RACINELN :
			integrale_s = methodeSimpsonRacineLn(borneInf, borneSup, pas);
			break;
			
		case SINUSCUBE :
			integrale_s = methodeSimpsonSinusCube(borneInf, borneSup, pas);
			break;
		
		case INVTAN4 :
			integrale_s = methodeSimpsonInverseTanExpQuatre(borneInf, borneSup, pas);
			break;
			
		case COS2EXP :
			integrale_s = methodeSimpsonCosCarreExp(borneInf, borneSup, pas);
			break;
			
		default :
			printf("Choix incorrect");
	}

	if (fonction == POLYNOME)
		free(polynome); //Libération de l'espace mémoire du polynôme saisi par l'utilisateur
		
	printf("L'intégrale de votre fonction, calculée avec la méthode Simpson, vaut %g", integrale_s);
	
	return 0;
}
