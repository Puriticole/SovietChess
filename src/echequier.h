/*
 * Classe qui modélise les intéraction entre les pièces, et l'échequier en général.
 * Va avoir besoin d'une intéraction avec la classe modélisant la partie, les joueurs et la classe pièce.
 */
#if !defined Echequier_h
#define Echequier_h

#include "piece.h"
#include "joueur.h"

class Echequier{

protected :
    Piece* cases[100]; //Modélise notre échequier, si aucune piéce dessus, pointeur NULL
public :
    Echequier();
    bool placer_Piece(Piece* pPiece); //A l'initialisation de l'échequier, pour placer les pièces à leur emplamcement de départ
    bool someone_On_The_Way(Piece* pPiece, int m_x, int m_y); //Pour le mouvement d'une pièce, inclue la vérification de colistion (si pièece sur la route de la pièce).
    bool deplacer_Piece(Piece* pPiece, Joueur* pJoueur, int m_x, int m_y);
    Piece* trouver_Piece(int s_x, int s_y); //Permet de chercher la pièce au coordonées indiquées.
    bool supprimer_Piece(Joueur* pJoueur, int m_x, int m_y); //Supprime la pièce de l'échequier quand elle est mangée.
    void afficher_B(); //Affiche l'échéquier vu Blanc dans le terminal.
    void afficher_N(); //Affiche l'échéquier vu Noir dans le terminal.
};

#endif
