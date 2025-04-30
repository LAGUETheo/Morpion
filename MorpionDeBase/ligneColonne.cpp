#include "ligneColonne.h"

int determinerColonne(string saisieJoueur, int& Colonne)
{
    switch (saisieJoueur[1])
    {
    case '1':
        Colonne = 0;
        break;
    case '2':
        Colonne = 1;
        break;
    case '3':
        Colonne = 2;
        break;
    }
    return Colonne;
}

int determinerLigne(string saisieJoueur, int& Ligne)
{
    switch (saisieJoueur[0])
    {
    case '1':
        Ligne = 0;
        break;
    case '2':
        Ligne = 1;
        break;
    case '3':
        Ligne = 2;
        break;
    }
    return Ligne;
}