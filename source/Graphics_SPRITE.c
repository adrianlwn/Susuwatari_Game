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
	VRAM_B_CR = VRAM_ENABLE | VRAM_B_MAIN_SPRITE;
	VRAM_D_CR = VRAM_ENABLE | VRAM_D_SUB_SPRITE;

	// initialisation des deux ecrans pour les sprites. On a activé le extended palette.
	oamInit(&oamMain, SpriteMapping_1D_128,true);
	oamInit(&oamSub, SpriteMapping_1D_128,true);


	vramSetBankF(VRAM_F_LCD);

	// set vram to ex palette
	vramSetBankF(VRAM_F_SPRITE_EXT_PALETTE);



}
