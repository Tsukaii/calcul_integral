#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	int fonction = 0;
	int methode = 0;
	int saisieCorrecte = 0;
	double *polynome; //Tableau des coefficients du polynôme saisi par l'utilisateur
	int degre = 0; //Degré du polynôme saisi par l'utilisateur
	
	int cpt = 0; //Compteur de boucle
	
	printf("------------------------------------------\n");
	printf("Calcul de l'approximation d'une intégrale\n");
	printf("------------------------------------------\n");
	
	printf("Appuyer sur le numéro correspondant à votre choix\n");
	
	
	/***** Choix de la méthode à utiliser *****/
	while ( (methode != 1 && methode != 2) && (!saisieCorrecte) ) {
		printf("1. Utiliser la méthode Simpson\n");
		printf("2. Utiliser la méthode Gauss\n");
		printf("3. Quitter le programme\n\n");
		scanf("%d", &methode);
		
		if (methode != 1 && methode != 2 && methode != 3)
			printf("Choix incorrect, veuillez recommencer\n");
		else
			saisieCorrecte = 1;
	}
	
	saisieCorrecte = 0; //saisieCorrecte à faux pour vérifier la deuxième saisie clavier
	
	/***** Choix de la fonction à utiliser *****/
	printf("Voulez-vous maintenant\n");
	
	while ( (fonction != 1 && fonction != 2 && fonction != 3) && (!saisieCorrecte) ) {
		printf("1. Entrez le polynôme de votre choix\n");
		printf("2. Calculer l'approximation de l'intégrale d'une fonction prédéfinie\n\n");
		scanf("%d", &fonction);
		if (fonction != 1 && fonction != 2)
			printf("Choix incorrect, veuillez recommencer\n");
		else
			saisieCorrecte = 1;
	}
	
	//Traitement suivant la méthode à utiliser
	switch (methode) {
		case 1 :
			break;
		case 2 :
			//Liste d'instructions;
			break;
		case 3 :
			exit(0);
		default :
			printf("Choix incorrect");
	}
	
	//Traitement suivant la fonction à utiliser
	switch (fonction) {
		case 1 : //L'utilisateur entre son polynôme
			printf("Entrez le degré de votre polynôme\n");
			scanf("%d", &degre);
	
			polynome = malloc( sizeof(double)*degre ); //Déclaration du tableau de double dans le tas pour pouvoir ensuite le retourner
	
			for (cpt = 0; cpt<=degre; cpt++){
				printf("Saisissez le coefficicent du terme de degré %d\n", cpt);
				scanf("%lf", &polynome[cpt]);
			}
			break;
		case 2 :
			//Liste d'instructions;
			break;
		default :
			printf("Choix incorrect");
	}

	if (fonction == 1)
		free(polynome); //On libère l'espace mémoire du polynôme saisi par l'utilisateur
	
	return 0;
}
