/*
 * game.c
 *
 *  Created on: 8 déc. 2015
 *      Author: adrian
 */
#include "game.h"

pSusu theSusu;
pItem theStar;
mapObstacle theMapObstacle;


void initGame(){
	theSusu = malloc(sizeof(Susu));
	initSusu(theSusu);
	setSusuAngle(theSusu,45);


	theStar = malloc(sizeof(Item));
	initItem(theStar);
	displayItem(theStar);

	initMapObstacle( theMapObstacle);

}

void playGame(){

	SusuMoveTest2(theSusu);
	//SusuRotate(theSusu,false);

	BounceUpdate(theSusu, theMapObstacle);
	SusuUpdate(theSusu);


}
