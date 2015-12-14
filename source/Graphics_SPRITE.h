/*
 * Graphics_SPRITE.h
 *
 *  Created on: 8 déc. 2015
 *      Author: adrian
 */

#ifndef GRAPHICS_SPRITE_H_
#define GRAPHICS_SPRITE_H_
#include <nds.h>
#include "Graphics_Susu.h"

#include "Star.h"
#include "Clover.h"
#include "Mushroom.h"
#include "Susu.h"


void configureSprite();
void mapSprite(int x, int y, int SpriteL);
void displayItem();
void displaySusu(pSusu mySusu);






#endif /* GRAPHICS_SPRITE_H_ */
