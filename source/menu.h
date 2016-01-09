/*
 * menu.h
 *
 *  Created on: 8 déc. 2015
 *      Author: adrian
 */

#ifndef MENU_H_
#define MENU_H_
#include <nds.h>
#include "Graphics_BG.h"
#include "Graphics_SPRITE.h"
#include "StateMachine.h"
#include "fileSystem.h"


// Level Selected : from 1 to 8


typedef struct Level_struct{
	int level_num; // level number from 1 to 8
	int locked ; // true : locked , false : unlocked
	int best_score ; // best score saved (to display inside the square) from 0 to 5 ( 0 = never played)

} level, *plevel;

int levelSelected;

plevel levelList[8];

void initMenu();
void loadMenu();
void playMenu();
void updateMenu();
void handlingMenuKey();


//void next_state();
//void goToLevel();


#endif /* MENU_H_ */
