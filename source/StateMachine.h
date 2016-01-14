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
#include "handlingKeys.h"
#include "game.h"
#include "introduction.h"
#include "gameOver.h"
#include "menu.h"
#include "audio.h"
#include "fileSystem.h"


typedef enum etat{
		INIT,
		INIT_START,
		START,
		INIT_MESSAGE,
		MESSAGE,
		INIT_MENU,
		MENU,
		INIT_LV1,
		INIT_LV2,
		INIT_LV3,
		INIT_LV4,
		INIT_LV5,
		INIT_LV6,
		INIT_LV7,
		INIT_LV8,
		PLAY_GAME,
		END_LEVEL_INIT,
		END_LEVEL,
		END
	} state ;


int run();
int level_list[8];
void next_state();
void goToLevel(int myLevel);
void goToEndLevel();
void backToMenu();




#endif /* SOURCE_STATEMACHINE_H_ */
