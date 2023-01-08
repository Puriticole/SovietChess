/*
Créateur Frantz
Date 30.11.22
But : main

*/


#include <iostream>
#include "piece.h"
#include "echequier.h"
#include "joueur.h"
#include "partie.h"

using namespace std;

int main(){
char da;


cout << 		"  █████████     ███████    █████   █████ █████ ██████████ ███████████" <<endl;
cout << 		" ███░░░░░███  ███░░░░░███ ░░███   ░░███ ░░███ ░░███░░░░░█░█░░░███░░░█" <<endl;
cout <<			"░███    ░░░  ███     ░░███ ░███    ░███  ░███  ░███  █ ░ ░   ░███  ░ " <<endl;
cout <<			"░░█████████ ░███      ░███ ░███    ░███  ░███  ░██████       ░███    " <<endl;
cout <<			" ░░░░░░░░███░███      ░███ ░░███   ███   ░███  ░███░░█       ░███    "<<endl;
cout <<			" ███    ░███░░███     ███   ░░░█████░    ░███  ░███ ░   █    ░███    "<<endl;
cout <<			"░░█████████  ░░░███████░      ░░███      █████ ██████████    █████   "<<endl;
cout <<			" ░░░░░░░░░     ░░░░░░░         ░░░      ░░░░░ ░░░░░░░░░░    ░░░░░    "<<endl;
cout <<			"                                                                     "<<endl;
cout <<			"                                                                     "<<endl;
cout <<			"                                                                     "<<endl;
cout <<			"   █████████  █████   █████ ██████████  █████████   █████████        "<<endl;
cout <<			"  ███░░░░░███░░███   ░░███ ░░███░░░░░█ ███░░░░░███ ███░░░░░███       "<<endl;
cout <<			" ███     ░░░  ░███    ░███  ░███  █ ░ ░███    ░░░ ░███    ░░░        "<<endl;
cout <<			"░███          ░███████████  ░██████   ░░█████████ ░░█████████        "<<endl;
cout <<			"░███          ░███░░░░░███  ░███░░█    ░░░░░░░░███ ░░░░░░░░███       "<<endl;
cout <<			"░░███     ███ ░███    ░███  ░███ ░   █ ███    ░███ ███    ░███       "<<endl;
cout <<			" ░░█████████  █████   █████ ██████████░░█████████ ░░█████████        "<<endl;
cout <<			"  ░░░░░░░░░  ░░░░░   ░░░░░ ░░░░░░░░░░  ░░░░░░░░░   ░░░░░░░░░         "<<endl;
cout <<			"                                                                     "<<endl;
cout <<			"                                                                     " <<endl;

cout <<	"Bienvenue Voyageur, vous aller devoir affrontrer votre camarade dans une partie d'échec" <<endl;
cout <<	"Les régles sont simples, pour bouger vos pièces, vous devez entrer sa position puis sa " <<endl;
cout <<	"destination. Par exemple, pour bouger votre pion faites b2b3." <<endl;
cout <<	"Il est important de respecter cet ordre ci. Pas de majuscule, ni d'espace." <<endl;
cout <<	"Le Camarade Staline ne tolére pas la dissidence, rapprelez-vous en Camarade !" <<endl;
	Partie p;
	p.Jouons();
}
