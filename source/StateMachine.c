/*
 * StateMachine.cpp
 *
 *  Created on: 13 déc. 2015
 *      Author: adrian
 */

#include "StateMachine.h"

state state_G = INIT;

int run(){

	while(1){

		switch (state_G) {

		case INIT :
			init_NDS();
			next_state();
			break;

		case INIT_MENU :
			//interruptions_managment();
			initMenu();
			configureSpriteMenu();
			next_state();
			break;

		case MENU:
			playMenu();
			handlingMenuKey();
			break;

		case INIT_GAME :
			configureSprite();
			initGame();
			next_state();
			break;

		case PLAY_GAME:
			playGame();

			break;

		case END :
			break;
		default :
			break;
		}
		swiWaitForVBlank();

	}
}

void next_state(){
	state_G ++;
}

void handlingMenuKey(){
	scanKeys();

	u16 keys = keysDown();
	if (keys & KEY_START){
		oamAllocReset(&oamSub);
		next_state();

	}

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
		next_state();

	}

}



