/*
 * Player.cpp

 *
 *  Created on: 11 déc. 2015
 *      Author: valentine
 */

#include "Player.h"


// initPlayer : initialise la position, la direction, la vitesse du joueur. Le sprite ???
void initPlayer(){

	//configure le sprite du joeur
	void configurePlayer();

	 // Position du joueur au début du jeu, milieu de l'écran;
	int x0,y0;
	x=x0;
	y=y0;

	//Vitesse du joueur nulle au début du jeu
	v=0;

	//afficher le sprite
	void displayPlayer();

	//Score du joueur = 0 pts au début du jeu
	score=0;
}
