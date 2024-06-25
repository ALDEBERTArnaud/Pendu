Projet réalisé par Arnaud ALDEBERT, Esteban MORTIER, Tom COLLET-YAKOUBI et Alexandre MATHIEU
# Jeu du Pendu en C

Ce projet est une implémentation du jeu du pendu en langage C. Il utilise plusieurs fichiers pour organiser le code, y compris des fichiers d'en-tête pour les définitions et des fichiers source pour les implémentations.

## Structure du Projet

- `pendu.h` : Contient les définitions des structures et des prototypes de fonctions pour le jeu du pendu.
- `dico.h` : Contient les définitions pour la gestion du dictionnaire.
- `stats.h` : Contient les définitions pour la gestion des statistiques du jeu.
- `dico.c` : Implémente les fonctions pour charger le dictionnaire à partir d'un fichier.
- `stats.c` : Implémente les fonctions pour gérer les statistiques du jeu.
- `pendu.c` : Implémente les fonctions principales du jeu, y compris l'initialisation de la partie, la gestion des erreurs, et l'affichage du pendu.
- `CMakeLists.txt` : Fichier de configuration pour CMake, permettant de compiler le projet.
- `dico.txt` : Fichier texte contenant les mots du dictionnaire utilisés dans le jeu.

## Prérequis

- Un compilateur C (par exemple, `gcc`)
- CMake (version 3.5 ou supérieure)

## Installation

1. Clonez le dépôt 

2. Compilez le projet avec CMake

3. Assurez-vous que le fichier `dico.txt` est dans le même répertoire que l'exécutable généré.

## Utilisation

Pour lancer le jeu, exécutez simplement l'exécutable généré
