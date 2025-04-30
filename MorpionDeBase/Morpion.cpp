/*
 Programme : Morpion
 But : Jeu du morpion
 Date de dernière modification : 14 janvier 2024
 Auteur : LAGUE Théo
 Remarques : Code conforme à l'algorithme données en cours
 1ère extension : Elle permet au joueur de choisir son symbole ainsi que d'y ajouter une couleur
*/

#include <iostream>
#include <string>
#include "ligneColonne.h"
#include "afficherRegles.h"
#include "windows.h"
using namespace std;

struct Joueur
{
    string prenom;
    char symbole;
};

void afficheMorpion(char tab[3][3]);

int determinerLigne(string saisieJoueur, int &Ligne);
int determinerColonne(string saisieJoueur, int &Colonne);

int main(void)
{
    /////////////////////////////////
    // V A R I A B L E S
    Joueur joueur1, joueur2;
    int ligne;
    int colonne;
    string choixJoueur;
    char tab[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    unsigned short int nbTour = 0;
    bool abandon = false;
    string gagnant;
    string perdant;
    bool estGagne = false;
    bool casePrise;
    string dernierJoueur;
    /////////////////////////////////
    // T R A I T E M E N T S

    // Affichage des règles
    afficherRegles();

    // Phase de personnalisation
    cout << "JOUEUR 1, entrez votre prenom : ";
    cin >> joueur1.prenom;
    cout << joueur1.prenom << ", entrez votre symbole (1 lettre ou 1 chiffre) : ";
    cin >> joueur1.symbole;

    cout << "JOUEUR 2, entrez votre prenom : ";
    cin >> joueur2.prenom;

    do
    {
        cout << joueur2.prenom << ", entrez votre symbole (1 lettre ou 1 chiffre), autre que '" << joueur1.symbole << "' : ";
        cin >> joueur2.symbole;

        if (joueur1.symbole == joueur2.symbole)
        {
            cout << "Les joueurs doivent choisir des symboles differents. Reessayez." << endl;
        }
    } while (joueur1.symbole == joueur2.symbole);

    // Jeu du morpion
    while (true)
    {
        nbTour++;

        // Affichage du morpion
        cout << "Tour numero " << nbTour << endl;
        cout << endl;
        cout << "[ " << tab[0][0] << " | " << tab[0][1] << " | " << tab[0][2] << " ]" << endl;
        cout << "[ " << tab[1][0] << " | " << tab[1][1] << " | " << tab[1][2] << " ]" << endl;
        cout << "[ " << tab[2][0] << " | " << tab[2][1] << " | " << tab[2][2] << " ]" << endl;

        // Saisie du joueur 1
        if (nbTour % 2 != 0)
        {
            cout << "--> " << joueur1.prenom << ", entrez :" << endl;
            cout << endl;
            do
            {
                cout << "Une coordonnee (LigneColonne, ex. : 12 pour Ligne 1, Colonne 2), ou bien A(bandonner)" << endl;
                cout << endl;
                cout << "Votre choix ? : ";
                cin >> choixJoueur;

                // Vérification pour abandonner la partie
                if (choixJoueur == "A" || choixJoueur == "a")
                {
                    abandon = true;
                    gagnant = joueur2.prenom;
                    perdant = joueur1.prenom;
                    break;
                }

                determinerLigne(choixJoueur, ligne);
                determinerColonne(choixJoueur, colonne);
                casePrise = (tab[ligne][colonne] == joueur1.symbole) || (tab[ligne][colonne] == joueur2.symbole);

                if (casePrise)
                {
                    cout << "Cette case est deja prise. Reessayez." << endl;
                }

            } while (casePrise || !((choixJoueur == "11") || (choixJoueur == "12") || (choixJoueur == "13") || (choixJoueur == "21") || (choixJoueur == "22") || (choixJoueur == "23") || (choixJoueur == "31") || (choixJoueur == "32") || (choixJoueur == "33")));
            dernierJoueur = joueur1.prenom;
        }
        // Saisie du joueur 2
        else
        {
            cout << "--> " << joueur2.prenom << ", entrez :" << endl;
            cout << endl;
            do
            {
                cout << "Une coordonnee (LigneColonne, ex. : 12 pour Ligne 1, Colonne 2), ou bien A(bandonner)" << endl;
                cout << endl;
                cout << "Votre choix ? : ";
                cin >> choixJoueur;

                // Vérification pour abandonner la partie
                if (choixJoueur == "A" || choixJoueur == "a")
                {
                    abandon = true;
                    gagnant = joueur1.prenom;
                    perdant = joueur2.prenom;
                    break;
                }

                determinerLigne(choixJoueur, ligne);
                determinerColonne(choixJoueur, colonne);
                casePrise = (tab[ligne][colonne] == joueur1.symbole) || (tab[ligne][colonne] == joueur2.symbole);

                if (casePrise)
                {
                    cout << "Cette case est deja prise. Reessayez." << endl;
                }

            } while (casePrise || !((choixJoueur == "11") || (choixJoueur == "12") || (choixJoueur == "13") || (choixJoueur == "21") || (choixJoueur == "22") || (choixJoueur == "23") || (choixJoueur == "31") || (choixJoueur == "32") || (choixJoueur == "33")));
            dernierJoueur = joueur2.prenom;
        }

        // Si le joueur n'abandonne pas et que le nombre de tour est impair alors on ajoute le symbole du joueur 1
        if (!(nbTour % 2 == 0))
        {
            tab[ligne][colonne] = joueur1.symbole;
        }
        // Sinon si le joueur n'abandonne pas on ajoute celui du joueur 2
        else
        {
            tab[ligne][colonne] = joueur2.symbole;
        }

        // Recherche d'une ligne gagnante
        if (nbTour >= 5)
        {
            // Verification lignes horizontales
            if (tab[0][0] == tab[0][1])
            {
                if ((tab[0][1] != ' ') && (tab[0][1] == tab[0][2]))
                {
                    cout << endl
                         << "11" << endl;
                    estGagne = true;
                }
            }

            if ((estGagne == false) && (tab[1][0] == tab[1][1]))
            {
                if ((tab[1][1] != ' ') && (tab[1][1] == tab[1][2]))
                {
                    cout << endl
                         << "12" << endl;
                    estGagne = true;
                }
            }

            if ((estGagne == false) && (tab[2][0] == tab[2][1]))
            {
                if ((tab[2][1] != ' ') && (tab[2][1] == tab[2][2]))
                {
                    cout << endl
                         << "13" << endl;
                    estGagne = true;
                }
            }

            // Verification lignes verticales
            if ((estGagne == false) && (tab[0][0] == tab[1][0]))
            {
                if ((tab[1][0] != ' ') && (tab[1][0] == tab[2][0]))
                {
                    cout << endl
                         << "21" << endl;
                    estGagne = true;
                }
            }

            if ((estGagne == false) && (tab[0][1] == tab[1][1]))
            {
                if ((tab[1][1] != ' ') && (tab[1][1] == tab[2][1]))
                {
                    cout << endl
                         << "22" << endl;
                    estGagne = true;
                }
            }

            if ((estGagne == false) && (tab[0][2] == tab[1][2]))
            {
                if ((tab[1][2] != ' ') && (tab[1][2] == tab[2][2]))
                {
                    cout << endl
                         << "23" << endl;
                    estGagne = true;
                }
            }

            // Verification diagonales
            if ((estGagne == false) && (tab[0][0] == tab[1][1]))
            {
                if ((tab[1][1] != ' ') && (tab[1][1] == tab[2][2]))
                {
                    cout << endl
                         << "31" << endl;
                    estGagne = true;
                }
            }

            if ((estGagne == false) && (tab[0][2] == tab[1][1]))
            {
                if ((tab[1][1] != ' ') && (tab[1][1] == tab[2][0]))
                {
                    cout << endl
                         << "32" << endl;
                    estGagne = true;
                }
            }
        }

        // Afficher le dernier tableau
        if (estGagne || nbTour == 9)
        {
            cout << endl;
            cout << "[ " << tab[0][0] << " | " << tab[0][1] << " | " << tab[0][2] << " ]" << endl;
            cout << "[ " << tab[1][0] << " | " << tab[1][1] << " | " << tab[1][2] << " ]" << endl;
            cout << "[ " << tab[2][0] << " | " << tab[2][1] << " | " << tab[2][2] << " ]" << endl;
            break;
        }
    }

    // Affichage du gagnant
    cout << endl;
    cout << "- - -   Fin de la partie   - - - " << endl;
    cout << endl;

    if (abandon)
    {
        cout << "Partie gagnee par " << gagnant << " suite a l'abandon de " << perdant << " au Tour numero " << nbTour << endl;
    }
    else if (nbTour == 9)
    {
        cout << "Egalite (pas de gagnant) car grille complete" << endl;
    }
    else
    {
        cout << "Partie gagnee par " << dernierJoueur << " au tour numero " << nbTour << endl;
    }

    return 0;
}

void afficheMorpion(char tab[3][3])
{
    for (unsigned short int ligne = 0; ligne < 5; ligne++)
    {
        if (ligne % 2 != 0)
        {
            cout << endl
                 << "---|---|---" << endl;
        }

        else
        {
            for (unsigned short int colonne = 0; colonne < 5; colonne++)
            {
                if (colonne % 2 == 0)
                {
                    cout << " " << tab[ligne / 2][colonne / 2] << " ";
                }
                else
                {
                    cout << "|";
                }
            }
        }
    }
}