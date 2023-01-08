#include "partie.h"

//A désactiver quand tout fonctionne
#define DEBUG

#include <iostream>
#include <string>

using namespace std;

//Concstructeur
Partie::Partie(){
    //Création de nos joueurs
    JB = Joueur(true);
    JN = Joueur(false);
    e =  Echequier();
}


void Partie::coord(){
    string move;
    cin >> move;
    x = (int)move[0]-96; //Le x étant sous forme de char ou lettre, on sait que la valeur int de a est 97, on vient le ramener à 1.
    y = (int)move[1]-48;
    m_x = (int)move[2]-96;
    m_y = (int)move[3]-48;
}

bool Partie::verif_Coord(){
    if(p.is_In_The_Boad(x,y) && p.is_In_The_Boad(m_x,m_y))
    {
        return true;
    }
    cout << "Hors limites" << endl;
    return false;
}

bool Partie::is_Piece(){
    if(e.trouver_Piece(x,y) != NULL) //Si la pièce à bouger est de la couleur du joueur
        {
            return true;
        }
    else{
        cout << "Il n'y a pas de pièce ici" << endl;
        return false;
    }
}

bool Partie::verif_Color(){
    if(e.trouver_Piece(x,y)->r_color() == j_Act) //Si la pièce à bouger est de la couleur du joueur
        {
            return true;
        }
    else{
        cout << "Ce n'est pas votre pièce" << endl;
        return false;
    }

}



void Partie::Jouons(){

    bool math = false;

    //Déclaration de nos pièces

	//ROI
	Roi rB(true);e.placer_Piece(&rB);
	Roi rN(false);e.placer_Piece(&rN);
	//Rennes
	Reine RB(true);e.placer_Piece(&RB);
	Reine RN(false);e.placer_Piece(&RN);
	//Fou
	Fou FR(true, true);e.placer_Piece(&FR); //Color, right
	Fou FL(true, false);e.placer_Piece(&FL);
	Fou fR(false, true);e.placer_Piece(&fR); //Color, right
	Fou fL(false, false);e.placer_Piece(&fL);
	//Tour
	Tour TR(true, true);e.placer_Piece(&TR);
	Tour TL(true, false);e.placer_Piece(&TL);
	Tour tR(false, true);e.placer_Piece(&tR);
	Tour tL(false, false);e.placer_Piece(&tL);
	//Cavalier
	Cavalier CR(true, true);e.placer_Piece(&CR);
	Cavalier CL(true, false);e.placer_Piece(&CL);
	Cavalier cR(false, true);e.placer_Piece(&cR);
	Cavalier cL(false, false);e.placer_Piece(&cL);

	//Pion blanc
	Pion P1(true,1);e.placer_Piece(&P1);
	Pion P2(true,2);e.placer_Piece(&P2);
	Pion P3(true,3);e.placer_Piece(&P3);
	Pion P4(true,4);e.placer_Piece(&P4);
	Pion P5(true,5);e.placer_Piece(&P5);
	Pion P6(true,6);e.placer_Piece(&P6);
	Pion P7(true,7);e.placer_Piece(&P7);
	Pion P8(true,8);e.placer_Piece(&P8);
	//Pion Noir
	Pion p1(false,1);e.placer_Piece(&p1);
	Pion p2(false,2);e.placer_Piece(&p2);
	Pion p3(false,3);e.placer_Piece(&p3);
	Pion p4(false,4);e.placer_Piece(&p4);
	Pion p5(false,5);e.placer_Piece(&p5);
	Pion p6(false,6);e.placer_Piece(&p6);
	Pion p7(false,7);e.placer_Piece(&p7);
	Pion p8(false,8);e.placer_Piece(&p8);

	j_Act = true;  //Le joueur blanc commence


    //Boucle de jeu
    while(!math){ //Tant qu'il n'y a pas math, on joue



        //Qui doit jouer ?
        if (j_Act){
             e.afficher_B(); //Affiche le plateau vue blanc (pièce blanches en bas du terminal).
            cout << "Au tour du joueur blanc :" << endl;
        }else{
            e.afficher_N(); //Affiche le plateau vue noir (pièce noires en bas du terminal).
            cout << "Au tour du joueur noir :" << endl;
        }

        //Entrée des coordonnées par le joueur && vérification
        do{
            coord();
        }while(!verif_Coord() && !verif_Color() && !is_Piece());

        // Déplacement de la pièce
        e.deplacer_Piece(e.trouver_Piece(x,y),j_Act?&JB:&JN,m_x,m_y);

        //On vérifie que le roi n'est pas mort
        if(!rB.is_Dead()){
            math =!math; // Il y a math, on sort de notre boucle de partie.
            cout << "Le joueur noir gagne la partie !" << endl;
        }
        if(!rN.is_Dead()){
            math =!math; // Il y a math, on sort de notre boucle de partie.
            cout << "Le joueur blanc gagne la partie !" << endl;
        }
        //On chnage de joueur
        j_Act = !j_Act;
    }
}


