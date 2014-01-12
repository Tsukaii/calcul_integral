#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	int fonction = 0;
	int methode = 0;
	int saisieCorrecte = 0; 
	
	printf("------------------------------------------\n");
	printf("Calcul de l'approximation d'une intégrale\n");
	printf("------------------------------------------\n");
	
	printf("Appuyer sur le numéro correspondant à votre choix\n");
	
	//Choix de la fonction à utiliser
	while ( (fonction != 1 && fonction != 2 && fonction != 3) && (!saisieCorrecte) ) {
		printf("1. Entrez le polynôme de votre choix\n");
		printf("2. Calculer l'approximation de l'intégrale d'une fonction prédéfinie\n");
		printf("3. Quitter le programme\n\n");
		scanf("%d", &fonction);
		if (fonction != 1 && fonction != 2 && fonction != 3)
			printf("Choix incorrect, veuillez recommencer\n");
		else
			saisieCorrecte = 1;
	}
	
	//Traitement suivant la fonction à utiliser
	switch (fonction) {
		case 1 :
			//Liste d'instructions;
			break;
		case 2 :
			//Liste d'instructions;
			break;
		case 3 :
			exit(0);
	}
	
	saisieCorrecte = 0; //saisieCorrecte à faux pour vérifier la deuxième saisie clavier
	
	//Choix de la méthode à utiliser
	printf("Voulez-vous maintenant\n");
	
	while ( (methode != 1 && methode != 2) && (!saisieCorrecte) ) {
		printf("1. Utiliser la méthode Simpson\n");
		printf("2. Utiliser la méthode Gauss\n\n");
		scanf("%d", &methode);
		
		if (methode != 1 && methode != 2)
			printf("Choix incorrect, veuillez recommencer\n");
		else
			saisieCorrecte = 1;
	}
	
	return 0;
}
