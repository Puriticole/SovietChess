# Cahier des charges de SovietChess

L'objectif du présent document est de définir les contraintes et les objetifs du projet.

## Contraintes 
Le projet devra être codé en C++ et utiliser les concepts de la programmation orientée objet.  
Le projet sera entièrement codée sur GITHUB et celui-ci devra être à jour.  
L'utilisation d'un logiciel de création de diagramme UML n'est pas obligatoire. Cepedant, notre groupe se réserve le droit d'tuiliser BOUML si celui-ci lui permet de ganer en productivitée.  
Le projet doit être rendu le : 


## Objetcifs
### Définition des classes d'objectifs
Le but du projet est de coder un jeu d'échecs avec un théme d'inspiration soviétique.  
Les objectifs du projet sont classé par dégrès de faisabilité :
* Simple
* Réalisable
* Complexe
* Ambitieux  
### Engagement 
Nous nous engageons à réaliser le projet jusqu'au degrès de faisabilité Réalisable. Les objectifs possédant un dégrès supérieur sont des bonus.  
### Descriptions des objectifs
Nous nous fixons les objectifs suivants :  
* Simple
  * Définir les classes des différents pions, joueurs et plateau sous une représentation vectorielle, par exemple sous BOUML. 
  * Coder les différents déplacements ainsi que l'affichage du message sur le terminal. 
  * Afficher dans un terminal le déplacement d'un pion, ses coordonées sur le plateau, en utilisant la notation algébrique (voir ci après) ![image](https://user-images.githubusercontent.com/49231937/202475159-92f330fe-7c52-4f40-82a5-02a5ce145e5d.png)
  * Définir les conditions d'erreurs pour un tour (par exemple le joueur blanc veut jouer une piéce noire, le joueur veut sortir sa pièce hors du plateau) ainsi que l'affichage du message.
  * Définir les conditions de prise de piéce et l'affichage du message.
  * Définir l'échec et l'obligation pour le joueur en échec de jouer son roi au prochain tour (en affichants les coups disponibles pour celui-ci).
  * Définir les "zones iradiées" par les piéces pour l'échec et math du roi.

* Réalisable
  * Faire fonctionner toute les fonctionalitées ennoncées dans les objectifs "Simple"
  * Dans le terminal, permettre la saisie des pseudo pour les deux joueurs.
  * Lors du lancemennt de la partie, déterminer aléatoirement, le joueur blanc (commencant en premier) et le joueur noir.
  * Coder les mécanismes permettant le jeu d'une partie amicale et d'un BO3 (best of 3), dans le terminal. -> Finalitée de l'objectif Simple

* Complexe
  * En reprenant les objets et le travail précedement réalisé, coder une version graphique de SovietChess. 
* Ambitieux
  * Coder une IA avec différents niveau de difficulté.
