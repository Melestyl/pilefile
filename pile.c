/* 
 * ATTENTION, CONVENTION : 
 * Si on attend d'une fonction qu'elle retourne un état (vide, plein), alors 1 = oui, 0 = non 
 * Si c'est une fonction d'action (empiler, dépiler), alors 1 = erreur, 0 = ok
 */

#include "pile.h"

void testPile(T_Pile *P, T_Elt *testVar) {
	T_Elt testVar2 = 0;

	initPile(P);
	if (pilePleine(P))
		fprintf(stderr, "Problème pilePleine() (renvoie pleine alors que vide)\n");
	if (!pileVide(P))
		fprintf(stderr, "Problème pileVide() (ne renvoie pas vide alors que vide)\n");
	for (int i=0; i<MAX; i++) {
		if (empiler(P, testVar))
			fprintf(stderr, "Problème empiler() (n'empile pas jusqu'à MAX)\n");
	}
	if (depiler(P, &testVar2))
		fprintf(stderr, "Problème depiler() (ne dépile pas)\n");
	if (*testVar != testVar2)
		fprintf(stderr, "Problème depiler() (ne dépile pas la bonne valeur)\n");
	if (pileVide(P))
		fprintf(stderr, "Problème pileVide() (renvoie vide alors qu'elle ne l'est pas)\n");
	if (sommet(P) == *testVar)
		fprintf(stderr, "Problème sommet() (ne renvoie pas la valeur de testVar)\n");
	if (hauteur(P) == 0)
		fprintf(stderr, "Problème hauteur() (renvoie 0)\n");
	printf("Affichage de la pile :\n");
	afficherPile(P);
}

void initPile(T_Pile *P) {
	P->nbElts = 0;
}

int pilePleine(const T_Pile *P) {
	if (P->nbElts == MAX)
		return 1;
	
	return 0;
}

int pileVide(const T_Pile *P) {
	if (P->nbElts == 0)
		return 1;
	
	return 0;
}

int empiler(T_Pile *P, T_Elt *e) {
	// Renvoie 1 si pile pleine, sinon 0
	if (!pilePleine(P))
		affecterElt(&P->Elts[P->nbElts++], e);
	else
		return 1;
	
	return 0;
}

int depiler(T_Pile *P, T_Elt *pelt) {
	// Renvoie 1 si pile vide, sinon 0
	if (!pileVide(P))
		*pelt = P->Elts[--P->nbElts];
	else
		return 1;
	
	return 0;
}

T_Elt sommet(const T_Pile *P) {
	if (!pileVide(P))
		return P->Elts[P->nbElts - 1];
	
	return 0; //FIXME: Il faudrait trouver une autre valeur, comme NULL, car 0 peut être une valeur
}

int hauteur(const T_Pile *P) {
	return P->nbElts;
}

void afficherPile(T_Pile *P) {
	for (int i=0; i<P->nbElts; i++)
		afficherElt(&P->Elts[i]);
}
