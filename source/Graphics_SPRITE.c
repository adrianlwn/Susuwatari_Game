/*
 * Graphics_SPRITE.c
 *
 *  Created on: 8 déc. 2015
 *      Author: adrian
 */
#include "Graphics_SPRITE.h"

#define	SPRITE_WIDTH	64
#define	SPRITE_HEIGHT	64





void configureSprite(){
	VRAM_B_CR = VRAM_ENABLE | VRAM_B_MAIN_SPRITE_0x06400000;
	VRAM_D_CR = VRAM_ENABLE | VRAM_D_SUB_SPRITE;

	oamInit(&oamMain, SpriteMapping_1D_64,false);
	oamInit(&oamSub, SpriteMapping_1D_64,false);



}
