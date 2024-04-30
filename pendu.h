#ifndef PENDU_H
#define PENDU_H

#include <stdbool.h>

#define TAILLE_MOT 30
#define MAX_ERREURS 6

typedef struct {
    char mot[TAILLE_MOT];
    char trouve[TAILLE_MOT];
    int erreurs;
} Partie;

void initialiser_partie(Partie *p);
void afficher_partie(Partie *p);
char demander_lettre();
void update_partie(Partie *p, char lettre);
bool partie_finie(Partie *p);
void afficher_pendu(int erreurs);
void afficher_statistiques();

#endif