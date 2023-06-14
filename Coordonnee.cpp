#include "Coordonnee.h"

// A Compléter

Coordonnee::Coordonnee(unsigned int ligne, unsigned int colonne) {
    this -> m_ligne = ligne;
    this -> m_colonne = colonne;
}

unsigned int Coordonnee::getLigne() {
    return this -> m_ligne;
}

unsigned int Coordonnee::getColonne() {
    return this -> m_colonne;
}
