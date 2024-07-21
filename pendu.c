#include "pendu.h"
#include "dico.h"
#include "stats.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifdef _WIN32
#include <crtdbg.h>
#endif

void initialiser_partie(Partie *p) {
    char *mot_choisi = choisir_mot();
    size_t len = strlen(mot_choisi);
    if (len >= TAILLE_MOT) {
        fprintf(stderr, "Erreur: mot trop long\n");
        exit(1);
    }
    strcpy(p->mot, mot_choisi);
    memset(p->trouve, '_', len);
    p->trouve[len] = '\0';
    p->erreurs = 0;
    memset(p->lettres_utilisees, 0, sizeof(p->lettres_utilisees));
}

void afficher_partie(Partie *p) {
    printf("Mot: %s\n", p->trouve);
    afficher_pendu(p->erreurs);
    afficher_lettres_utilisees(p);
}

char demander_lettre(void) {
    char lettre;
    do {
        printf("Proposez une lettre: ");
        scanf(" %c", &lettre);
        lettre = toupper(lettre);
    } while(!isalpha(lettre));
    return lettre;
}

void update_partie(Partie *p, char lettre) {
    bool trouve = false;
    for(int i = 0; p->mot[i]; i++) {
        if(toupper(p->mot[i]) == lettre) {
            p->trouve[i] = p->mot[i];
            trouve = true;
        }
    }
    if(!trouve) {
        p->erreurs++;
    }
    ajouter_lettre_proposee(lettre);
    p->lettres_utilisees[lettre - 'A'] = true;
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

void afficher_lettres_utilisees(Partie *p) {
    printf("Lettres utilisees : ");
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (p->lettres_utilisees[i]) {
            printf("%c ", 'A' + i);
        }
    }
    printf("\n");
}

void nettoyer(void) {
    liberer_dico();
}

int main(void) {
#ifdef _WIN32
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

    srand(time(NULL));
    charger_dico("dico.txt");

    char rejouer;
    do {
        incrementer_parties_jouees();

        static Partie p;
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
    } while(rejouer == 'o' || rejouer == 'O');

    nettoyer();

#ifdef _WIN32
    _CrtDumpMemoryLeaks();
#endif

    return 0;
}
