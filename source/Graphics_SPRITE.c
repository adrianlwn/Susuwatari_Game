/*
 * Graphics_SPRITE.c
 *
 *  Created on: 8 déc. 2015
 *      Author: adrian
 */
#include "Graphics_SPRITE.h"
#include "Graphics_Items.h"
#include <nds.h>
#include "Star.h"
#include "Mushroom.h"
#include  "Clover.h"
#include  "Susu24px.h"

#define	SPRITE_WIDTH	64
#define	SPRITE_HEIGHT	64


void configureSprite(){

	VRAM_B_CR = VRAM_ENABLE | VRAM_B_MAIN_SPRITE;
	VRAM_D_CR = VRAM_ENABLE | VRAM_D_SUB_SPRITE;

	// initialisation des deux ecrans pour les sprites. On a activé le extended palette.
	oamInit(&oamMain, SpriteMapping_1D_128,true);
	oamInit(&oamSub, SpriteMapping_1D_128,true);



	// TILES et PALETTE Susu //

	gfx_susu = oamAllocateGfx(&oamMain, SpriteSize_64x64, SpriteColorFormat_256Color);
	gfx_sub_susu= oamAllocateGfx(&oamSub, SpriteSize_64x64, SpriteColorFormat_256Color);


	// VRAM F pour la palette du Susu ( palette 0 pour le Main)
	vramSetBankF(VRAM_F_LCD);
			swiCopy(SusuPal,  &VRAM_F_EXT_SPR_PALETTE[0], SusuPalLen/2);
			// set vram to ex palette
	vramSetBankF(VRAM_F_SPRITE_EXT_PALETTE);
	// VRAM I pour la palette du Susu ( palette 0 pour le Sub)
	vramSetBankI(VRAM_I_LCD);
	swiCopy(SusuPal,  &VRAM_I_EXT_SPR_PALETTE[0], SusuPalLen/2);
	// set vram to ex palette
	vramSetBankI(VRAM_I_SUB_SPRITE_EXT_PALETTE);

		swiCopy(SusuTiles,gfx_susu , SusuTilesLen/2);
		swiCopy(SusuTiles, gfx_sub_susu, SusuTilesLen/2);



		// TILES et PALETTE Items //

	gfx_clover = oamAllocateGfx(&oamMain, SpriteSize_32x32, SpriteColorFormat_256Color);
	gfx_mushroom= oamAllocateGfx(&oamMain, SpriteSize_32x32, SpriteColorFormat_256Color);
	gfx_star = oamAllocateGfx(&oamMain, SpriteSize_32x32, SpriteColorFormat_256Color);

	// VRAM F pour la palette des Items ( palette 1 pour le Main)
	vramSetBankF(VRAM_F_LCD);


	swiCopy(CloverPal,  &VRAM_F_EXT_SPR_PALETTE[2], CloverPalLen/2);
	swiCopy(CloverTiles, gfx_clover, CloverTilesLen/2);


	swiCopy(MushroomPal,  &VRAM_F_EXT_SPR_PALETTE[3], MushroomPalLen/2);
	swiCopy(MushroomTiles, gfx_mushroom, MushroomTilesLen/2);

	swiCopy(StarPal,  &VRAM_F_EXT_SPR_PALETTE[1], StarPalLen/2);
	swiCopy(StarTiles, gfx_star, StarTilesLen/2);


	// set vram to ex palette
   vramSetBankF(VRAM_F_SPRITE_EXT_PALETTE);

}
