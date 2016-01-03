/*
 * StateMachine.h
 *
 *  Created on: 13 déc. 2015
 *      Author: adrian
 */

#ifndef SOURCE_STATEMACHINE_H_
#define SOURCE_STATEMACHINE_H_

#include "init.h"
#include "Graphics_SPRITE.h"
#include "game.h"
#include "menu.h"

typedef enum {
		INIT,
		INIT_MENU,
		MENU,
		INIT_GAME,
		PLAY_GAME,
		END
	} state ;


int run();
void next_state();
// --- INTERUPTIONS
void interruptions_managment();
// Timer interruptions handler
void ISR_Timer0();
// Key interuptions handler

void ISR_Keys_MENU();
void ISR_KEYS_GAME();


#endif /* SOURCE_STATEMACHINE_H_ */
