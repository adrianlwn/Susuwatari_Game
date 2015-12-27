/*
 * StateMachine.cpp
 *
 *  Created on: 13 déc. 2015
 *      Author: adrian
 */

#include "StateMachine.h"


	typedef enum {
		INIT,
		MENU,
		INIT_GAME,
		PLAY_GAME,
		END
	} state ;

int run(){
	state state_G = INIT;


	while(1){

		switch (state_G) {
		case INIT :
			init_NDS();

			state_G = MENU;
			break;
		case MENU:

			state_G = INIT_GAME;
			break;
		case INIT_GAME :
			initGame();
			state_G = PLAY_GAME;
			break;
		case PLAY_GAME:
			playGame();
			//state_G = END;
			break;
		case END :

			break;
		default :
			break;
		}

	}
}

