/*
 * game.c
 *
 *  Created on: 8 déc. 2015
 *      Author: adrian
 */
#include "game.h"
#include <stdio.h>

pSusu theSusu;
<<<<<<< HEAD
pItem theStar;
mapObstacle theMapObstacle;
=======

pItem Items[15];
>>>>>>> master


void initGame(){

	theSusu = malloc(sizeof(Susu));
	initSusu(theSusu);
	setSusuAngle(theSusu,45);


<<<<<<< HEAD
	theStar = malloc(sizeof(Item));
	initItem(theStar);
	displayItem(theStar);

	initMapObstacle( theMapObstacle);
=======
	Items[0]= malloc(sizeof(Item));

	chooseItems (Items[0]);
	initItems(Items[0]);
	setItemsPosition( Items[0]);
	displayItems(Items[0]);

>>>>>>> master

}

void playGame(){


	SusuMoveTest2(theSusu);
	//SusuRotate(theSusu,false);

	BounceUpdate(theSusu, theMapObstacle);
	SusuUpdate(theSusu);


<<<<<<< HEAD
=======

>>>>>>> master
}
