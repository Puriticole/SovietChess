/*
 * Classe qui modélise les joueurs, permet de savoir combien de pièeces sont encore en vie, leurs scores ect.
 */

#if !defined joueur_h
#define joueur_h

#include "piece.h"

class Joueur{

protected :
    int score_Piece;
    int score_Partie;
    bool color;
public :
    Joueur();
    Joueur(bool color);
    ~Joueur();
    void ajouter_Piece(Piece* pPiece);
    void ajouter_Score_Piece(int v_P){score_Piece += v_P;};
    void victory(){score_Partie += 1;};
    int r_Score_Piece();
    int r_Score_Partie();
};

#endif
