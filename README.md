# ❌⭕ Morpion - Jeu du Tic-Tac-Toe en C++

Ce projet est une implémentation console du jeu du **Morpion** en **C++**

## 🧩 Structure du projet

- `Morpion.cpp` : Fichier principal qui lance le jeu.
- `afficherRegles.cpp/.h` : Module dédié à l'affichage des règles du jeu.
- `ligneColonne.cpp/.h` : Module gérant la récupération des coordonnées (ligne et colonne) entrées par l'utilisateur.

## 🕹️ Fonctionnalités

- Jeu du morpion à deux joueurs en local.
- Interface textuelle interactive dans le terminal.
- Vérification des conditions de victoire ou d’égalité.
- Affichage clair de la grille à chaque tour.
- Rappel des règles intégré (`afficherRegles`).

## 🛠️ Technologies utilisées

- Langage : **C++**
- Compilation : via `g++`
- Dépendances : Aucune bibliothèque externe

## ▶️ Compilation et exécution

### Compilation (Linux/macOS/WSL/MinGW) :

```bash
g++ Morpion.cpp afficherRegles.cpp ligneColonne.cpp -o Morpion
