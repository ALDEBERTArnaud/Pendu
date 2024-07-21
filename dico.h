#ifndef DICO_H
#define DICO_H

#define TAILLE_MOT 30

extern char **dictionnaire;
extern int taille_dico;

void charger_dico(const char *fichier);
void liberer_dico(void);
char *choisir_mot(void);

#endif
