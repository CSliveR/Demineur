#ifndef INTERFACEUTILISATEUR_H
#define INTERFACEUTILISATEUR_H

#include <string>
#include "Grille.h"
#include "Coup.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Interface en mode texte du jeu du démineur
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
constexpr int TAILLE_MAX = 16;
constexpr int TAILLE_MIN = 2;
constexpr char CASE_VIDE = ' ';
constexpr char CASE_MINEE = 'B';
constexpr char CASE_MARQUEE = 'M';
constexpr char CASE_COUVERTE = '*';

// Saisie sur cin de la taille de la grille et du nombre de mines
void saisirParametres(unsigned int &taille, unsigned int &nbMines);

// Affichage sur cout de la grille :
// Si montrerSolution=vrai
// - les cases minées sont dénotées par CASE_MINEE
// - les cases sans mines autour sont dénotées par CASE_VIDE
// - les cases avec n mines autour sont dénotées par 'n'
// Sinon
// - les cases non découvertes sont dénotées par CASE_CACHEE
// - les cases marquées sont dénotées par CASE_MARQUEE
// - les cases découvertes sans mines autour sont dénotées par CASE_VIDE
// - les cases découvertes avec n mines autour sont dénotées par 'n'
void afficher(Grille grille, bool montrerSolution = false);

// Saisie sur cin du coup d'un joueur :
// - deux entiers compris entre 0 et taille-1
// - un caractère pour l'action : d (découvrir) ou m (marquer)
// Retourne le coup construit à partir de ces informations
Coup saisirCoup(unsigned int taille);

// Affichage sur cout du résultat du dernier coup :
// - "Perdu" si une case minée a été découverte
// - "Gagné" si toutes les cases non minées sont découvertes et toutes les cases minées sont marquées
// - "Continuer" sinon
void afficherResultatCoup(Grille grille);

#endif //INTERFACEUTILISATEUR_H