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
	setSusuAngle(theSusu,360);

}

void playGame(){

	SusuMoveTest2(theSusu);
	//SusuRotate(theSusu,false);
	SusuUpdate(theSusu);

}
