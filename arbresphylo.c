#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "arbres.h"
#include "arbresphylo.h"
#include "listes.h"

int nb_caracteristique(arbre racine){
	if((racine == NULL) || (racine->gauche == NULL && racine->droit == NULL)){
		return 0;
	} 
	return 1 + nb_caracteristique(racine->gauche) + nb_caracteristique(racine->droit);
}

int nb_espece(arbre racine){
	//printf("espcesecs\n");
	if(racine == NULL){ 
		return 0;
	} else if(racine->gauche == NULL && racine->droit == NULL){
		return 1;
	}
	return nb_espece(racine->gauche) + nb_espece(racine->droit);
}

void analyse_arbre (arbre racine, int* nb_esp, int* nb_carac)
{
   	printf ("À faire: fonction analyse_arbre fichier " __FILE__ "\n");
	*nb_esp = nb_espece(racine);
	//printf("nb_especes marche : %d", *nb_esp);
	*nb_carac = nb_caracteristique(racine);
}

int appartient(noeud * racine, char *espece){
	if(racine == NULL){
		return 0;
	}
	if(!strcmp(racine->valeur, espece)){
		return 1;	
	} 
	return appartient(racine->gauche, espece) || appartient(racine->droit, espece);
}

void rechercher_espece (arbre racine, char *espece, liste_t *lst_head){
	if(racine == NULL){
		return;
	}
	if(appartient(racine->gauche, espece)){
		//printf("%s, %s \tgauche\n", racine->valeur, espece);		
		rechercher_espece(racine->gauche, espece, lst_head);
	} else if(appartient(racine->droit, espece)){
		//printf("%s, %s\t droit\t", racine->valeur, espece);		
		ajout_en_queue(lst_head, racine->valeur);
		rechercher_espece(racine->droit, espece, lst_head);
	} else {
		return;
	}
}

void insertion_espece (arbre racine, char *espece, int nb_carac, liste_t lst_head){
	if(racine == NULL && nb_carac == 0){
		printf("Arbre vide, pas possible d'inserer\n");
		return;
	}
	for(int i = 0; i <= nb_carac; i++){
			if(racine->droit == NULL){
				racine->droit = nouveau_noeud ();
				racine->droit->valeur = elem_idx(lst_head, i+1);
			}
			if(!strcmp(racine->droit->valeur, elem_idx(lst_head, i))){
					racine = racine->droit;
			} else {
				printf("Caracteristique different que celle dans l'arbre, caracteristique invalide\n");
			}
	}
}








