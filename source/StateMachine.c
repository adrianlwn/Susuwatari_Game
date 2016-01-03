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
			initMenu();
			//interruptions_managment();
			irqInit();
			irqSet (IRQ_KEYS, &ISR_Keys_MENU);
			irqEnable(IRQ_KEYS);
			irqEnable(IRQ_VBLANK);

			next_state();
			break;

		case MENU:
			playMenu();

			break;

		case INIT_GAME :
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

	}
}

void next_state(){
	state_G ++;
}

void ISR_Keys_MENU(){
	u16 keys = ~(REG_KEYINPUT);

	if (keys & KEY_START){

		irqDisable(IRQ_KEYS);
		next_state();
	}
}


void interruptions_managment (){
	switch (state_G) {
	case INIT_MENU :
		irqInit();
		irqSet (IRQ_KEYS, &ISR_Keys_MENU);
		irqEnable(IRQ_KEYS);
		irqEnable(IRQ_VBLANK);
		next_state();

		break;
	case PLAY_GAME :

		break;
	default :
		break;
	}
}


