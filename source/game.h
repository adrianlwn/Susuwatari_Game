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
pItem Items[15];
pPlayer thePlayer;

mapObstacle theMapObstacle;
int wow_counter,counter;


void initLevel1();
void initLevel2();
void initLevel3();
void initLevel4();
void initLevel5();
void initLevel6();
void initLevel7();
void initLevel8();



void playGame();
int collision();
void itemDisappear(int indexTouched);
void initPlayer(pPlayer myPlayer);

void LifeScore(pPlayer myPlayer);
void StarScore(pPlayer myPlayer);

void checkGameOver(pPlayer myPlayer, pSusu mySusu);

#endif /* GAME_H_ */
