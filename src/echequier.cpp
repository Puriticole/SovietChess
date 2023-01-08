#include "echequier.h"

//A désactiver quand tout fonctionne
//#define DEBUG
//#define DEBUG_CONSTRUCTOR
//#define DEBUG_PLACEMENT
//#define DEBUG_AFFICHAGE
//#define DEBUG_DEPLACEMENT

#include <iostream>
#include <cmath> //pour la fonction abs()

using namespace std;

//Constructeur
//Initalise l'échequier vide
Echequier::Echequier(){
    for(int i = 0; i<=100; i++){
        this->cases[i] = NULL;
    }

    #ifdef DEBUG_CONSTRUCTOR
    cout << "L'échequier est créé" << endl;
    #endif
}

/* Place la pièce sur la case de l'échequier a déquoit.
 * Ici on sépare notre tableau tout les 8 cases, ce qui nosu permet de faire une représentation 2D sur un 1D
 */

bool Echequier::placer_Piece(Piece* pPiece){
    if(pPiece != NULL){ //Si piece != NULL somme toute, permet d'éviter un segmentation fault
        this->cases[(pPiece->r_x())+((pPiece->r_y())*8)] = pPiece ;
        #ifdef DEBUG_PLACEMENT
        cout << "Piece " << (pPiece->r_x())+((pPiece->r_y())*8) <<" placée" << endl;
        #endif
        return true;
    }
    #ifdef DEBUG_PLACEMENT
    cout << "Promblème avec le pointer de Piece" << endl;
    #endif
    return false;
}

bool Echequier::supprimer_Piece(Joueur* pJoueur, int m_x, int m_y){
    Piece * pPiece = this->cases[(m_x)+((m_y)*8)];
    if(pPiece!=NULL){
        pPiece->MEUUUUUURT();// Déplacement de la pièce
        pJoueur->ajouter_Score_Piece(pPiece->r_valeur()); //Donne la valeur de la pièce au joueur qui a mangé la pièce.
        this->cases[(m_x)+((m_y)*8)] = NULL;  //Suppresion de la piece du terrain
        return true;
    }
    return false;
    #ifdef DEBUG
    cout << "Promblème avec le pointer de Piece" << endl;
    #endif
}

Piece* Echequier::trouver_Piece(int s_x, int s_y){
    if(this->cases[(s_x)+((s_y)*8)] != NULL){
        return this->cases[(s_x)+((s_y)*8)];
    }
    #ifdef DEBUG
    cout << "Pas de pièce" << endl;
    #endif
    return NULL;
}



//Vérification s'il y a une pièce sur le chemin
bool Echequier::someone_On_The_Way(Piece* pPiece, int m_x, int m_y){
/*
    switch (pPiece->code_Piece)
        case 'R' : //Reine

            break;
        case 'r' : //Roi

            break;
        case 'f' : //Fou
            if(m_x-pPiece->x){

            break;
        case 'c' : //Cavalier

            break;
        case 'p' : //Pion

            break;

*/
}

bool Echequier::deplacer_Piece(Piece* pPiece, Joueur* pJoueur, int m_x, int m_y){

    if(!(pPiece->is_Mov_Valid(m_x,m_y))){ //Cas ou le mouvment n'est pas valide, sort directement de la boucle
        cout << "Mouvement invalide, ne respecte pas les régles de mouvement de votre pièce" << endl;
        return false;
    }

    if(trouver_Piece(m_x,m_y) != NULL){ // Une pièce sur l'arrivée de notre pièce
        if(trouver_Piece(m_x,m_y)->r_color() == pPiece->r_color())
        {
            cout << "Mouvement invalide, une de vos pièces sur cette case" << endl;
            return false;
        }
        else{
            supprimer_Piece(pJoueur, m_x, m_y); //On supprime la pièce du jeu car il tombe sur une pièce adsverse
            //Placement de la pièce sur la case
            this->cases[(pPiece->r_x())+((pPiece->r_y())*8)] = NULL ;
            pPiece->move(m_x,m_y);
            placer_Piece(pPiece); //On peut réutiliser notre fonction car on viens de bouger nos coordonées.
            #ifdef DEBUG_DEPLACEMENT
            cout << "Déplacée" << endl;
            #endif
            return true;
        }
    }
    else //Pas de pièce à l'arrivée
    {
        this->cases[(pPiece->r_x())+((pPiece->r_y())*8)] = NULL ;
        pPiece->move(m_x,m_y);
        placer_Piece(pPiece); //On peut réutiliser notre fonction car on viens de bouger nos coordonées.
        #ifdef DEBUG_DEPLACEMENT
        cout << pPiece->r_y() << endl;
        #endif
        return true;
    }

}

//On pourrait faire une fonction pour afficher en fonction du Joueur.
void Echequier::afficher_B(){


cout << endl << "  abcdefgh" << endl;
  for ( int y = 8; y >= 1; y-- ) // Nous permet d'afficher les noirs d'abord puis ensuite les blancs. On parcoure notre tableau a l'envers.
    {
      cout << y << " ";
      for ( int x = 1; x <= 8; x++ )
	{
	  char c;
	  Piece * p = trouver_Piece( x, y );
      #ifdef DEBUG_AFFICHAGE
        cout << "Pièce : " << x+y*8 << endl;
        #endif

	  if ( p == NULL ){
	    c = ( ( x + y ) % 2 ) == 0 ? '#' : '.';
        }
	  else{

	    c = p->r_code();
        }
	  cout << c;
	}
      cout << " " << y << endl;
    }
  cout << "  abcdefgh" << endl;

}

//On pourrait faire une fonction pour afficher en fonction du Joueur.
void Echequier::afficher_N(){


cout << endl << "  hgfedcba" << endl;
  for ( int y = 1; y <= 8; y++ ) // Nous permet d'afficher les noirs d'abord puis ensuite les blancs. On parcoure notre tableau a l'envers.
    {
      cout << y << " ";
      for ( int x = 8; x >= 1; x-- )
	{
	  char c;
	  Piece * p = trouver_Piece( x, y );
      #ifdef DEBUG_AFFICHAGE
        cout << "Pièce : " << x+y*8 << endl;
        #endif

	  if ( p == NULL ){
	    c = ( ( x + y ) % 2 ) == 0 ? '#' : '.';
        }
	  else{

	    c = p->r_code();
        }
	  cout << c;
	}
      cout << " " << y << endl;
    }
  cout << "  hgfedcba" << endl;

}
