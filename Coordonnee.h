#ifndef COORDONNEE_H
#define COORDONNEE_H

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Pour représenter les coordonnées (ligne, colonne) d'une case de la grille
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Coordonnee {
private:
    unsigned int m_ligne; // le numéro de la ligne
    unsigned int m_colonne; // le numéro de la colonne
public:
    Coordonnee(unsigned int ligne, unsigned int colonne); // Construite une coordonnée selon ligne, colonne
    unsigned int getLigne(); // retourne la ligne de la coordonnée
    unsigned int getColonne(); // retourne la colonne de la coordonnée
};


#endif //COORDONNEE_H
