#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "listes.h"

void ajout_en_tete(liste_t *lst_head , char *elem){
   cellule_t *tete = nouvelleCellule();
   tete->valeur = elem;
   tete->suivant = lst_head->tete;
   lst_head->tete = tete;
}


void ajout_en_queue(liste_t *lst_head, char *elem){
   cellule_t *fin = nouvelleCellule();
   if(lst_head->tete != NULL){
	cellule_t *cel = lst_head->tete;
	while(cel->suivant != NULL){
	   cel = cel-> suivant;
	}
	fin->valeur = elem;	
	fin ->suivant = NULL;
	cel->suivant = fin;
   } else {
   	ajout_en_tete(lst_head, elem);
   }
}

cellule_t* nouvelleCellule (void){
    /* À compléter (utiliser malloc) */
    cellule_t *cel = malloc(sizeof(cellule_t));
    return cel;
}

void conversion_carac(liste_t lst_head, char *lst){
	if(lst_head.tete == NULL){
		return;
	}	
	cellule_t *queue = lst_head.tete;
	char comma = ',';
	while(queue->suivant != NULL){
		strcat(lst, queue->valeur);
		strcat(lst, &comma);
		queue = queue-> suivant;
	}
}

void afficher_lst(liste_t lst_head){
	printf("\n\tThis is a test.\n");
	if(lst_head.tete == NULL){
		printf("La liste chainee est vide.\n");
		return;
	}	
	cellule_t *queue = lst_head.tete;
	while(queue->suivant != NULL){
		char lst_carac[15];
		strcpy(lst_carac, queue->valeur);	
		printf("%s\n", lst_carac);
		queue = queue->suivant;
	}
}
