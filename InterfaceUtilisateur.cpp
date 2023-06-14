#include "InterfaceUtilisateur.h"
#include <iostream>

using namespace std;

void saisirParametres(unsigned int &taille, unsigned int &nbMines) {
    bool saisieCorrecte;
    do {
        cout << "Taille de la grille : ";
        cin >> taille;
        cout << "Nombre de mines : ";
        cin >> nbMines;
        cin.ignore(256, '\n');
        saisieCorrecte = (taille >= TAILLE_MIN && taille <= TAILLE_MAX &&
                          nbMines >= 1 && nbMines <= taille * taille);
        if (!saisieCorrecte) {
            cout << "! Erreur : La taille doit etre dans [" << TAILLE_MIN << ".." << TAILLE_MAX << "]" << endl
                 << "et le nombre de mines dans [1..taille^2]. Recommencez..." << endl;
        }
    } while (!saisieCorrecte);
}

Coup saisirCoup(unsigned int taille) {
    unsigned int ligne, colonne;
    char action;
    bool saisieCorrecte;
    do {
        cout << endl <<  "Quel coup jouez-vous (ligne colonne action (D|M) : ";
        cin >> hex >> ligne >> hex >> colonne >> action;
        saisieCorrecte = 0 <= ligne && ligne < taille &&
                         0 <= colonne && colonne < taille &&
                         action == 'd' || action == 'D' || action == 'm' || action == 'M';
        if (!saisieCorrecte) {
            cout << "! Erreur : Ligne et colonne doivent etre entre 0 et " << taille - 1
                 << endl << "et action doit etre 'd' ou 'm'. Recommencez..." << endl;
        }
    } while (!saisieCorrecte);
    return {ligne, colonne, (action == 'd' || action == 'D') ? DECOUVRIR : MARQUER};
}

void afficherResultatCoup(Grille grille) {
    if (grille.isPerdue())
        cout << "BOUM ! Vous avez perdu !" << endl;
    else if (grille.isGagnee())
        cout << "Vous avez gagne !" << endl;
    else
        cout << "Il faut continuer a deminer..." << endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Affichage de la grille
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void afficherNumeroColonnes(unsigned int taille) {
    // afficher les numéros de colonne
    cout << endl << "  ";
    for (unsigned int colonne = 0; colonne < taille; colonne++)
        cout << ' ' << uppercase << hex << colonne;
    cout << endl;
}

void afficheLigneSeparatrice(unsigned int taille) {
    // afficher ligne séparatrice horizontale
    cout << "  ";
    for (unsigned int colonne = 0; colonne < taille; colonne++)
        cout << "+-";
    cout << "+" << endl;
}

void afficherJeu(Case laCase) {
    // Afficher le contenu d'une case en mode "jeu"
    if (!laCase.isDecouverte()) {
        if (laCase.isMarquee())
            cout << CASE_MARQUEE;
        else
            cout << CASE_COUVERTE;
    } else {
        if (laCase.getNbMinesAutour() > 0)
            cout << laCase.getNbMinesAutour();
        else
            cout << CASE_VIDE;
    }
}

void afficherSolution(Case laCase) {
    // Afficher le contenu d'une case en mode "solution"
    if (laCase.isMinee())
        cout << CASE_MINEE;
    else if (laCase.getNbMinesAutour() > 0)
        cout << laCase.getNbMinesAutour();
    else
        cout << CASE_VIDE;
}

void afficher(Grille grille, bool montrerSolution) {
    afficherNumeroColonnes(grille.getTaille());
    afficheLigneSeparatrice(grille.getTaille());
    for (unsigned int ligne = 0; ligne < grille.getTaille(); ligne++) {
        cout << ligne << " ";
        for (unsigned int colonne = 0; colonne < grille.getTaille(); colonne++) {
            cout << '|';
            Case &laCase = grille.getCase(Coordonnee(ligne, colonne));
            if (montrerSolution)
                afficherSolution(laCase);
            else
                afficherJeu(laCase);
        }
        cout << '|' << endl;
        afficheLigneSeparatrice(grille.getTaille());
    }
}
