#include "es.h"

#define MAX 10

typedef struct {
	T_Elt Elts[MAX]; // stockage d'éléments de la case 0 à la case MAX-1
	int Tete;
	int Queue;
} T_File;

/**
 * \brief Teste toutes les fonctions de la file. Si un comportement inhabituel est remarqué, alors 1 est renvoyé.
 * Si une exception est levée (SEGSEV, ...), alors évidemment il y a une erreur.
 * 
 * \param ptrF Pointeur de file à tester
 */
void testFile(T_File *ptrF, T_Elt *);

//TODO: Faire de la dox pour toutes les fonctions
void initFile(T_File *);		// mettre Tete et Queue à -1
int retirer(T_File *, T_Elt *); // si pas vide, en tete de file, renvoie 0 si file vide sinon 1
int ajouter(T_File *, T_Elt *); // si espace libre, ajout en queue, revoie 0 si file pleine sinon 1
int fileVide(const T_File *);	// qd Tete == 0
int filePleine(const T_File *); // qd MAX elts dans la file
T_Elt premier(T_File *);		// valeur en tete de file
void afficherFile(T_File *);
