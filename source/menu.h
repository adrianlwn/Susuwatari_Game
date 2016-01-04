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


// Level Selected : from 1 to 8
int levelSelected;

void initMenu();
void playMenu();
void updateMenu();


#endif /* MENU_H_ */
