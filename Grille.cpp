#include "Grille.h"
#include <random>
#include "Case.h"
#include "Coordonnee.h"

using namespace std;

Grille::Grille(unsigned int taille, unsigned int nbMines)
        : m_taille(taille), m_nbMines(nbMines) {
    unsigned int nbCasesACreer = taille * taille; // Le nombre de cases qu'il reste à créer
    unsigned int nbMinesAPoser = nbMines; // Le nombre de mines qu'il reste à poser
    // Pour chaque ligne de la grille
    for (unsigned int ligne = 0; ligne < taille; ligne++) {
        // On fabrique un vecteur de taille 'cases' (une nouvelle ligne)
        vector<Case> uneLigne;
        for (unsigned int colonne = 0; colonne < taille; colonne++) {
            // S'il reste nBMinesAPoser dans nbCasesACreer, la probabilité de miner est nbMinesAPoser/nbCasesACreer
            // Donc on tire un nombre aléatoire a dans [1..nbCasesACreer] et on pose une mine si a <= nbMinesAposer
            bool minee = aleatoire(nbCasesACreer) <= nbMinesAPoser;
            nbCasesACreer--; // Une case de moins à créer
            if (minee) nbMinesAPoser--; // une mine de moins à poser
            uneLigne.push_back(minee); // On ajoute une nouvelle case à la ligne
        }
        // On ajoute la nouvelle ligne à la grille
        this->m_grille.push_back(uneLigne);
    }
    // Les cases étant créées et les mines posées, on calcule pour chaque case le 'nombre de mines autour'
    this->calculeNbMinesAutour();
}

unsigned int Grille::getTaille() {
    return this->m_taille;
}

unsigned int Grille::getNbMines() {
    return this->m_nbMines;
}

Case &Grille::getCase(Coordonnee coordonnee) {
    return this->m_grille[coordonnee.getLigne()][coordonnee.getColonne()];
}

void Grille::mettreAJour(Coup coup) {
    Case &laCase = this->getCase(coup.getCoordonnee());
    if (coup.getAction() == MARQUER && !laCase.isDecouverte()) {
        laCase.inverserMarque();
    } else if (coup.getAction() == DECOUVRIR && !laCase.isDecouverte()) {
        laCase.decouvrir();
        this -> m_nbCoupsDecouvrir ++;
        if (!laCase.isMinee() && laCase.getNbMinesAutour() == 0) {
            decouvrirVoisines(coup.getCoordonnee());
        }
    }
}

bool Grille::isFinie() {
// A Compléter
    return this->isPerdue() || this->isGagnee();
}

bool Grille::isPerdue() {
// A Compléter
    bool perdue = false;
    for (int ligne = 0; ligne < m_taille && !perdue; ligne++) {
        for (int colonne = 0; colonne < m_taille && !perdue; colonne++) {
            Coordonnee coord(ligne, colonne);
            if(this->getCase(coord).isMinee() && this->getCase(coord).isDecouverte()){
                perdue = true;
            }
        }
    }
    return perdue;
}

bool Grille::isGagnee() {
// A Compléter
    bool gagnee = true;
    for (int ligne = 0; ligne < m_taille && gagnee; ligne++) {
        for (int colonne = 0; colonne < m_taille && gagnee; colonne++) {
            Coordonnee coord(ligne, colonne);
            if ((this->getCase(coord).isDecouverte() && !this->getCase(coord).isMinee()) ||
                    (!this->getCase(coord).isDecouverte() && this->getCase(coord).isMinee())) {
                gagnee = true;
            } else {
                gagnee = false;
            }
        }

    }
    return gagnee;
}

std::vector<Coordonnee> Grille::getVoisins(Coordonnee coord) {
// A Compléter
    vector<Coordonnee> voisins;
    for (int ligne = (int)coord.getLigne() - 1; ligne <= (int)coord.getLigne() + 1; ligne++) {
        for (int colonne = (int)coord.getColonne() - 1; colonne <= (int)coord.getColonne() + 1; colonne++) {
            if (ligne >= 0 && ligne < this->getTaille()
                && colonne >= 0 && colonne < this->getTaille()
                &&(ligne != coord.getLigne() || colonne != coord.getColonne())) {
                //condition qui vérifie si la case est pas à l'intérieur du jeu et qu'elle n'est pas elle-meme
                voisins.push_back(Coordonnee(ligne, colonne));
            }
        }
    }
    return voisins;
}

void Grille::calculeNbMinesAutour() {
// A Compléter
    for (int ligne = 0; ligne < this->getTaille(); ligne++) {
        for (int colonne = 0; colonne < this->getTaille(); colonne++) {
            //on calcule le nombre de mines autour de la case(ligne, colonne)
            int nbMines = 0;
            vector<Coordonnee> voisins = this->getVoisins(Coordonnee(ligne, colonne));
            for (int i = 0; i < voisins.size(); i++) {
                if (this->getCase(voisins[i]).isMinee()) {
                    nbMines++;
                }
            }
            this->m_grille[ligne][colonne].setNbMinesAutour(nbMines);
        }
    }
}

void Grille::decouvrirVoisines(Coordonnee coordonnee) {
// A Compléter
    vector<Coordonnee> voisines = this->getVoisins(coordonnee);
    for (int i = 0; i < voisines.size(); i++) {
        Case &laVoisine = this->getCase(voisines[i]);
        if (!laVoisine.isDecouverte() && !laVoisine.isMarquee() && !laVoisine.isMinee()) {
            laVoisine.decouvrir();
            if (laVoisine.getNbMinesAutour() == 0) {
                decouvrirVoisines(voisines[i]);
            }
        }
    }
}


unsigned int Grille::aleatoire(unsigned int n) {
    // Retourne un nombre aléatoire compris dans [1..n]
    static std::random_device rd; // variable 'static' : persiste entre 2 appels successifs de la fonction
    static std::mt19937 generateur(rd());
    std::uniform_int_distribution<> distribution(1, n);
    return distribution(generateur);
}


