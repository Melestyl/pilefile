// SDA1 TP 9 PILE de TAD (PILE d'ELEMENT)

#include "tp9.h"

int menu() {
	int choix;

	printf("\n\n\n SDA1 TP9, LAFFRA Timothee et TELLIER--CALOONE Tom");
	printf("\n\n\n 1 : tester mon fichier file.c");
	printf("\n 2 : tester mon fichier pile.c");
	printf("\n 3 : afficher et compter les permutations d'une chaine");
	printf("\n 4 : afficher et compter les solutions pour un échiquier ");
	printf("\n 0 :  QUITTER  ");
	printf("\n votre choix ?  ");
	scanf("%d", &choix);

	return choix;
}

int main() {
	T_File mafile;
	T_Pile mapile;
	int chx;
	T_Elt testVar = 1; // Valeur test qui sert à tester les piles/files. A modifier si on change de type. !! DIFFERENT DE 0 !!
	// int taille;
	// char chaine[20];

	testVar = 1;
	empiler(&mapile, &testVar);
	testVar = 2;
	empiler(&mapile, &testVar);
	testVar = 3;
	empiler(&mapile, &testVar);
	testVar = 2;
	empiler(&mapile, &testVar);
	testVar = 5;
	empiler(&mapile, &testVar);
	printf("\n%d", noeudValide(mapile));

	do {
		chx = menu();
		switch (chx) {
			case 1:
				// testez toutes vos fonctions par un jeu de test de votre choix
				testFile(&mafile, &testVar);
				break;
			case 2: // testez toutes vos fonctions par un jeu de test de votre choix
				testPile(&mapile, &testVar); //TP9 partie 1 : à ecrire
				break;
			case 3:
				// scanf("%s",chaine); //une chaine de longueur <=MAX
				// permut(&mapiless,chaine); //TP9 partie 2: ecrire permut
				break;
			case 4:
				// scanf("%d",&taille);//taille echiquier <=MAX
				// echiquier(&mapile,taille); //TP9 partie 3: ecrire echiquier
				break;
		}
	} while (chx != 0);

	printf("\nau plaisir de vous revoir ...\n");
	return 0;
}


int noeudValide(T_Pile mapile){
	int i, y; //Boucleurs
	printf("nb element truc : %d", mapile.nbElts);
	if (mapile.nbElts == 0)
		return 1;


	for(i = mapile.nbElts-1; i >= 0; i--){
		for(y = 0; y < i; y++){
			/* printf("\nElement 1: ");
			afficherElt(&mapile.Elts[i]);
			printf("\nElement 2: ");
			afficherElt(&mapile.Elts[y]);
			printf("\n---"); */
			if(mapile.Elts[i] == mapile.Elts[y]){
				return 0;
			}
		}
	}
	return 1;
}

void permutations(T_Pile mapile, int entree){
	T_Elt element = 69; // Poubelle


	int compteur = 0;
	int i = 0;
	int nbCombi = factorial(entree);

	while(!depiler(&mapile, &element)); //Vidage de pile
	printf("oui");
	do{
		printf("\nNb : %d\n", mapile.nbElts);
		while (noeudValide(mapile)){
			printf("oui\n");
			if(mapile.nbElts == entree){
				for(i = 0; i < mapile.nbElts; i++)
					afficherElt(&mapile.Elts[i]);
				compteur++;
				break;
			}
			else{
				element = 0;
				empiler(&mapile, &element);
				break;
			}
		}
		while(compteur < nbCombi && mapile.Elts[mapile.nbElts] == mapile.nbElts - 1){
			depiler(&mapile, &element);
		}
		while (compteur < nbCombi){
			depiler(&mapile, &element);
			element += 1;
			empiler(&mapile, &element);
		}
	}while (mapile.nbElts != 0);
}