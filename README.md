# Jeu du Pendu en C

Ce projet est une implémentation du jeu classique du pendu en langage C, réalisé dans le cadre d'un projet scolaire.

## Auteurs

- Arnaud ALDEBERT
- Esteban MORTIER
- Tom COLLET-YAKOUBI
- Alexandre MATHIEU

## Structure du Projet

- `pendu.c` / `pendu.h` : Fichiers principaux du jeu
- `dico.c` / `dico.h` : Gestion du dictionnaire
- `stats.c` / `stats.h` : Gestion des statistiques
- `CMakeLists.txt` : Configuration de compilation
- `dico.txt` : Fichier de données pour le dictionnaire

## Fonctionnalités

- Interface en ligne de commande
- Chargement dynamique du dictionnaire
- Gestion des statistiques de jeu (parties jouées, gagnées, lettres proposées)
- Affichage graphique du pendu en ASCII art

## Prérequis

- Compilateur C (GCC recommandé, ou Visual Studio sur Windows)
- CMake (version 3.5 ou supérieure)
- Dr. Memory (optionnel, pour la vérification des fuites mémoire sur Windows)

## Installation et Compilation

1. Clonez le dépôt :
   ```
   git clone [URL_DU_REPO]
   cd [NOM_DU_DOSSIER]
   ```

2. Créez un dossier de build et naviguez dedans :
   ```
   mkdir build
   cd build
   ```

3. Générez les fichiers de build avec CMake :
   ```
   cmake ..
   ```

4. Compilez le projet :
   - Pour une version de release :
     ```
     cmake --build . --config Release
     ```
   - Pour une version de debug :
     ```
     cmake --build . --config Debug
     ```

L'exécutable sera généré dans le dossier `build/bin/`.

## Utilisation

Pour lancer le jeu, exécutez :
```
./bin/pendu
```

## Vérification des fuites mémoire (Windows uniquement)

Si Dr. Memory est installé, vous pouvez l'exécuter directement via CMake :
```
cmake --build . --target run_drmemory
```

## Concepts de programmation utilisés

- Pointeurs
- Structures
- Tableaux
- Allocation dynamique de mémoire
- Fonctions
- Manipulation de fichiers