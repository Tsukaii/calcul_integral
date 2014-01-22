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

#define NBCHOIX 6

int main(int argc, char *argv[]){
	int fonction = 0;
	int saisieCorrecte = 0;
	double *polynome = NULL; //Tableau des coefficients du polynôme saisi par l'utilisateur
	int degre = 0; //Degré du polynôme
	
	int cpt = 0; //Compteur de boucle
	
	double integrale_s = 0.0; //Intégrale calculée avec la méthode Simpson
	double integrale_r = 0.0; //Intégrale calculée avec la méthode Romberg
	
	double borneInf = 0.0; //Borne inférieure de l'intervalle
	double borneSup = 0.0; //Borne inférieure de l'intervalle
	double pas = 0.0; //Largeur d'un sous-intervalle
	
	printf("\n--------------------------------------------------------\n");
	printf("-      Calcul de l'approximation d'une intégrale       -\n");
	printf("--------------------------------------------------------\n\n");
	
	printf("Appuyer sur le numéro correspondant à votre choix\n");
	
	
	//Choix de la fonction à utiliser
	while ( (fonction > NBCHOIX || fonction < 1) && (!saisieCorrecte) ) {
		printf("\nVoulez-vous :\n\n");
		printf("  %d. Entrez le polynôme de votre choix\n\n", POLYNOME);
		printf("...ou calculer l'intégrale d'une fonction prédéfinie : \n\n");
		printf("  %d. sin(x)\n", SINUS);
		printf("  %d. racine carrée de ln(x)\n", RACINELN);
		printf("  %d. sin³(x)\n", SINUSCUBE);
		printf("  %d. 1/tan⁴(x)\n", INVTAN4);
		printf("  %d. cos²(x)*exp(x)\n\n", COS2EXP);
		
		printf("Votre choix : ");
		scanf("%d", &fonction);
		
		if (fonction > NBCHOIX || fonction < 1)
			printf("Choix incorrect, veuillez recommencer\n\n");
		else
			saisieCorrecte = 1;
	}
	
	//Saisie des bornes et du pas
	printf("Veuillez maintenant entrer les bornes de l'intervalle sur lequel vous voulez intégrer, ainsi que le pas (largeur d'un sous-intervalle)\n");
	printf("Borne inférieure : ");
	scanf("%lf", &borneInf);
	printf("Borne supérieure : ");
	scanf("%lf", &borneSup);
	printf("Pas : ");
	scanf("%lf", &pas);
	
	//Traitement suivant la fonction à utiliser
	switch (fonction) {
		case POLYNOME : //L'utilisateur entre son polynôme
			printf("Entrez le degré de votre polynôme : ");
			scanf("%d", &degre);
			polynome = malloc( sizeof(double)* (degre + 1) );

			for (cpt = 0; cpt<=degre; cpt++){
				printf("Saisissez le coefficicent du terme de degré %d\n", cpt);
				scanf("%lf", &polynome[cpt]);
			}
			
			integrale_s = methodeSimpsonPolynome(borneInf, borneSup, pas, polynome, degre);
			
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
		
	printf("L'intégrale de votre fonction, calculée avec la méthode Simpson, vaut %g\n", integrale_s);
	printf("L'intégrale de votre fonction, calculée avec la méthode Romberg, vaut %g\n", integrale_r);
	
	return 0;
}
