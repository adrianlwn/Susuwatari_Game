/*
 * game.c
 *
 *  Created on: 8 déc. 2015
 *      Author: adrian
 */
#include "game.h"

pSusu theSusu;


void initGame(){
	theSusu = malloc(sizeof(Susu));
	initSusu(theSusu);

}

void playGame(){

	SusuMoveTest(theSusu);
	SusuRotate(theSusu);
	SusuUpdate(theSusu);

}
