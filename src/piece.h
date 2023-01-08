//Librairie des pièces.

#if !defined Piece_H //Permet de ne pas avoir deux ou trois les même définition lors du CMAKE.
#define Piece_H

/*Classe piece
 * Classe qui va être hérité par tout nos classes pieces filles.
 * Le constructeur ne sert pas à grand chose pour l'instant.
 * Il faudrait peut être le supprimer.
 */
class Piece
{

protected :
    int x;
    int y;
    bool color;
    int valeur; //Chaque piéce posséde une valeur qui défini sa force sur le terrain. Quand une piéce meurt, l'adverse gagne sa valeur dans son score. La comparaison de ses valeurs affiche l'avantage d'un joueur sur l'autre.
    char code_Piece;
    bool alive;
public:
    Piece();
    Piece(int x, int y, bool color);
    virtual ~Piece();
    int r_x(){return x;};
    int r_y(){return y;};
    int r_valeur(){return valeur;};
    bool r_color(){return color;};
    char r_code(){return code_Piece;};
    bool is_Dead(){return alive;};
    void move(int m_x, int m_y);
    void MEUUUUUURT();
    bool is_In_The_Boad(int x, int y);
    virtual bool is_Mov_Valid(int m_x, int m_y); //Permet à la classe fille de réécrire sur cette méthode.
};

class Fou : virtual public Piece
{
public:
    Fou(bool color, bool right);
    bool is_Mov_Valid(int m_x, int m_y);
};

class Tour : virtual public Piece
{
public:
    Tour(bool color, bool right);
    bool is_Mov_Valid(int m_x, int m_y);
};

class Cavalier : virtual public Piece
{
public:
    Cavalier(bool color, bool right);
    bool is_Mov_Valid(int m_x, int m_y);
};

class Pion : virtual public Piece
{
public:
    Pion(bool color, int spawn_x);
    bool is_Mov_Valid(int m_x, int m_y);
};

class Roi : virtual public Piece
{
public:
    Roi(bool color);
    bool is_Mov_Valid(int m_x, int m_y);
};

class Reine : virtual public Piece
{
public :
    Reine(bool color);
    bool is_Mov_Valid(int m_x, int m_y);
};

#endif
