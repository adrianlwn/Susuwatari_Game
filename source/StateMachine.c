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
			 timerInit();
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


			if (mmActive() == 0){
				// Resume Playing Music
				mmStart(MOD_ENIGMA,MM_PLAY_LOOP);
				mmSetModuleVolume(1024*50/100);
			}
			next_state();
			break;

		case MENU:
			//mmResume();

			playMenu();
			break;

		case INIT_LV1 :

			// mettre les 2 prochaines fonctions dans initLevel ?
			if (mmActive() == 0){
				// Resume Playing Music
				mmStart(MOD_ENIGMA,MM_PLAY_LOOP);
				mmSetModuleVolume(1024*50/100);
			}
			clearSprite();
			loadSprite(1);
			initLevel(1);
			state_G = PLAY_GAME;
			break;
		case INIT_LV2 :
			if (mmActive() == 0){
				// Resume Playing Music
				mmStart(MOD_ENIGMA,MM_PLAY_LOOP);
				mmSetModuleVolume(1024*50/100);
			}
			clearSprite();
			loadSprite(2);
			initLevel(2);
			state_G = PLAY_GAME;
			break;
		case INIT_LV3 :
			if (mmActive() == 0){
				// Resume Playing Music
				mmStart(MOD_ENIGMA,MM_PLAY_LOOP);
				mmSetModuleVolume(1024*50/100);
			}
			clearSprite();
			loadSprite(3);
			initLevel(3);
			state_G = PLAY_GAME;
			break;
		case INIT_LV4 :
			if (mmActive() == 0){
				// Resume Playing Music
				mmStart(MOD_ENIGMA,MM_PLAY_LOOP);
				mmSetModuleVolume(1024*50/100);
			}
			clearSprite();
			loadSprite(4);
			initLevel(4);
			state_G = PLAY_GAME;
			break;
		case INIT_LV5 :
			if (mmActive() == 0){
				// Resume Playing Music
				mmStart(MOD_ENIGMA,MM_PLAY_LOOP);
				mmSetModuleVolume(1024*50/100);
			}
			clearSprite();
			loadSprite(5);
			initLevel(5);
			state_G = PLAY_GAME;
			break;
		case INIT_LV6 :
			if (mmActive() == 0){
				// Resume Playing Music
				mmStart(MOD_ENIGMA,MM_PLAY_LOOP);
				mmSetModuleVolume(1024*50/100);
			}
			irqEnable(IRQ_TIMER0); // Timer active ici
			clearSprite();
			loadSprite(6);
			initLevel(6);
			state_G = PLAY_GAME;
			break;
		case INIT_LV7 :
			if (mmActive() == 0){
				// Resume Playing Music
				mmStart(MOD_ENIGMA,MM_PLAY_LOOP);
				mmSetModuleVolume(1024*50/100);
			}
			irqEnable(IRQ_TIMER0); // Timer active ici
			clearSprite();
			loadSprite(7);
			initLevel(7);
			state_G = PLAY_GAME;
			break;
		case INIT_LV8 :
			if (mmActive() == 0){
				// Resume Playing Music
				mmStart(MOD_ENIGMA,MM_PLAY_LOOP);
				mmSetModuleVolume(1024*50/100);
			}
			irqEnable(IRQ_TIMER0); // Timer active ici
			clearSprite();
			loadSprite(8);
			initLevel(8);
			state_G = PLAY_GAME;
			break;

		case PLAY_GAME:
			mmResume();
			//irqEnable(IRQ_TIMER0); // Timer active ici
			playGame();
			break;

		case END_LEVEL_INIT :
			irqDisable(IRQ_TIMER0); // Timer desactive ici
			clearSprite();

			loadSpriteGameOver();

			if (thePlayer->score == 5 ){
				loadSpriteSucess();
			}
			else{
			}

			next_state();
			break;
		case END_LEVEL :
			mmStop();
			playGameOver();

			if (thePlayer->score == 5 ){
				playSucess();
			}
			else{

			}
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
	state_G = END_LEVEL_INIT;
}
void backToMenu(){
	state_G = INIT_MENU;
}



