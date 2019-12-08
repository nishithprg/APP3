#ifndef _LISTES_H
#define _LISTES_H

//Definition des type de struct pour les listes chainees
struct cellule {
    char* valeur;
    struct cellule *suivant;
};
typedef struct cellule cellule_t;

struct liste {
    cellule_t *tete;
};

typedef struct liste liste_t;

//Definition de listes 2D ou tab[0][vertebre] meme chose que [vertebre] (les listes dans python)
// struct list{
//     int longeur;
//     char * tab[]
// };

void ajout_en_tete(liste_t *lst_head , char *elem);

void ajout_en_queue(liste_t *lst_head, char *elem);

cellule_t* nouvelleCellule (void);

char *elem_idx(liste_t lst_head, int index, int nb_carac);

void conversion_carac(liste_t lst_head, char *lst);

void afficher_lst(liste_t lst_head);
#endif /* _LISTES_H */


