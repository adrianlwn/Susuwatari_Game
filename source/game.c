/*
 * game.c
 *
 *  Created on: 8 déc. 2015
 *      Author: adrian
 */
#include "game.h"
#include <stdio.h>
#include "Graphics_Susu.h"

pSusu theSusu;

pSusu listSusu[5];
pItem Items[15];

mapObstacle theMapObstacle;
int wow_counter,counter;

void initGame(){

	theSusu = malloc(sizeof(Susu));
	initSusu(theSusu);
	//setSusuAngle(theSusu,45);


	initMapObstacle( theMapObstacle);

	Items[0]= malloc(sizeof(Item));

	chooseItems (Items[0]);
	initItems(Items[0]);
	setItemsPosition( Items[0]);
	displayItems(Items[0]);

	counter = 0;


}

void playGame(){


	wow_counter ++;
	SusuMove(theSusu);
	//SusuMoveTest2(theSusu);


	BounceUpdate(theSusu, theMapObstacle);
	SusuUpdate(theSusu);


	if (wow_counter == 200 || wow_counter == 400 || wow_counter == 600 || wow_counter == 800){

			setSusuBigger(theSusu);
		}
	if (wow_counter == 1000 || wow_counter == 1200 || wow_counter == 1400 || wow_counter == 1600){

				setSusuSmaller(theSusu);
			}




}
