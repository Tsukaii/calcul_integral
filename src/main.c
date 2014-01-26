#include <stdio.h>
#include <stdlib.h>
#include "simpson.h"
#include "romberg.h"

//Options du menu des fonctions
#define POLYNOME 1
#define SINUS 2
#define RACINELN 3
#define SINUSCUBE 4
#define INVTAN4 5
#define COS2EXP 6
#define QUIT 7

#define NBCHOIX 7

//Précision utilisée pour la méthode de Romberg
#define PREC 15

int main(int argc, char *argv[]){
	int fonction = 0;
	int saisieCorrecte = 0;
	double *polynome = NULL; //Tableau des coefficients du polynôme saisi par l'utilisateur
	int degre = 0; //Degré du polynôme
	
	int cpt = 0; //Compteur de boucle
	
	double integrale_s = 0.0; //Intégrale calculée avec la méthode Simpson
	double integrale_r = 0.0; //Intégrale calculée avec la méthode Romberg
	
	double temp = 0.0; //Variable temporaire utilisé pour la vérification des bornes
	double borneInf = 0.0; //Borne inférieure de l'intervalle
	double borneSup = 0.0; //Borne inférieure de l'intervalle
	int nbPts = 0; //Nombre de sous-intervalles
	
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
		printf("  %d. ln(x)^1/2\n", RACINELN);
		printf("  %d. sin³(x)\n", SINUSCUBE);
		printf("  %d. 1/tan⁴(x)\n", INVTAN4);
		printf("  %d. cos²(x)*exp(x)\n", COS2EXP);
		printf("  %d. Quitter le programme\n\n", QUIT);
		
		printf("Votre choix : ");
		scanf("%d", &fonction);
		
		if (fonction > NBCHOIX || fonction < 1)
			printf("Choix incorrect, veuillez recommencer\n\n");
		else
			saisieCorrecte = 1;
	}
	
	if (fonction == QUIT){
		printf("Au revoir !\n\n");
		exit(1);
	}
	
	//Saisie des bornes et du nombre de sous-intervalles
	printf("Veuillez maintenant entrer les bornes de l'intervalle sur lequel vous voulez intégrer, ainsi que le nombre de sous-intervalles\n");
	printf("Borne inférieure : ");
	scanf("%lf", &borneInf);
	printf("Borne supérieure : ");
	scanf("%lf", &borneSup);
	
	if (borneSup < borneInf){
		temp = borneSup;
		borneSup = borneInf;
		borneInf = temp;
	}
	
	printf("Nombre de sous-intervalles (valeur max conseillée = 1 000 000) : ");
	scanf("%d", &nbPts);
	
	//Traitement suivant la fonction à utiliser
	switch (fonction) {
		case POLYNOME : //L'utilisateur entre son polynôme
			printf("\nEntrez le degré de votre polynôme : ");
			scanf("%d", &degre);
			while(degre < 0){ //Tant que l'utilisateur n'entre pas un degré > 0, le programme lui demande de le saisir à nouveau
				printf("Degré de polynôme incorrect\n");
				printf("Entrez le degré de votre polynôme : ");
				scanf("%d", &degre);
			}
			
			polynome = malloc( sizeof(double)* (degre + 1) );

			for (cpt = 0; cpt<=degre; cpt++){
				printf("Saisissez le coefficicent du terme de degré %d\n", cpt);
				scanf("%lf", &polynome[cpt]);
			}
			
			integrale_s = methodeSimpsonPolynome(borneInf, borneSup, nbPts, polynome, degre);
			integrale_r = methodeRombergPolynome(borneInf, borneSup, PREC, PREC, polynome, degre);
			
			break;
			
		case SINUS :
			integrale_s = methodeSimpsonSinus(borneInf, borneSup, nbPts);
			integrale_r = methodeRombergSinus(borneInf, borneSup, PREC, PREC);
			break;
			
		case RACINELN :
			if (borneInf <= 0 || borneSup <= 0)
				printf("Votre intervalle contient une valeur interdite !\n");
			else{
				integrale_s = methodeSimpsonRacineLn(borneInf, borneSup, nbPts);
				integrale_r = methodeRombergRacineLn(borneInf, borneSup, PREC, PREC);
			}
			break;
			
		case SINUSCUBE :
			integrale_s = methodeSimpsonSinusCube(borneInf, borneSup, nbPts);
			integrale_r = methodeRombergSinusCube(borneInf, borneSup, PREC, PREC);
			break;
		
		case INVTAN4 :
			if (borneInf <= 0 && borneSup >= 0)
				printf("Votre intervalle contient une valeur interdite !\n");
			else{
				integrale_s = methodeSimpsonInverseTanExpQuatre(borneInf, borneSup, nbPts);
				integrale_r = methodeRombergInverseTanExpQuatre(borneInf, borneSup, PREC, PREC);
			}
			break;
			
		case COS2EXP :
			integrale_s = methodeSimpsonCosCarreExp(borneInf, borneSup, nbPts);
			integrale_r = methodeRombergCosCarreExp(borneInf, borneSup, PREC, PREC);
			break;
			
		default :
			printf("Choix incorrect");
	}

	if (fonction == POLYNOME)
		free(polynome); //Libération de l'espace mémoire du polynôme saisi par l'utilisateur
		
	printf("\nL'intégrale de votre fonction, calculée avec la méthode Simpson, vaut %g\n", integrale_s);
	printf("L'intégrale de votre fonction, calculée avec la méthode Romberg, vaut %g\n", integrale_r);

	return 0;
}
