#ifndef COUP_H
#define COUP_H

#include "Coordonnee.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Pour représenter les différents types d'action réalisée sur une case
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

enum Action {
    DECOUVRIR, MARQUER
};

// Pour représenter le coup d'un joueur : une action réalisée sur une case dont on donne les coordonnées

class Coup {
private:
    Coordonnee m_coordonnee; // Les coordonnées de la case jouée
    Action m_action; // l'action à réaliser sur la case
public:
    // Construit un coup à partir d'un numéro de ligne, de colonne et une action
    Coup(unsigned int ligne, unsigned int colonne, Action action);
    // Retourne les coordonnées de la case jouée dans le coup
    Coordonnee getCoordonnee();
    // Retourne l'action réalisée dans le coup
    Action getAction();
};


#endif //COUP_H
