#include "es.h"
#define MAX 10 // pile STATIQUE (limitée à MAX éléments)

typedef struct {
	T_Elt Elts[MAX]; // stockage d'éléments de la case 0 à la case MAX-1
	int nbElts;
} T_Pile;

/**
 * @brief Teste la pile en effectuant une batterie de tests dessus, avec une valeur passée en argument
 * @param P La pile à tester
 * @param testVar La valeur avec laquelle tester la pile
 */
void testPile(T_Pile *P, T_Elt *testVar);

/**
 * @brief Initialise la pile en mettant nbElts à 0
 */
void initPile(T_Pile *P);

/**
 * @brief Indique si la pile est pleine
 * @param P La pile
 * @return 1 si elle est pleine, 0 sinon
 */
int pilePleine(const T_Pile *P);

/**
 * @brief Indique si la pile est vide
 * @param P La pile
 * @return
 */
int pileVide(const T_Pile *P);

/**
 * @brief Empile un élément à la pile souhaitée
 * @param P La pile souhaitée
 * @param e L'élément à empiler
 * @return 0 si l'ajout s'est bien passé, 1 sinon (pile pleine)
 */
int empiler(T_Pile *P, T_Elt *e);

/**
 * @brief Dépile un élément de la pile souhaitée
 * @param P La pile souhaitée
 * @param pelt La variable vers laquelle l'élément dépilé sera sauvegardé
 * @return 0 si l'action s'est bien passée, 1 sinon (pile vide)
 */
int depiler(T_Pile *P, T_Elt *pelt);

/**
 * @brief Retourne la valeur de l'élément se situant en haut de la pile
 * @return La valeur de l'élément se situant en haut de la pile
 */
T_Elt sommet(const T_Pile *);

/**
 * @brief Renvoie la hauteur actuelle de la pile
 * @param P La pile
 * @return La hauteur actuelle de la pile
 */
int hauteur(const T_Pile *P);

/**
 * @brief Affiche tous les éléments de la pile
 * @param P La pile
 */
void afficherPile(T_Pile *P); // vous devez depiler la pile pour afficher chacune de ses valeurs (puis surtout la rempiler)
