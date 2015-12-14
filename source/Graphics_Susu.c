/*
 * Susu.c
 *
 *  Created on: 13 déc. 2015
 *      Author: adrian
 */

#include "Graphics_Susu.h"

void initSusu(pSusu mySusu){
	mySusu->angle=0;
	mySusu->size=5;
	mySusu->v=0;
	mySusu->v_angle=0;
	mySusu->x = 100;
	mySusu->y = 200;

}
void setSusuPosition(pSusu mySusu,double x, double y){
	mySusu->x = x;
	mySusu->y = y;

}
void setSusuAngle(pSusu mySusu,double angle){
	mySusu->angle = angle;
}
void setSusuBigger(pSusu mySusu){

	if (mySusu->size < 10) {
		mySusu->size++;
	}

}
void setSusuSmaller(pSusu mySusu){
	if (mySusu->size  < 0) {
		mySusu->size--;
	}
}

void SusuRotate(pSusu mySusu){

}

void SusuMove(pSusu mySusu){
	int keys;
 	scanKeys();

    	keys = keysHeld();

    	//Modify position of the sprite accordingly
    	if(keys & KEY_RIGHT) mySusu->x +=2;
    	if(keys & KEY_DOWN)  mySusu->y +=2;
    	if(keys & KEY_LEFT) mySusu->x -=2;
    	if(keys & KEY_UP)  mySusu->y -=2;
}

void SusuUpdate(pSusu mySusu){
	displaySusu(mySusu);
}

