/*
 * StateMachine.h
 *
 *  Created on: 13 déc. 2015
 *      Author: adrian
 */

#ifndef SOURCE_STATEMACHINE_H_
#define SOURCE_STATEMACHINE_H_
#include <nds.h>
#include "init.h"
#include "Graphics_SPRITE.h"
#include "game.h"
#include "menu.h"

typedef enum etat{
		INIT,
		INIT_MENU,
		MENU,
		INIT_GAME,
		PLAY_GAME,
		END
	} state ;


int run();
int level_list[8];
void next_state();

void handlingMenuKey();



#endif /* SOURCE_STATEMACHINE_H_ */
