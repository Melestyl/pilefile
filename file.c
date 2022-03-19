// Un élément rentre par la queue et sort par la tête
/* 
 * ATTENTION, CONVENTION : 
 * Si on attend d'une fonction qu'elle retourne un état (vide, plein), alors 1 = oui, 0 = non 
 * Si c'est une fonction d'action (ajouter, retirer), alors 1 = erreur, 0 = ok
 */

#include "file.h"

void testFile(T_File *ptrF, T_Elt *testVar) {
	T_Elt testVar2 = 0;

	initFile(ptrF);
	if (!fileVide(ptrF))
		fprintf(stderr, "Problème fileVide() (fileVide dès le début)\n");
	if (!retirer(ptrF, &testVar2))
		fprintf(stderr, "Problème retirer() (retire si vide)\n");
	for (int i=0; i<MAX; i++) { // Remplie la file
		if (ajouter(ptrF, testVar))
			 fprintf(stderr, "Problème ajouter() (ne peut ajouter correctement jusqu'à MAX)\n");
	}
	if (fileVide(ptrF))
		fprintf(stderr, "Problème fileVide() (renvoie vide alors qu'elle ne l'est pas)\n");
	if (!filePleine(ptrF))
		fprintf(stderr, "Problème filePleine() (ne renvoie pas pleine alors qu'elle l'est)\n");
	if (!ajouter(ptrF, testVar))
		fprintf(stderr, "Problème ajouter() (file pleine ajoute quand même)\n");
	if (retirer(ptrF, &testVar2))
		fprintf(stderr, "Problème retirer() (ne parvient pas à retirer un élément)\n");
	if (*testVar != testVar2) //FIXME: Dépendant du type
		fprintf(stderr, "Problème retirer() (ne retire pas la bonne valeur)\n");
	if (premier(ptrF) == 0)
		fprintf(stderr, "Problème premier() (renvoie 0)\n");
	printf("Test afficherFile() : \n");
	afficherFile(ptrF);
}

void initFile(T_File *ptrF) {
	ptrF->Tete = 0;
	ptrF->Queue = 0;
}

int retirer(T_File *ptrF, T_Elt *ptrE)  {
	// Si pas vide, en tete de file
	if (!fileVide(ptrF))
		*ptrE = ptrF->Elts[--ptrF->Queue];
	else
		return 1;

	return 0;
}

int ajouter(T_File *ptrF, T_Elt *ptrE) {
	// Si espace libre, ajout en queue
	if (!filePleine(ptrF)) {
		affecterElt(&ptrF->Elts[ptrF->Queue], ptrE);
		ptrF->Queue++;
		if (ptrF->Queue == MAX + 1) ptrF->Queue = 0;
	}
	else
		return 1;

	return 0;
}

int fileVide(const T_File *prtF) {
	// Quand Tete == 0 
	if (prtF->Tete == prtF->Queue)
		return 1;
	
	return 0;
}

int filePleine(const T_File *ptrF) {
	// Quand MAX elts dans la file
	if ((ptrF->Queue == MAX && ptrF->Tete == 0) || (ptrF->Queue + 1 == ptrF->Tete))
		return 1;

	return 0;
}

T_Elt premier(T_File *ptrF) {
	// Valeur en tete de file
	if (!fileVide(ptrF))
		return ptrF->Elts[ptrF->Tete];
	
	return 0;
}

void afficherFile(T_File *ptrF) {
	for (int i=0, j=ptrF->Tete; i < (ptrF->Queue - ptrF->Tete); i++, j++) {
		if (j == MAX) j = 0;
		afficherElt(&ptrF->Elts[j]);
	}
}