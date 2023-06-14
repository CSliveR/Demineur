#include <iostream>
using namespace std;
#include "Grille.h"
#include "Coup.h"
#include "InterfaceUtilisateur.h"


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Algorithme principal d'une partie de démineur
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
    // Saisie des paramètres du jeu (taille de la grille et nombre de mines)
    unsigned int taille, nbMines;
    saisirParametres(taille, nbMines);
    // Instanciation de la grille du démineur
    Grille grille(taille, nbMines);
    // Pour tester/déboguer : on affiche tout de suite la solution
    afficher(grille,true);
    // Itération pour réaliser le déroulement de la partie
    do {
        // On affiche la grille en mode "jeu"
        afficher(grille);
        // On saisit le coup du joueur
        Coup coup = saisirCoup(taille);
        // On met à jour la grille en fonction du coup joué
        grille.mettreAJour(coup);
        // On affiche le résultat après le coup : gagné, perdu ou continuer
        afficherResultatCoup(grille);


    } while (!grille.isFinie()); // on continue tant que la partie n'est pas finie
    // A la fin, on affiche la solution
    cout << endl << "La solution : " << endl;
    afficher(grille,true);
    return 0;
}
