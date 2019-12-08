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

//La fonction renvoie vraie si l'espece appartient a sous-arbre
int appartient(noeud * racine, char *espece){
	if(racine == NULL){
		return 0;
	}
	if(!strcmp(racine->valeur, espece)){
		return 1;	
	} 
	return appartient(racine->gauche, espece) || appartient(racine->droit, espece);
}

//La fonction parcours l'arbre que sur le bon chemin vers l'espece qu'on cherche et a chaque caracteristique correspondant a l'espece,
//on ajoute cette caracteristique dans une liste chaine
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

//on suppose que les caracteristiques fournis font partie de l'arbre
//on peut rajouter les caracteristiques en faison une fonction supplementaire rajoute des caracteristique tant que
//toutes les caracteristique dans notre liste chaine n'est pas traite
void insertion_espece (arbre racine, char *espece, liste_t lst_head, int nb_carac, int index){
	//L'ajoute de l'espece a l'arbre
	if(racine == NULL){
		racine = nouveau_noeud ();
		racine->valeur = espece;
		printf("test 5\n");
		return;
	} else if(racine->droit == NULL && racine->gauche == NULL){
		printf("%s a les memes caracteristique qur %s, insertion pas possible", racine->valeur, espece);
	} else {
		char *elem = elem_idx(lst_head, index, nb_carac);
		if(elem == NULL){ //comme strcmp sort des erreurs quand un pointeur NULL est fourni on fait ca
		//	printf("%s \t gauche 2\n", racine->valeur);
			insertion_espece(racine->gauche,espece,lst_head,nb_carac,index);
		}
		if(!strcmp(racine->valeur, elem)){
		//	printf("%s \t droit\n", racine->valeur);
			insertion_espece(racine->droit,espece,lst_head,nb_carac,index+1);
		} else {
		//	printf("%s \t gauche\n", racine->valeur);
			insertion_espece(racine->gauche,espece,lst_head,nb_carac,index);
		}	
	}
}








