#include "afficherRegles.h"

void afficherRegles()
{

    // Affichage des règles
    cout << "---------------- M O R P I O N ----------------" << endl;
    cout << endl;
    cout << "Jeu avec 2 joueurs humains et une grille de 9 cases : 3 lignes et 3 colonnes." << endl;
    cout << "Chaque joueur joue a tour de role." << endl;
    cout << "Le but du jeu est d'aligner, avant son adversaire, 3 symboles identiques, horizontalement, verticalement ou en diagonale" << endl;
    cout << endl;
    cout << "La partie se termine :" << endl;
    cout << "- quand l'un des joueurs a aligne ses 3 symboles, et il gagne," << endl;
    cout << "- quand la grille est complete, et il y a egalite (pas de gagnant)" << endl;
    cout << "- quand l'un des joueurs abandonne, et c'est alors l'autre joueur qui gagne." << endl;
    cout << "Chaque joueur a donc son propre symbole." << endl;
    cout << endl;
    cout << "Dans cette version du Morpion, une phrase prealable de personnalisation permet a chaque joueur de saisir son prenom" << endl << "et le symbole choisi pour jouer." << endl;
    cout << "Lorsqu'arrive son tour de jouer, un joueur peut :" << endl;
    cout << "- saisir la position de la case ou placer son symbole, sous la forme LigneColonne (exemple : 12 pour Ligne 1, Colonne 2)" << endl;
    cout << "- saisir A (ou a) pour abandonner le jeu" << endl;
    cout << endl;
    cout << "-----------------------------------------------" << endl;
    cout << endl;
}
