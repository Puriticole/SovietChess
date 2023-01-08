#if !defined Partie_h
#define Partie_h

#include "piece.h"
#include "joueur.h"
#include "echequier.h"

class Partie{

protected :
    Echequier e;
    Piece p;
    Joueur JB;
    Joueur JN;
    bool j_Act; //Joueur actuel, 1 pour blanc, 0 pour noir.
    int x, y, m_x, m_y; //Coordonées déplacement
public :
    Partie();
    void init_Partie();
    void Jouons(); // Notre boucle principale de partie
    void fin_Partie(); //Avec les option de revanche etc
    bool verif_Coord();
    bool is_Piece();
    bool verif_Color();
};

#endif
