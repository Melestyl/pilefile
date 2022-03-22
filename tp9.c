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
				break;
		}
	} while (chx != 0);

	printf("\nau plaisir de vous revoir ...\n");
	return 0;
}

void permutations(T_Pile mapile, char entree[]){
    T_Elt element;

    while(!depiler(&mapile, &element)); //Vidage de pile

    do {
        printf("Temp\n");
        while (noeudValide(mapile)){
            printf("Temp2\n");
            if (mapile.nbElts == strlen(entree)){
                afficherPile(&mapile);
                break;
            } 
            else
                empiler(&mapile, 0);
        }
        
        while (mapile.nbElts == 0 && sommet(&mapile) == strlen(entree)){
            printf("Temp3\n");
            depiler(&mapile, &element);
        }
        printf("Temp4\n");

        if (mapile.nbElts != 0){
            depiler(&mapile, &element);
            empiler(&mapile, &element+1);
        }

    } while (mapile.nbElts == 0);
}

int noeudValide(T_Pile mapile){
    int i, y; //Boucleurs
    if (mapile.nbElts == 0)
        return 1;


    for(i = mapile.nbElts-1; i >= 0; i--){
        for(y = 0; y < i; y++){
            if(mapile.Elts[i] == mapile.Elts[y]){
                return 0;
            }
        }
    }
    return 1;
}