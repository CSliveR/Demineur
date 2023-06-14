#include "Coup.h"

// A Compléter
Coup::Coup(unsigned int ligne, unsigned int colonne, Action action) :
        m_coordonnee(ligne,colonne), m_action(action){
}

Coordonnee Coup::getCoordonnee() {
    return Coordonnee(this -> m_coordonnee.getLigne(), this -> m_coordonnee.getColonne());
}

Action Coup::getAction() {
    return this -> m_action;
}

