#include "dico.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pendu.h"

const char *dictionnaire[TAILLE_DICO];

void charger_dico(const char *fichier) {
    FILE *f = fopen(fichier, "r");
    if(f == NULL) {
        fprintf(stderr, "Erreur: impossible d'ouvrir %s\n", fichier);
        exit(1);
    }
    char ligne[TAILLE_MOT];
    int i = 0;
    while(fgets(ligne, TAILLE_MOT, f)) {
        dictionnaire[i] = strdup(ligne);
        i++;
    }
    fclose(f);
}