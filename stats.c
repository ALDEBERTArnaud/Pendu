#include "stats.h"
#include <stdio.h>

int parties_jouees = 0;
int parties_gagnees = 0;
int lettres_proposees[26] = {0};

void incrementer_parties_jouees(void) {
    parties_jouees++;
}

void incrementer_parties_gagnees(void) {
    parties_gagnees++;
}

void ajouter_lettre_proposee(char lettre) {
    lettres_proposees[lettre - 'A']++;
}

void afficher_statistiques(void) {
    printf("Parties jouees: %d\n", parties_jouees);
    printf("Parties gagnees: %d\n", parties_gagnees);
    printf("Lettres proposees:\n");
    for(int i=0; i<26; i++) {
        printf("%c: %d\n", 'A'+i, lettres_proposees[i]);
    }
}
