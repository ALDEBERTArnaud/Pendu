#include "dico.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **dictionnaire = NULL;
int taille_dico = 0;

void charger_dico(const char *fichier) {
    FILE *f = fopen(fichier, "r");
    if(f == NULL) {
        fprintf(stderr, "Erreur: impossible d'ouvrir %s\n", fichier);
        exit(1);
    }

    char ligne[TAILLE_MOT];
    while(fgets(ligne, TAILLE_MOT, f)) {
        taille_dico++;
        dictionnaire = realloc(dictionnaire, taille_dico * sizeof(char*));
        if (dictionnaire == NULL) {
            fprintf(stderr, "Erreur d'allocation mémoire\n");
            exit(1);
        }
        ligne[strcspn(ligne, "\n")] = 0;
        dictionnaire[taille_dico-1] = strdup(ligne);
        if (dictionnaire[taille_dico-1] == NULL) {
            fprintf(stderr, "Erreur d'allocation mémoire\n");
            exit(1);
        }
    }
    fclose(f);
}

void liberer_dico(void) {
    if (dictionnaire != NULL) {
        for (int i = 0; i < taille_dico; i++) {
            free(dictionnaire[i]);
        }
        free(dictionnaire);
        dictionnaire = NULL;
        taille_dico = 0;
    }
}

char *choisir_mot(void) {
    if (taille_dico == 0) {
        fprintf(stderr, "Erreur: le dictionnaire est vide\n");
        exit(1);
    }
    return dictionnaire[rand() % taille_dico];
}
