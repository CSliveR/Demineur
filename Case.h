#ifndef CASE_H
#define CASE_H

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Pour représenter une case de la grille du démineur
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Case {
private:
    bool m_minee; // la case est-elle minee
    bool m_decouverte; // la case est-elle découverte
    bool m_marquee; // la case est-elle marquée
    unsigned int m_nbMinesAutour; // nombre de mines autour de la case
public:
    Case(bool mine); // Construire une case avec ou sans mins
    bool isMinee(); // retourne vrai si la case contient une mine
    bool isDecouverte(); // retourne vrai si la case est découverte
    void decouvrir(); // découvre la case
    bool isMarquee(); // retourne vrai si la case est marquée
    void inverserMarque(); // inverse la marque de la case
    unsigned int getNbMinesAutour(); // retourne le nombre de mines autour de la case
    void setNbMinesAutour(unsigned int nbMinesAutour); // définit le nombre de mines autour de la case

};

#endif //CASE_H
