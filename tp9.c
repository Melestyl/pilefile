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
	int taille;
	char chaine[MAX];
	T_Elt testVar = 5; // Valeur test qui sert à tester les piles/files. A modifier si on change de type. !! DIFFERENT DE 0 !!
	// int taille;
	// char chaine[20];

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
				// permut(&mapile,chaine); //TP9 partie 2: ecrire permut
				printf("Entrer la chaine a permuter : ");
				scanf("%s", chaine);
				permutations(mapile, chaine);
				break;
			case 4:
				// scanf("%d",&taille);//taille echiquier <=MAX
				// echiquier(&mapile,taille); //TP9 partie 3: ecrire echiquier
				printf("Entrer la taille de l'échiquier : ");
				scanf("%d", &taille);
				echiquier(mapile, taille);
				break;
		}
	} while (chx != 0);

	printf("\nau plaisir de vous revoir ...\n");
	return 0;
}

void permutations(T_Pile mapile, char entree[]){
    T_Elt element;
	int compteur = 0;

    while(!depiler(&mapile, &element)); //Vidage de pile

    do {
        while (noeudValide(mapile)){
            if (mapile.nbElts == (int)strlen(entree)){
                afficherPile(&mapile);
				printf("\n");
				compteur++;
                break;
            } 
            else{
				element = 1;
                empiler(&mapile, &element);
				
			}
        }
        while (mapile.nbElts != 0 && sommet(&mapile) == (int)strlen(entree)){
            depiler(&mapile, &element);
        }
        

        if (!mapile.nbElts == 0){
            depiler(&mapile, &element);
			element++;
            empiler(&mapile, &element);
        }
    } while (!mapile.nbElts == 0);
	printf("\nIl y a %d solution(s)\n", compteur);
}


void echiquier(T_Pile mapile, int taille){
	T_Elt element;	
	//Ça marche puisqu'avait une taille de 8 on obtient 92 solutions :)
	int compteur = 0;

    while(!depiler(&mapile, &element)); //Vidage de pile

    do {
        while (reineValide(mapile)){
            if (mapile.nbElts == taille){
                afficherPile(&mapile);
				printf("\n");
				compteur++;
                break;
            }
            else{
				element = 1;
                empiler(&mapile, &element);
				
			}
        }
        while (mapile.nbElts != 0 && sommet(&mapile) == taille){
            depiler(&mapile, &element);
        }
        

        if (!mapile.nbElts == 0){
            depiler(&mapile, &element);
			element++;
            empiler(&mapile, &element);
        }
    } while (!mapile.nbElts == 0);
	printf("\nIl y a %d solution(s)\n", compteur);
}

int noeudValide(T_Pile mapile){
	int compteur;
	for (int i = 0; i < mapile.nbElts; i++) {
		compteur = 0;
		for (int j = 0; j < mapile.nbElts; j++) {
			if (mapile.Elts[j] == mapile.Elts[i]) compteur++;
			if (compteur > 1) return 0;
		}
	}
	return 1;
}

int reineValide(T_Pile mapile){
	int compteur;
	for (int i = 0; i < mapile.nbElts; i++) {
		compteur = 0;
		for (int j = 0; j < mapile.nbElts; j++) {
			if (mapile.Elts[j] == mapile.Elts[i]) compteur++;
			if (compteur > 1) return 0;
		}
	}

	for (int i = 0; i < mapile.nbElts; i++){
		for (int j = 0; j < mapile.nbElts; j++){
			if (((mapile.Elts[j] == mapile.Elts[i] - (i-j)) || (mapile.Elts[i] + i-j ==  mapile.Elts[j])) && i!=j)
				return 0;
		}
	}
	return 1;
}