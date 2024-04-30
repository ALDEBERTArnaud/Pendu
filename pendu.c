#include "pendu.h"
#include "dico.h"
#include "stats.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void initialiser_partie(Partie *p) {
    strcpy(p->mot, dictionnaire[rand() % TAILLE_DICO]);
    int longueur = strlen(p->mot);
    p->mot[longueur-1] = '\0';  // Enlève le caractère de fin de ligne '\n'
    memset(p->trouve, '_', longueur-1);
    p->trouve[longueur-1] = '\0';
    p->erreurs = 0;
}

void afficher_partie(Partie *p) {
    printf("Mot: %s\n", p->trouve);
    afficher_pendu(p->erreurs);
}

char demander_lettre() {
    char lettre;
    do {
        printf("Proposez une lettre: ");
        lettre = toupper(getchar());
        while(getchar() != '\n');
    } while(!isalpha(lettre));
    return lettre;
}

void update_partie(Partie *p, char lettre) {
    bool trouve = false;
    for(int i=0; p->mot[i]; i++) {
        if(toupper(p->mot[i]) == lettre) {
            p->trouve[i] = p->mot[i];
            trouve = true;
        }
    }
    if(!trouve) {
        p->erreurs++;
    }
    ajouter_lettre_proposee(lettre);
}

bool partie_finie(Partie *p) {
    return p->erreurs == MAX_ERREURS || strcmp(p->mot, p->trouve) == 0;
}

void afficher_pendu(int erreurs) {
    printf("  _______\n");
    printf(" |/      |\n");
    printf(" |      %c%c%c\n", erreurs>0?'(':' ', erreurs>1?'_':' ', erreurs>0?')':' ');
    printf(" |      %c%c%c\n", erreurs>3?'\\':' ', erreurs>2?'|':' ', erreurs>4?'/':' ');
    printf(" |       %c\n", erreurs>5?'|':' ');
    printf(" |\n");
    printf("_|___\n\n");
}

int main() {
    srand(time(NULL));
    charger_dico("dico.txt");

    char rejouer;
    do {
        incrementer_parties_jouees();

        Partie p;
        initialiser_partie(&p);

        while(!partie_finie(&p)) {
            afficher_partie(&p);
            char lettre = demander_lettre();
            update_partie(&p, lettre);
        }

        afficher_partie(&p);
        if(p.erreurs == MAX_ERREURS) {
            printf("Perdu! Le mot etait %s\n", p.mot);
        } else {
            printf("Gagne!\n");
            incrementer_parties_gagnees();
        }

        afficher_statistiques();

        printf("Voulez-vous rejouer (o/n) ? ");
        scanf(" %c", &rejouer);
        while(getchar()!='\n');
    } while(rejouer == 'o');

    return 0;
}
