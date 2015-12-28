/*
 * game.c
 *
 *  Created on: 8 déc. 2015
 *      Author: adrian
 */
#include "game.h"
#include <stdio.h>

pSusu theSusu;

pItem Items[15];


void initGame(){

	theSusu = malloc(sizeof(Susu));
	initSusu(theSusu);
	setSusuAngle(theSusu,360);

	Items[0]= malloc(sizeof(Item));

	chooseItems (Items[0]);
	initItems(Items[0]);
	setItemsPosition( Items[0]);
	displayItems(Items[0]);


}

void playGame(){


	SusuMoveTest2(theSusu);
	//SusuRotate(theSusu,false);
	SusuUpdate(theSusu);



}
