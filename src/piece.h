//Librairie des pièces.

#if !defined Piece_H
#define Piece_H

/*Classe piece
 * Classe qui va être hérité par tout nos classes pieces filles.
 * Le constructeur ne sert pas à grand chose pour l'instant.
 * Il faudrait peut être le supprimer.
 */
class Piece
{

private :
    int x;
    int y;
    bool color;

public:
    Piece();
    Piece(int x, int y, bool color);
    int r_x();
    int r_y();
    bool is_White();
    bool is_Dead();
}

class Fou : public Piece
{
public:
    Fou(bool color, bool right);
    bool is_Mov_Valid(int x; int y);
}

class Tour : public Piece
{
public:
    Tour(bool color, bool right);
    bool is_Mov_Valid(int x; int y);
}

class Cavalier : public Piece
{
public:
    Cavalier(bool color, bool right);
    bool is_Mov_Valid(int x; int y);
}

class Pion : public Piece
{
public:
    Pion(bool color, int y);
    bool is_Mov_Valid(int x; int y);
}

class Roi : public Piece
{
public:
    Roi(bool color);
    bool is_Mov_Valid(int x; int y);
}

#endif
