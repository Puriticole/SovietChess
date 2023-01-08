// Color = 1 == piece blanche
// Right = 1 == piéce à droite de l'échequier droite

//X = représente axe des abscisse en math et l'axe des lettres en référentiel echec
//Y = représente axe des ordonnées en math et l'axe des chiffres en référentiel echec


/*
 * Fonctionnel et testé.
 */

#include "piece.h"


//A désactiver quand tout fonctionne
//#define DEBUG

#include <iostream>
#include <cmath> //pour la fonction abs()

using namespace std;


Piece::Piece()
{
    #ifdef DEBUG
    cout << "Constructeur de base Piece" << endl;
    #endif
}

Piece::~Piece()
{
    #ifdef DEBUG
    cout << "Destructeur de base Piece" << endl;
    #endif
}


/*Fonction de return pour obtenir nos valeurs, afin que nos méthodes intéraggissent avec sans que l'utilisateur du main ne puisse intéragir avec.
 * Utile pour d'autre classe qui n'auront pas accés aux attributs.
 */


//Permet de vérifier si le coup demandé par le joueur est valide
bool Piece::is_In_The_Boad(int x, int y)
{
    if(x >=  1 && x <= 8 && y <= 8 && y >= 1){
        return 1;}
    else{
        return 0;
        cout << "Mouvement invalide, n'est pas dans le plateau" << endl;
    }
}


bool Piece::is_Mov_Valid(int m_x, int m_y)
{
    #ifdef DEBUG
    cout << "Le mouvement de la pièce est valide" << endl;
    #endif
    return true;
}

//Giga con comme nom de fonction mais c'est rigolo
void Piece::MEUUUUUURT(){
    alive = false;
}


void Piece::move(int m_x, int m_y){
    x = m_x;
    y = m_y;
}

Fou::Fou(bool spawn_color, bool right)
{
    x = right ? 6:3;
    y = spawn_color ? 1:8;
    color = spawn_color;
    valeur = 3;
    code_Piece = spawn_color ? 'F':'f';
    alive = true;

    #ifdef DEBUG
    cout << "Fou " << color << "  créé en x:" << x << " y:" << y << endl;
    #endif
}

// Le fou ne peut se déplacer qu'en diagognale
bool Fou::is_Mov_Valid(int m_x, int m_y)
{

    if ((abs(m_x - this->x)) == (abs(m_y - this->y)) && is_In_The_Boad(m_x,m_y) ){ //
        #ifdef DEBUG
        cout << "Le mouvement du fou est valide" << endl;
        #endif
        return true;
    }
    #ifdef DEBUG
    cout << "Le mouvement du fou est non valide" << endl;
    #endif
    return false;
}

Roi::Roi(bool spawn_color)
{
    x = 5;
    y = spawn_color ? 1:8;
    color = spawn_color;
    valeur = 100000;
    code_Piece = spawn_color ? 'K':'k';
    alive = true;

    #ifdef DEBUG
    cout << "Roi " << color << " créé en x:" << x << " y:" << y << endl;
    #endif
}

bool Roi::is_Mov_Valid(int m_x, int m_y){
    if((abs(m_x - this->x) == 1 || abs(m_y - this->y)) && is_In_The_Boad(m_x,m_y)){ // Le roi ne peut bouger que d'une case par une case
        #ifdef DEBUG
        cout << "Le mouvement du Roi est valide" << endl;
        #endif
        return true;
    }
    #ifdef DEBUG
    cout << "Le mouvement du Roi est non valide" << endl;
    #endif
    return false;
}

Reine::Reine(bool spawn_color)
{
    x = 4;
    y = spawn_color?1:8;
    color = spawn_color;
    valeur = 9;
    code_Piece = spawn_color ? 'Q':'q';
    alive = true;

    #ifdef DEBUG
    cout << "Reine " << color << " créé en x:" << x << " y:" << y << endl;
    #endif
}

