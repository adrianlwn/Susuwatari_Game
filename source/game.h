/*
 * game.h
 *
 *  Created on: 8 déc. 2015
 *      Author: adrian
 */

#ifndef GAME_H_
#define GAME_H_
#include <nds.h>
#include "Graphics_Susu.h"
#include "Graphics_Items.h"
#include "SusuBounce.h"



//---Structure JOUEUR---//
typedef struct Player_struct {
	int score;
	int life;
}Player, *pPlayer;

<<<<<<< HEAD

pSusu theSusu;

// Liste des items //
pItem Items[100]; // changer , mettre nbr_items

=======
// Liste des items utilisée tout a cours de chaque niveau
pItem Items[100];
>>>>>>> master
pPlayer thePlayer;


void initPlayer(pPlayer myPlayer);
void initLevel(int initLevel);

void playGame();//exécute le jeu ;
int collision(); // vérifie si le Susu (sprite) touche un objet et renvoie l'index de l'objet touché;
void itemDisappear(int indexTouched); // l'objet désigné par l'index en argument disparait;

void LifeScore(pPlayer myPlayer); // affiche les vies restantes du joueur;
void StarScore(pPlayer myPlayer);// affiche les étoiles gagnées par le joueur

void checkGameOver(pPlayer myPlayer);

#endif /* GAME_H_ */
