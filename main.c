#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listes.h"
#include "arbres.h"
#include "arbresphylo.h"

int DEBUG = 0;

int main(int argc, char* argv[])
{
    char *fichier = NULL;

    if (argc < 2) {
        fprintf (stderr, "Usage:  %s [-d] <fichier>\n", argv[0]);
        fprintf (stderr, "\n");
        fprintf (stderr, "Options:\n");
        fprintf (stderr, "\t-d\tmode debug\n");
        exit(1);
    }
    int arg=1;

    while (arg < argc) {
        if (!strncmp(argv[arg], "-d", 2)) {
            DEBUG = 1;
            arg++;
            continue;
        }
        if (argv[arg][0] == '-') {
            fprintf (stderr, "Option inconnue : '%s'\n", argv[arg]);
            exit(1);
        }
        if (fichier == NULL) {
            fichier = argv[arg];
            arg++;
            continue;
        }
        else {
            fprintf (stderr, "Trop de fichiers sur la ligne de commande : '%s'\n", argv[arg]);
            exit(1);
        }
    }

    debug ("Ouverture de %s\n", fichier);
    FILE* f = fopen (fichier, "r");
	if (!f) {
		fprintf (stderr, "Erreur à l'ouverture du fichier `%s'\n", fichier);
		perror (fichier);
		exit(1);
	}

    arbre mon_arbre = lire_arbre (f);

    int nombre_especes; /* Ne pas initialiser ici, c'est analyse_arbre */
    int nombre_caract;  /* qui doit s'en charger */
	char espece_recherche[12];
	printf("L'espece de recherche: ");	
	scanf("%s", espece_recherche);
	char *searching = espece_recherche;
	char carac_lst[250];
    	
	affiche_arbre (mon_arbre);
	
    analyse_arbre (mon_arbre, &nombre_especes, &nombre_caract);
	
    printf ("Nombre d'especes de l'arbre: %d\n", nombre_especes);
    printf ("Nombre de caractéristiques de l'arbre: %d\n", nombre_caract);

	//Test de la fonction appartient
	/*	
	if(appartient(mon_arbre, searching)){
		printf("%s appartient a l'arbre.\n", espece_recherche);
	} else {
		printf("%s n'appartient pas a l'arbre.\n", espece_recherche);
	}
	*/
	
	//Acte II
	//Initialisation de liste chainee et appel de la fonction de recherche d'espece
	liste_t lst_head;
	lst_head.tete = NULL;	
	if(appartient(mon_arbre, searching)){
		rechercher_espece(mon_arbre, searching, &lst_head);
		//afficher_lst(lst_head);	//Fonction d'affichage de la liste chainee	
		conversion_carac(lst_head, carac_lst);
		printf("\n\tCaracteristique de l'espece\n%s\n", carac_lst); //Affichage de l'ensemble des caractesitques
	} else {
		printf("%s n'appartient pas a l'arbre.\n", espece_recherche); //En cas le nom d'espece fournie n'est pas dans l'arbre
	}
	
	//Acte III
	//Ecriture des caractestique dans listes chaine
	//liste_t lst_head;
	lst_head.tete = NULL;
	char carac[15], espece[20];
	int nb_carac;
	printf("Nombre de caracteristique de l'espece : ");
	scanf("%d", &nb_carac);
	printf("Nom de l'espece a inserer : ");
	scanf("%s", espece);
	if(nb_carac != 0){
		printf("Premiere caracteristique : ");
		scanf("%s", carac);
		ajout_en_tete(&lst_head, carac);
		for(int i = 1; i < nb_carac - 1; i++){
			printf("Caracteristique suivante: ");
			scanf("%s\n", carac);
			ajout_en_queue(&lst_head, carac);
		}
	}
	printf("test 1\n");
	insertion_espece(mon_arbre, espece, lst_head, nb_carac, 0);
	affiche_arbre (mon_arbre);
	return 0;
}


