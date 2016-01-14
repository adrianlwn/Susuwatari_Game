/*
 * handlingKeys.c
 *
 *  Created on: 9 janv. 2016
 *      Author: adrian
 */

#include "handlingKeys.h"

void handlingMenuKey(){
	scanKeys();

	u16 keys = keysDown();

	if ((keys & KEY_RIGHT) && levelSelected <8){

		levelSelected++;
	}
	if ((keys & KEY_LEFT) && levelSelected >1){
		levelSelected--;

	}
	if ((keys & KEY_UP) && levelSelected > 4){
		levelSelected -= 4;
	}

	if ((keys & KEY_DOWN) && levelSelected < 5){
		levelSelected += 4;
	}

	if (keys & KEY_A){

		if(levelList[levelSelected-1]->locked == 0){
			goToLevel(levelSelected);}

	}

	// Gestion du touch :

	if (keys & KEY_TOUCH){
		touchPosition pos_menu;
		touchRead(&pos_menu);

		//int held=keysHeld();
		int px = pos_menu.px;
		int py = pos_menu.py;

		// Coordonnées dans un rectangle élémentaire
		int X = px %(8+54);
		int Y = (py - 50) % (63+8);
		// Coordonnée du rectangle élémentaire.
		int nX = px /(8+54);
		int nY = (py - 50) / (63+8);

		if (Y >0 && X > 8 && Y < 63){
			levelSelected = (nX+1) + 4*nY;
		}

		if( px >= 213 && px <= 233 && py >=15 && py <= 33 ){
			if(levelList[levelSelected-1]->locked == 0){
				goToLevel(levelSelected);}
		}
	}

}

void handlingGameOverKey(){
	scanKeys();

	u16 keys = keysDown();

	if (keys & KEY_TOUCH){
		touchPosition pos_menu;
		touchRead(&pos_menu);

		//int held=keysHeld();
		int px = pos_menu.px;
		int py = pos_menu.py;

		if (py > 29 && px > 73 && px < 184 && py < 74){
			goToLevel(levelSelected);
		}

		if (py > 102 && px > 73 && px < 184 && py < 147){
			backToMenu();
		}

	}
}



void handlingStartKey(){
	scanKeys();

	u16 keys = keysDown();
	if (keys & (KEY_START | KEY_A)){
		next_state();
	}
}
void handlingMessageKey(){
	scanKeys();

	u16 keys = keysDown();
	if (keys & (KEY_START | KEY_A)){
		next_state();
	}
}
