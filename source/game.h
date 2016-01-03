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
pSusu listSusu[5];

pItem Items[15];
int indexTouched;

pPlayer thePlayer;

mapObstacle theMapObstacle;
int wow_counter,counter;

void initGame();
void playGame();
int collision( pSusu mySusu, pItem myItems);
void itemDisappear(int indexTouched );
void initPlayer(pPlayer myPlayer);
void LifeScore(pPlayer myPlayer);
void StarScore(pPlayer myPlayer);

#endif /* GAME_H_ */
