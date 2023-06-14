#include "Case.h"

// A Compléter
Case::Case(bool mine) {
    this -> m_minee = mine;
}

bool Case::isMinee() {
    return this -> m_minee;
}

bool Case::isDecouverte() {
    return this -> m_decouverte;
}

void Case::decouvrir() {
    this -> m_decouverte = true;
}

bool Case::isMarquee() {
    return this -> m_marquee;
}

void Case::inverserMarque() {
    this -> m_marquee = !this -> m_marquee;
}

unsigned int Case::getNbMinesAutour() {
    return this -> m_nbMinesAutour;
}

void Case::setNbMinesAutour(unsigned int nbMinesAutour) {
    this -> m_nbMinesAutour = nbMinesAutour;
}