bool Reine::is_Mov_Valid(int m_x, int m_y){

    if(((m_x==this->x && m_y!=this->y) || (m_x!=this->x && m_y==this->y)) || ((abs(m_x - this->x)) == (abs(m_y - this->y))) && is_In_The_Boad(m_x,m_y)){ //Mouvement du fou et de la tour combiné
        #ifdef DEBUG
        cout << "Le mouvement de la Reine est valide" << endl;
        #endif
        return true;
    }
    #ifdef DEBUG
    cout << "Le mouvement de la Reine est non valide" << endl;
    #endif
    return false;
}

Tour::Tour(bool spawn_color, bool right)
{
    x = (right==0)?1:8;
    y = spawn_color?1:8;
    color = spawn_color;
    valeur = 5;
    code_Piece = spawn_color ? 'T':'t';
    alive = true;

    #ifdef DEBUG
    cout << "Tour " << color << " créé en x:" << x << " y:" << y << endl;
    #endif
}

bool Tour::is_Mov_Valid(int m_x, int m_y){
    if(((m_x==this->x && m_y!=this->y) || (m_x!=this->x && m_y==this->y)) && is_In_The_Boad(m_x,m_y)){
        #ifdef DEBUG
        cout << "Le mouvement de la tour est valide" << endl;
        #endif
        return true;
    }
    #ifdef DEBUG
    cout << "Le mouvement de la tour est non valide" << endl;
    #endif
    return false;
}


Cavalier::Cavalier(bool spawn_color, bool right)
{
    x = right?2:7;
    y = spawn_color?1:8;
    color = spawn_color;
    valeur = 3;
    code_Piece = spawn_color ? 'C':'c';
    alive = true;

    #ifdef DEBUG
    cout << "Cavalier " << color << " créé en x:" << x << " y:" << y << endl;
    #endif
}

//Valeur absolue permet de vérifier le mouvement dans les 2 sens (fonction abs()). Comme le déplacement est sysmétrique, nous n'avons que de deux conditions.
bool Cavalier::is_Mov_Valid(int m_x, int m_y){
    if((abs(m_x-this->x) == 2 && abs(m_y-this->y) == 1 || abs(m_x-this->x) == 1 && abs(m_y-this->y) == 2 ) && is_In_The_Boad(m_x,m_y)){
        #ifdef DEBUG
        cout << "Le mouvement du Cavalier est valide" << endl;
        #endif
        return true;
    }
    #ifdef DEBUG
    cout << "Le mouvement du Cavalier est non valide" << endl;
    #endif
    return false;
}


Pion::Pion(bool spawn_color, int spawn_x)
{
    x = spawn_x;
    y = spawn_color?2:7;
    color = spawn_color;
    valeur = 1;
    code_Piece = spawn_color ?'P':'p';
    alive = true;

    #ifdef DEBUG
    cout << "Pion " << color << " créé en x:" << x << " y:" << y << endl;
    #endif
}

/*Test du mouvement valide du pion un peu plus compliqué.
Ici je prends compte le mouvement normal de déplacement (1 case vers l'avant) && le mouvement d'attaque du pion (1 case en diagonale pour le x & y.
Un autre fonction dans la classe représentant l'échequier devrat se rejouter en plus pour pour confirmer la présence d'une piéce adverse pour définir si le mouvement est ok ou non.
*/
bool Pion::is_Mov_Valid(int m_x, int m_y){
    if(this->color){ //Pion blanc, avance en positif sur l'axe des y
        if((m_y - this->y) == 1 || ((m_y - this->y) == 1 && abs(m_x - this->x) == 1) && is_In_The_Boad(m_x,m_y)){
            #ifdef DEBUG
            cout << "Le mouvement du Pion est valide" << endl;
            #endif
            return true;
        }
        #ifdef DEBUG
        cout << "Le mouvement du Pion est non valide" << endl;
        #endif
        return false;

    }
    else{ //Pion blanc, avance en négatif sur l'axe des y
        if((m_y - this->y) == -1 || ((m_y - this->y) == -1 && abs(m_x - this->x) == 1) && is_In_The_Boad(m_x,m_y)){
            #ifdef DEBUG
            cout << "Le mouvement du Pion est valide" << endl;
            #endif
            return true;
        }
        #ifdef DEBUG
        cout << "Le mouvement du Pion est non valide" << endl;
        #endif
        return false;
    }
}



