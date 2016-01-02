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

<<<<<<< HEAD
int wow_counter;


=======
>>>>>>> master

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

<<<<<<< HEAD
	wow_counter = 0;


=======
>>>>>>> master
}

void playGame(){

<<<<<<< HEAD
	wow_counter ++;
	SusuMoveTest2(theSusu);
	//SusuRotate(theSusu,false);
=======

	SusuMove(theSusu);
	//SusuMoveTest2(theSusu);

>>>>>>> master

	BounceUpdate(theSusu, theMapObstacle);
	SusuUpdate(theSusu);

	if (wow_counter == 200 ){
		wow_counter = 0;
		setSusuBigger(theSusu);
	}


}
