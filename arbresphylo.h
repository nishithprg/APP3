#ifndef ARBRESPHYLO_H
#define ARBRESPHYLO_H

#include "listes.h"


/* Analyse un arbre: doit mettre à jour le nombre d'espèces et de 
 * caractéristiques.
 */
int nb_caracteristique(arbre racine);

int nb_espece(arbre racine);

void analyse_arbre (arbre racine, int* nb_esp, int* nb_carac);

/* Recherche une espèce dans l'arbre et renvoie en argument
 * la séquence de ses caractéristiques.
 * Note: vous devrez modifier la signature de cette fonction selon vos besoins 
 * (plus d'arguments, valeur de retour différente, etc.)
 */
int appartient(noeud * racine, char *espece);

void rechercher_espece (arbre racine, char *espece, liste_t *lst_head);

void insertion_espece (arbre racine, char *espece, int nb_caracs, liste_t lst_head);

#endif
