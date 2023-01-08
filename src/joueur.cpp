#include "joueur.h"

//A désactiver quand tout fonctionne
//#define DEBUG

#include <iostream>

using namespace std;



Joueur::Joueur(){
    #ifdef DEBUG
    cout << "Constructeur de joueur par défault" << endl;
    #endif
}


Joueur::~Joueur(){
    #ifdef DEBUG
    cout << "Destructeur de joueur par défault" << endl;
    #endif
}


Joueur::Joueur(bool i_color){
    score_Piece = 0;
    score_Partie = 0;
    color = i_color ? true:false;
    #ifdef DEBUG
    cout << "Constructeur de joueur" << endl;
    #endif
}


void Joueur::ajouter_Piece(Piece* pPiece){

}


