#include <stdio.h>
#include <string.h>

/*typedef int T_Elt; // TAD*/

// ou
/*typedef char T_chaine[50];
typedef T_chaine T_Elt; //TAD*/
// ou
typedef char  T_Elt; //TAD

/**
 * @brief Permet de saisir un élément, s'adapte au type
 * @param T_Elt Elément à saisir
 */
void saisirElt(T_Elt *);

/**
 * @brief Permet d'afficher un élément, s'adapte au type
 * @param T_Elt Elément à afficher
 */
void afficherElt(T_Elt *);

/**
 * @brief Permet d'affecter une valeur à un élément, s'adapte au type
 * @param T_Elt Destination
 * @param T_Elt Source
 */
void affecterElt(T_Elt *, T_Elt *);
