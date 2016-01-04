/*
 * Graphics_SPRITE.c
 *
 *  Created on: 8 déc. 2015
 *      Author: adrian
 */
#include "Graphics_SPRITE.h"

#include <nds.h>
#include "Star.h"
#include "Mushroom.h"
#include  "Clover.h"

#include "Susu24px.h"
#include "Susu34px.h"
#include "Susu44px.h"
#include "Susu54px.h"
#include "Susu64px.h"

#include "MENU_CADRE.h"

#define	SPRITE_WIDTH	64
#define	SPRITE_HEIGHT	64

void initSprite(){
	VRAM_B_CR = VRAM_ENABLE | VRAM_B_MAIN_SPRITE;
	VRAM_D_CR = VRAM_ENABLE | VRAM_D_SUB_SPRITE;

	// initialisation des deux ecrans pour les sprites. On a activé le extended palette.
	oamInit(&oamMain, SpriteMapping_1D_128,true);
	oamInit(&oamSub, SpriteMapping_1D_128,true);
}
void configureSprite(){





	// TILES et PALETTE Susu //

	gfx_susu_main[0] = oamAllocateGfx(&oamMain, SpriteSize_64x64, SpriteColorFormat_256Color);
	gfx_susu_sub[0]= oamAllocateGfx(&oamSub, SpriteSize_64x64, SpriteColorFormat_256Color);

	gfx_susu_main[1] = oamAllocateGfx(&oamMain, SpriteSize_64x64, SpriteColorFormat_256Color);
	gfx_susu_sub[1]= oamAllocateGfx(&oamSub, SpriteSize_64x64, SpriteColorFormat_256Color);

	gfx_susu_main[2] = oamAllocateGfx(&oamMain, SpriteSize_64x64, SpriteColorFormat_256Color);
	gfx_susu_sub[2]= oamAllocateGfx(&oamSub, SpriteSize_64x64, SpriteColorFormat_256Color);

	gfx_susu_main[3] = oamAllocateGfx(&oamMain, SpriteSize_64x64, SpriteColorFormat_256Color);
	gfx_susu_sub[3]= oamAllocateGfx(&oamSub, SpriteSize_64x64, SpriteColorFormat_256Color);

	gfx_susu_main[4] = oamAllocateGfx(&oamMain, SpriteSize_64x64, SpriteColorFormat_256Color);
	gfx_susu_sub[4]= oamAllocateGfx(&oamSub, SpriteSize_64x64, SpriteColorFormat_256Color);


	// VRAM F pour la palette du Susu ( palette 0,1,2,3,4 pour le Main)
	vramSetBankF(VRAM_F_LCD);
	swiCopy(Susu24pxPal,  &VRAM_F_EXT_SPR_PALETTE[0], Susu24pxPalLen/2);
	swiCopy(Susu34pxPal,  &VRAM_F_EXT_SPR_PALETTE[1], Susu34pxPalLen/2);
	swiCopy(Susu44pxPal,  &VRAM_F_EXT_SPR_PALETTE[2], Susu44pxPalLen/2);
	swiCopy(Susu54pxPal,  &VRAM_F_EXT_SPR_PALETTE[3], Susu54pxPalLen/2);
	swiCopy(Susu64pxPal,  &VRAM_F_EXT_SPR_PALETTE[4], Susu64pxPalLen/2);
	// set vram to ex palette
	vramSetBankF(VRAM_F_SPRITE_EXT_PALETTE);

	// VRAM I pour la palette du Susu ( palette 0,1,2,3,4 pour le Sub)
	vramSetBankI(VRAM_I_LCD);
	swiCopy(Susu24pxPal,  &VRAM_I_EXT_SPR_PALETTE[0], Susu24pxPalLen/2);
	swiCopy(Susu34pxPal,  &VRAM_I_EXT_SPR_PALETTE[1], Susu34pxPalLen/2);
	swiCopy(Susu44pxPal,  &VRAM_I_EXT_SPR_PALETTE[2], Susu44pxPalLen/2);
	swiCopy(Susu54pxPal,  &VRAM_I_EXT_SPR_PALETTE[3], Susu54pxPalLen/2);
	swiCopy(Susu64pxPal,  &VRAM_I_EXT_SPR_PALETTE[4], Susu64pxPalLen/2);
	// set vram to ex palette
	vramSetBankI(VRAM_I_SUB_SPRITE_EXT_PALETTE);

	swiCopy(Susu24pxTiles,gfx_susu_main[0] , Susu24pxTilesLen/2);
	swiCopy(Susu24pxTiles, gfx_susu_sub[0], Susu24pxTilesLen/2);

	swiCopy(Susu34pxTiles,gfx_susu_main[1] , Susu34pxTilesLen/2);
	swiCopy(Susu34pxTiles, gfx_susu_sub[1], Susu34pxTilesLen/2);

	swiCopy(Susu44pxTiles,gfx_susu_main[2] , Susu44pxTilesLen/2);
	swiCopy(Susu44pxTiles, gfx_susu_sub[2], Susu44pxTilesLen/2);

	swiCopy(Susu54pxTiles,gfx_susu_main[3] , Susu54pxTilesLen/2);
	swiCopy(Susu54pxTiles, gfx_susu_sub[3], Susu54pxTilesLen/2);

	swiCopy(Susu64pxTiles,gfx_susu_main[4] , Susu64pxTilesLen/2);
	swiCopy(Susu64pxTiles, gfx_susu_sub[4], Susu64pxTilesLen/2);




	// TILES et PALETTE Items //

	gfx_clover = oamAllocateGfx(&oamMain, SpriteSize_32x32, SpriteColorFormat_256Color);
	gfx_mushroom= oamAllocateGfx(&oamMain, SpriteSize_32x32, SpriteColorFormat_256Color);
	gfx_star = oamAllocateGfx(&oamMain, SpriteSize_32x32, SpriteColorFormat_256Color);

	gfx_clover_sub = oamAllocateGfx(&oamSub, SpriteSize_32x32, SpriteColorFormat_256Color);
	gfx_mushroom_sub= oamAllocateGfx(&oamSub, SpriteSize_32x32, SpriteColorFormat_256Color);
	gfx_star_sub = oamAllocateGfx(&oamSub, SpriteSize_32x32, SpriteColorFormat_256Color);

	// VRAM F pour la palette des Items ( palette 5,6,7) dans le main
	vramSetBankF(VRAM_F_LCD);

	swiCopy(StarPal,  &VRAM_F_EXT_SPR_PALETTE[5], StarPalLen/2);
	swiCopy(StarTiles, gfx_star, StarTilesLen/2);


	swiCopy(CloverPal,  &VRAM_F_EXT_SPR_PALETTE[6], CloverPalLen/2);
	swiCopy(CloverTiles, gfx_clover, CloverTilesLen/2);


	swiCopy(MushroomPal,  &VRAM_F_EXT_SPR_PALETTE[7], MushroomPalLen/2);
	swiCopy(MushroomTiles, gfx_mushroom, MushroomTilesLen/2);

	// set vram to ex palette
	vramSetBankF(VRAM_F_SPRITE_EXT_PALETTE);


	// VRAM I pour la palette des Items ( palette 5,6,7) dans le sub
	vramSetBankI(VRAM_I_LCD);

	swiCopy(StarPal,  &VRAM_I_EXT_SPR_PALETTE[5], StarPalLen/2);
	swiCopy(StarTiles, gfx_star_sub, StarTilesLen/2);


	swiCopy(CloverPal,  &VRAM_I_EXT_SPR_PALETTE[6], CloverPalLen/2);
	swiCopy(CloverTiles, gfx_clover_sub, CloverTilesLen/2);


	swiCopy(MushroomPal,  &VRAM_I_EXT_SPR_PALETTE[7], MushroomPalLen/2);
	swiCopy(MushroomTiles, gfx_mushroom_sub, MushroomTilesLen/2);

	// set vram to ex palette
	vramSetBankI(VRAM_I_SUB_SPRITE_EXT_PALETTE);







}

void configureSpriteMenu(){
	// Configure Sprites of the Menu :

	gfx_cadre_menu = oamAllocateGfx(&oamSub, SpriteSize_64x64, SpriteColorFormat_256Color);

	// Palette :
	vramSetBankI(VRAM_I_LCD);
	swiCopy(MENU_CADREPal,  &VRAM_I_EXT_SPR_PALETTE[0], MENU_CADREPalLen/2);
	vramSetBankI(VRAM_I_SUB_SPRITE_EXT_PALETTE);

	// Tiles :
	swiCopy(MENU_CADRETiles, gfx_cadre_menu, MENU_CADRETilesLen/2);
}
