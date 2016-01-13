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
			loadMusic();
			loadEffect();
			next_state();
			break;
		case INIT_START :
				mmStart(MOD_ENIGMA,MM_PLAY_LOOP);
				mmSetModuleVolume(1024*50/100);
				loadStart();
				next_state();
				break;
			case START :
				handlingStartKey();

				break;
			case INIT_MESSAGE :
				loadMessage();
				next_state();

				break;
			case MESSAGE :
				handlingMessageKey();

				break;

		case INIT_MENU :
			// Load Graphics of the Menu
			clearSprite();
			loadMenu();
			loadSpriteMenu();
			if (mmActive()){
			// Start Playing Music
			mmStart(MOD_ENIGMA,MM_PLAY_LOOP);
			mmSetModuleVolume(1024*50/100);
			}
			//mmSetModuleTempo()
			next_state();
			break;

		case MENU:
			playMenu();
			break;

		case INIT_LV1 :

			// mettre les 2 prochaines fonctions dans initLevel ?
			mmSetModuleVolume(1024*20/100);
			clearSprite();
			loadSprite(1);
			initLevel1();
			state_G = PLAY_GAME;
			break;
		case INIT_LV2 :
			mmSetModuleVolume(1024*20/100);

			clearSprite();
			loadSprite(2);
			initLevel2();
			state_G = PLAY_GAME;
			break;
		case INIT_LV3 :
			mmSetModuleVolume(1024*20/100);

			clearSprite();
			loadSprite(3);
			initLevel3();
			state_G = PLAY_GAME;
			break;
		case INIT_LV4 :
			mmSetModuleVolume(1024*20/100);

			clearSprite();
			loadSprite(4);
			initLevel4();
			state_G = PLAY_GAME;
			break;
		case INIT_LV5 :
			mmSetModuleVolume(1024*20/100);

			clearSprite();
			loadSprite(5);
			initLevel5();
			state_G = PLAY_GAME;
			break;
		case INIT_LV6 :
			mmSetModuleVolume(1024*20/100);

			clearSprite();
			loadSprite(6);
			initLevel6();
			state_G = PLAY_GAME;
			break;
		case INIT_LV7 :
			mmSetModuleVolume(1024*20/100);

			clearSprite();
			loadSprite(7);
			initLevel7();
			state_G = PLAY_GAME;
			break;
		case INIT_LV8 :
			mmSetModuleVolume(1024*20/100);

			clearSprite();
			loadSprite(8);
			initLevel8();
			state_G = PLAY_GAME;
			break;

		case PLAY_GAME:
			playGame();
			break;

		case END_LEVEL :
			clearSprite();
			mmStop();

			handlingGameOverKey();
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

void goToLevel(int myLevel){
	state_G = INIT_LV1 + (myLevel-1);
}

void goToEndLevel(){
	state_G = END_LEVEL;
}
void backToMenu(){
	state_G = INIT_MENU;
}



