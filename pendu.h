#ifndef PENDU_H
#define PENDU_H

#include <stdbool.h>
#include "dico.h"

#define TAILLE_MOT 30
#define MAX_ERREURS 6
#define ALPHABET_SIZE 26

typedef struct {
    char mot[TAILLE_MOT];
    char trouve[TAILLE_MOT];
    int erreurs;
    bool lettres_utilisees[ALPHABET_SIZE];
} Partie;

void initialiser_partie(Partie *p);
void afficher_partie(Partie *p);
char demander_lettre(void);
void update_partie(Partie *p, char lettre);
bool partie_finie(Partie *p);
void afficher_pendu(int erreurs);
void afficher_statistiques(void);
void afficher_lettres_utilisees(Partie *p);
void nettoyer(void);

#endif
