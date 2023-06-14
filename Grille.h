#ifndef GRILLE_H
#define GRILLE_H

#include <vector>
#include "Case.h"
#include "Coup.h"
#include "Coordonnee.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Pour représenter la grille du démineur
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Grille {
private:
    unsigned int m_taille; // Taille de la grille : m_taille x m_taille
    unsigned int m_nbMines; // nombre de mines dans la grille
    unsigned int m_nbCoupsDecouvrir; //nombre de coups "découvrir" joué.
    std::vector<std::vector<Case>> m_grille; // la grille (vecteur à deux dimensions)
public:
    // Construit la grille en fonction de la taille et du nombre de mines
    Grille(unsigned int taille, unsigned int nbMines);

    // Retourne la taille de la grille
    unsigned int getTaille();

    // Retourne le nombre de mines dans la grille
    unsigned int getNbMines();

    // Retourne une REFERENCE à la case de la grille située aux coordonnées fournies
    Case &getCase(Coordonnee coordonnee);

    // Met à jour la grille en fonction du coup joué
    void mettreAJour(Coup coup);

    // Retourne vrai si la partie est terminée (perdue ou gagnée)
    bool isFinie();

    // Retourne vrai si la grille contient une case minée et découverte
    bool isPerdue();

    // Retourne vrai si la grille ne contient que des cases minées et couvertes ou des cases non minées et découvertes
    bool isGagnee();

private:
    // Calcule le "nombre de mines autour" pour chaque case de la grille
    void calculeNbMinesAutour();

    // Méthode de classe (static) qui renvoie un nombre aléatoire compris entre 1 et n
    // Une méthode de classe s'utilise comme une fonction "normale".
    // Elle ne s'applique pas à un objet et ne reçoit donc pas de paramètre implicite "this"
    static unsigned int aleatoire(unsigned int n);

    // Méthode qui découvre toutes les voisines de la case indiquée par coordonnée
    // Cette méthode est appelée récursivement sur toutes les voisines non minées, non marquées et qui n'ont pas de mines autour
    void decouvrirVoisines(Coordonnee coordonnee);

    // Retourne le vecteur des coordonnées de toutes les cases voisines de la case indiquée par coordonnee
    std::vector<Coordonnee> getVoisins(Coordonnee coordonnee);
};

#endif //GRILLE_H
