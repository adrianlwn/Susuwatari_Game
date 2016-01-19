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


typedef struct Player_struct {
	int score;
	int life;
}Player, *pPlayer;

pSusu theSusu;
// Liste des items utilisée tout a cours de chaque niveau
pItem Items[100];
pPlayer thePlayer;

void initPlayer(pPlayer myPlayer);
void initLevel(int initLevel);

void playGame();
int collision();
void itemDisappear(int indexTouched);

void LifeScore(pPlayer myPlayer);
void StarScore(pPlayer myPlayer);

void checkGameOver(pPlayer myPlayer, pSusu mySusu);

#endif /* GAME_H_ */
