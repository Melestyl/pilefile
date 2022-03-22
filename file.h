#include "es.h"

#define MAX 10

typedef struct {
	T_Elt Elts[MAX]; // stockage d'éléments de la case 0 à la case MAX-1
	int Tete;
	int Queue;
} T_File;

/**
 * @brief Teste toutes les fonctions de la file. Si un comportement inhabituel est remarqué, alors 1 est renvoyé.
 * Si une exception est levée (SEGSEV, ...), alors évidemment il y a une erreur.
 *
 * @param ptrF Pointeur de file à tester
 * @param testVar La valeur avec laquelle tester
 */
void testFile(T_File *ptrF, T_Elt *testVar);

/**
 * @brief Initialise la file, en mettant Tete et Queue à 0
 *
 * @param ptrF La file à initialiser
 */
void initFile(T_File *);

/**
 * @brief Défile le dernier élément, et le met dans la variable passée en argument
 *
 * @param ptrF La file sur laquelle on défile
 * @param ptrE La variable dans laquelle on stocke l'élément défilé
 *
 * @return 0 si l'opération s'est bien passée, 1 sinon (file vide)
 */
int retirer(T_File *ptrF, T_Elt *ptrE);

/**
 * @brief Ajoute un élément à la file
 *
 * @param ptrF File dans laquelle ajouter
 * @param ptrE Elément à rajouter dans la file
 *
 * @return 0 si l'ajout s'est bien passé, 1 sinon (file pleine)
 */
int ajouter(T_File *ptrF, T_Elt *ptrE);

/**
 * @brief Indique si la file est vide
 *
 * @param ptrF La file
 *
 * @return 1 si file vide, 0 sinon
 */
int fileVide(const T_File *ptrF);

/**
 * @brief Indique si la file est pleine
 *
 * @param ptrF
 * @return
 */
int filePleine(const T_File *ptrF); // qd MAX elts dans la file
char* premier(const T_File *ptrF);		// valeur en tete de file
void afficherFile(const T_File *ptrF);
