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




