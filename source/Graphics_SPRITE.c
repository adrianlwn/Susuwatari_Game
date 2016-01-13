/*
 * Graphics_SPRITE.c
 *
 *  Created on: 8 déc. 2015
 *      Author: adrian
 */
#include "Graphics_SPRITE.h"


#define	SPRITE_WIDTH	64
#define	SPRITE_HEIGHT	64

void clearSprite(){
	// Reinitialisation des index OAM :

	oamClear(&oamMain,0,0);
	oamClear(&oamSub,0,0);

	oamAllocReset(&oamMain);
	oamAllocReset(&oamSub);

	oamUpdate(&oamMain);
	oamUpdate(&oamSub);
}

void initSprite(){
	VRAM_B_CR = VRAM_ENABLE | VRAM_B_MAIN_SPRITE;
	VRAM_D_CR = VRAM_ENABLE | VRAM_D_SUB_SPRITE;

	// initialisation des deux ecrans pour les sprites. On a activé le extended palette.
	oamInit(&oamMain, SpriteMapping_1D_128,true);
	oamInit(&oamSub, SpriteMapping_1D_128,true);
}

void loadSprite(int myLevel){

	// -- INITIALISATION DES SPRITES GENERIQUES
	// Susu 24 px
	const unsigned  int * Susu24pxPal;
	int Susu24pxPalLen;
	const unsigned  short *Susu24pxTiles ;
	int Susu24pxTilesLen;

	// Susu 34 px
	const unsigned  int *Susu34pxPal;
	int Susu34pxPalLen;
	const unsigned  short *Susu34pxTiles ;
	int Susu34pxTilesLen;

	// Susu 44 px
	const unsigned  int *Susu44pxPal;
	int Susu44pxPalLen;
	const unsigned  short *Susu44pxTiles ;
	int Susu44pxTilesLen;

	// Susu 54 px
	const unsigned  int *Susu54pxPal;
	int Susu54pxPalLen;
	const unsigned  short *Susu54pxTiles ;
	int Susu54pxTilesLen;

	// Susu 64 px
	const unsigned  int *Susu64pxPal;
	int Susu64pxPalLen;
	const unsigned short *Susu64pxTiles;
	int Susu64pxTilesLen;


	// -- CHOIX DES SPRITES EN FONCTION DES NIVEAUX
	switch (myLevel) {
	case 1 : // LEVEL 1 SPRITES
		// Susu 24 px
		Susu24pxPalLen = Susu24px_1PalLen;
		Susu24pxPal = &Susu24px_1Pal;
		Susu24pxTilesLen = Susu24px_1TilesLen;
		Susu24pxTiles = &Susu24px_1Tiles;
		// Susu 34 px
		Susu34pxPalLen = Susu34px_1PalLen;
		Susu34pxPal = &Susu34px_1Pal;
		Susu34pxTilesLen = Susu34px_1TilesLen;
		Susu34pxTiles = &Susu34px_1Tiles;
		// Susu 44 px
		Susu44pxPalLen = Susu44px_1PalLen;
		Susu44pxPal = &Susu44px_1Pal;
		Susu44pxTilesLen = Susu44px_1TilesLen;
		Susu44pxTiles = &Susu44px_1Tiles;
		// Susu 54 px
		Susu54pxPalLen = Susu54px_1PalLen;
		Susu54pxPal = &Susu54px_1Pal;
		Susu54pxTilesLen = Susu54px_1TilesLen;
		Susu54pxTiles = &Susu54px_1Tiles;
		// Susu 64 px
		Susu64pxPalLen = Susu64px_1PalLen;
		Susu64pxPal = &Susu64px_1Pal;
		Susu64pxTilesLen = Susu64px_1TilesLen;
		Susu64pxTiles = &Susu64px_1Tiles;

		break;
	case 2 : // LEVEL 2 SPRITES

		// Susu 24 px
		Susu24pxPalLen = Susu24px_2PalLen;
		Susu24pxPal = Susu24px_2Pal;
		Susu24pxTilesLen = Susu24px_2TilesLen;
		Susu24pxTiles = Susu24px_2Tiles;
		// Susu 34 px
		Susu34pxPalLen = Susu34px_2PalLen;
		Susu34pxPal = Susu34px_2Pal;
		Susu34pxTilesLen = Susu34px_2TilesLen;
		Susu34pxTiles = Susu34px_2Tiles;
		// Susu 44 px
		Susu44pxPalLen = Susu44px_2PalLen;
		Susu44pxPal = Susu44px_2Pal;
		Susu44pxTilesLen = Susu44px_2TilesLen;
		Susu44pxTiles = Susu44px_2Tiles;
		// Susu 54 px
		Susu54pxPalLen = Susu54px_2PalLen;
		Susu54pxPal = Susu54px_2Pal;
		Susu54pxTilesLen = Susu54px_2TilesLen;
		Susu54pxTiles = Susu54px_2Tiles;
		// Susu 64 px
		Susu64pxPalLen = Susu64px_2PalLen;
		Susu64pxPal = &Susu64px_2Pal;
		Susu64pxTilesLen = Susu64px_2TilesLen;
		Susu64pxTiles = &Susu64px_2Tiles;

		break;
	case 3 : // LEVEL 3 SPRITES

		// Susu 24 px
		Susu24pxPalLen = Susu24px_3PalLen;
		Susu24pxPal = Susu24px_3Pal;
		Susu24pxTilesLen = Susu24px_3TilesLen;
		Susu24pxTiles = Susu24px_3Tiles;
		// Susu 34 px
		Susu34pxPalLen = Susu34px_3PalLen;
		Susu34pxPal = Susu34px_3Pal;
		Susu34pxTilesLen = Susu34px_3TilesLen;
		Susu34pxTiles = Susu34px_3Tiles;
		// Susu 44 px
		Susu44pxPalLen = Susu44px_3PalLen;
		Susu44pxPal = Susu44px_3Pal;
		Susu44pxTilesLen = Susu44px_3TilesLen;
		Susu44pxTiles = Susu44px_3Tiles;
		// Susu 54 px
		Susu54pxPalLen = Susu54px_3PalLen;
		Susu54pxPal = Susu54px_3Pal;
		Susu54pxTilesLen = Susu54px_3TilesLen;
		Susu54pxTiles = Susu54px_3Tiles;
		// Susu 64 px
		Susu64pxPalLen = Susu64px_3PalLen;
		Susu64pxPal = &Susu64px_3Pal;
		Susu64pxTilesLen = Susu64px_3TilesLen;
		Susu64pxTiles = &Susu64px_3Tiles;

		break;

	case 4 : // LEVEL 4 SPRITES

		// Susu 24 px
		Susu24pxPalLen = Susu24px_4PalLen;
		Susu24pxPal = Susu24px_4Pal;
		Susu24pxTilesLen = Susu24px_4TilesLen;
		Susu24pxTiles = Susu24px_4Tiles;
		// Susu 34 px
		Susu34pxPalLen = Susu34px_4PalLen;
		Susu34pxPal = Susu34px_4Pal;
		Susu34pxTilesLen = Susu34px_4TilesLen;
		Susu34pxTiles = Susu34px_4Tiles;
		// Susu 44 px
		Susu44pxPalLen = Susu44px_4PalLen;
		Susu44pxPal = Susu44px_4Pal;
		Susu44pxTilesLen = Susu44px_4TilesLen;
		Susu44pxTiles = Susu44px_4Tiles;
		// Susu 54 px
		Susu54pxPalLen = Susu54px_4PalLen;
		Susu54pxPal = Susu54px_4Pal;
		Susu54pxTilesLen = Susu54px_4TilesLen;
		Susu54pxTiles = Susu54px_4Tiles;
		// Susu 64 px
		Susu64pxPalLen = Susu64px_4PalLen;
		Susu64pxPal = &Susu64px_4Pal;
		Susu64pxTilesLen = Susu64px_4TilesLen;
		Susu64pxTiles = &Susu64px_4Tiles;

		break;
	case 5 : // LEVEL 5 SPRITES

		// Susu 24 px
		Susu24pxPalLen = Susu24px_5PalLen;
		Susu24pxPal = Susu24px_5Pal;
		Susu24pxTilesLen = Susu24px_5TilesLen;
		Susu24pxTiles = Susu24px_5Tiles;
		// Susu 34 px
		Susu34pxPalLen = Susu34px_5PalLen;
		Susu34pxPal = Susu34px_5Pal;
		Susu34pxTilesLen = Susu34px_5TilesLen;
		Susu34pxTiles = Susu34px_5Tiles;
		// Susu 44 px
		Susu44pxPalLen = Susu44px_5PalLen;
		Susu44pxPal = Susu44px_5Pal;
		Susu44pxTilesLen = Susu44px_5TilesLen;
		Susu44pxTiles = Susu44px_5Tiles;
		// Susu 54 px
		Susu54pxPalLen = Susu54px_5PalLen;
		Susu54pxPal = Susu54px_5Pal;
		Susu54pxTilesLen = Susu54px_5TilesLen;
		Susu54pxTiles = Susu54px_5Tiles;
		// Susu 64 px
		Susu64pxPalLen = Susu64px_5PalLen;
		Susu64pxPal = &Susu64px_5Pal;
		Susu64pxTilesLen = Susu64px_5TilesLen;
		Susu64pxTiles = &Susu64px_5Tiles;

		break;

	case 6 : // LEVEL 6 SPRITES

		// Susu 24 px
		Susu24pxPalLen = Susu24px_6PalLen;
		Susu24pxPal = Susu24px_6Pal;
		Susu24pxTilesLen = Susu24px_6TilesLen;
		Susu24pxTiles = Susu24px_6Tiles;
		// Susu 34 px
		Susu34pxPalLen = Susu34px_6PalLen;
		Susu34pxPal = Susu34px_6Pal;
		Susu34pxTilesLen = Susu34px_6TilesLen;
		Susu34pxTiles = Susu34px_6Tiles;
		// Susu 44 px
		Susu44pxPalLen = Susu44px_6PalLen;
		Susu44pxPal = Susu44px_6Pal;
		Susu44pxTilesLen = Susu44px_6TilesLen;
		Susu44pxTiles = Susu44px_6Tiles;
		// Susu 54 px
		Susu54pxPalLen = Susu54px_6PalLen;
		Susu54pxPal = Susu54px_6Pal;
		Susu54pxTilesLen = Susu54px_6TilesLen;
		Susu54pxTiles = Susu54px_6Tiles;
		// Susu 64 px
		Susu64pxPalLen = Susu64px_6PalLen;
		Susu64pxPal = &Susu64px_6Pal;
		Susu64pxTilesLen = Susu64px_6TilesLen;
		Susu64pxTiles = &Susu64px_6Tiles;

		break;
	case 7 : // LEVEL 7 SPRITES

		// Susu 24 px
		Susu24pxPalLen = Susu24px_7PalLen;
		Susu24pxPal = Susu24px_7Pal;
		Susu24pxTilesLen = Susu24px_7TilesLen;
		Susu24pxTiles = Susu24px_7Tiles;
		// Susu 34 px
		Susu34pxPalLen = Susu34px_7PalLen;
		Susu34pxPal = Susu34px_7Pal;
		Susu34pxTilesLen = Susu34px_7TilesLen;
		Susu34pxTiles = Susu34px_7Tiles;
		// Susu 44 px
		Susu44pxPalLen = Susu44px_7PalLen;
		Susu44pxPal = Susu44px_7Pal;
		Susu44pxTilesLen = Susu44px_7TilesLen;
		Susu44pxTiles = Susu44px_7Tiles;
		// Susu 54 px
		Susu54pxPalLen = Susu54px_7PalLen;
		Susu54pxPal = Susu54px_7Pal;
		Susu54pxTilesLen = Susu54px_7TilesLen;
		Susu54pxTiles = Susu54px_7Tiles;
		// Susu 64 px
		Susu64pxPalLen = Susu64px_7PalLen;
		Susu64pxPal = &Susu64px_7Pal;
		Susu64pxTilesLen = Susu64px_7TilesLen;
		Susu64pxTiles = &Susu64px_7Tiles;

		break;
	case 8 : // LEVEL 8 SPRITES

		// Susu 24 px
		Susu24pxPalLen = Susu24px_8PalLen;
		Susu24pxPal = Susu24px_8Pal;
		Susu24pxTilesLen = Susu24px_8TilesLen;
		Susu24pxTiles = Susu24px_8Tiles;
		// Susu 34 px
		Susu34pxPalLen = Susu34px_8PalLen;
		Susu34pxPal = Susu34px_8Pal;
		Susu34pxTilesLen = Susu34px_8TilesLen;
		Susu34pxTiles = Susu34px_8Tiles;
		// Susu 44 px
		Susu44pxPalLen = Susu44px_8PalLen;
		Susu44pxPal = Susu44px_8Pal;
		Susu44pxTilesLen = Susu44px_8TilesLen;
		Susu44pxTiles = Susu44px_8Tiles;
		// Susu 54 px
		Susu54pxPalLen = Susu54px_8PalLen;
		Susu54pxPal = Susu54px_8Pal;
		Susu54pxTilesLen = Susu54px_8TilesLen;
		Susu54pxTiles = Susu54px_8Tiles;
		// Susu 64 px
		Susu64pxPalLen = Susu64px_8PalLen;
		Susu64pxPal = &Susu64px_8Pal;
		Susu64pxTilesLen = Susu64px_8TilesLen;
		Susu64pxTiles = &Susu64px_8Tiles;

		break;

	}
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

	swiCopy(Susu54pxTiles, gfx_susu_main[3] , Susu54pxTilesLen/2);
	swiCopy(Susu54pxTiles, gfx_susu_sub[3], Susu54pxTilesLen/2);

	swiCopy(Susu64pxTiles,gfx_susu_main[4] , Susu64pxTilesLen/2);
	swiCopy(Susu64pxTiles, gfx_susu_sub[4], Susu64pxTilesLen/2);




	// TILES et PALETTE Items //

	gfx_clover = oamAllocateGfx(&oamMain, SpriteSize_32x32, SpriteColorFormat_256Color);
	gfx_mushroom= oamAllocateGfx(&oamMain, SpriteSize_32x32, SpriteColorFormat_256Color);
	gfx_star = oamAllocateGfx(&oamMain, SpriteSize_32x32, SpriteColorFormat_256Color);
	/*gfx_clover_sub = oamAllocateGfx(&oamSub, SpriteSize_32x32, SpriteColorFormat_256Color);
	gfx_mushroom_sub= oamAllocateGfx(&oamSub, SpriteSize_32x32, SpriteColorFormat_256Color);
	gfx_star_sub = oamAllocateGfx(&oamSub, SpriteSize_32x32, SpriteColorFormat_256Color);*/

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


	nbr_pal_mushroom =7;
	nbr_pal_clover=6;
	nbr_pal_star=5;

	/*// VRAM I pour la palette des Items ( palette 5,6,7) dans le sub
	vramSetBankI(VRAM_I_LCD);

	swiCopy(StarPal,  &VRAM_I_EXT_SPR_PALETTE[5], StarPalLen/2);
	swiCopy(StarTiles, gfx_star_sub, StarTilesLen/2);


	swiCopy(CloverPal,  &VRAM_I_EXT_SPR_PALETTE[6], CloverPalLen/2);
	swiCopy(CloverTiles, gfx_clover_sub, CloverTilesLen/2);


	swiCopy(MushroomPal,  &VRAM_I_EXT_SPR_PALETTE[7], MushroomPalLen/2);
	swiCopy(MushroomTiles, gfx_mushroom_sub, MushroomTilesLen/2);

	// set vram to ex palette
	vramSetBankI(VRAM_I_SUB_SPRITE_EXT_PALETTE); */


	// --------COEUR SCORE
	gfx_heart_score = oamAllocateGfx(&oamSub, SpriteSize_8x16, SpriteColorFormat_256Color);

	// Palette :
	vramSetBankI(VRAM_I_LCD);
	swiCopy(MENU_heartPal,  &VRAM_I_EXT_SPR_PALETTE[8], MENU_heartPalLen/2);
	vramSetBankI(VRAM_I_SUB_SPRITE_EXT_PALETTE);

	// Tiles :
	swiCopy(MENU_heartTiles, gfx_heart_score, MENU_heartTilesLen/2);

	// --------COEUR SCORE - Creux
	gfx_heart_creux_score = oamAllocateGfx(&oamSub, SpriteSize_8x16, SpriteColorFormat_256Color);

	// Palette :
	vramSetBankI(VRAM_I_LCD);
	swiCopy(MENU_heart_creuxPal,  &VRAM_I_EXT_SPR_PALETTE[9], MENU_heart_creuxPalLen/2);
	vramSetBankI(VRAM_I_SUB_SPRITE_EXT_PALETTE);

	// Tiles :
	swiCopy(MENU_heart_creuxTiles, gfx_heart_creux_score, MENU_heart_creuxTilesLen/2);


	// --------STAR SCORE
	gfx_star_score = oamAllocateGfx(&oamSub, SpriteSize_8x16, SpriteColorFormat_256Color);

	// Palette :
	vramSetBankI(VRAM_I_LCD);
	swiCopy(MENU_starPal,  &VRAM_I_EXT_SPR_PALETTE[10], MENU_starPalLen/2);
	vramSetBankI(VRAM_I_SUB_SPRITE_EXT_PALETTE);

	// Tiles :
	swiCopy(MENU_starTiles, gfx_star_score, MENU_starTilesLen/2);

	// --------STAR SCORE - Creux
	gfx_star_creux_score= oamAllocateGfx(&oamSub, SpriteSize_8x16, SpriteColorFormat_256Color);

	// Palette :
	vramSetBankI(VRAM_I_LCD);
	swiCopy(MENU_star_creuxPal,  &VRAM_I_EXT_SPR_PALETTE[11], MENU_star_creuxPalLen/2);
	vramSetBankI(VRAM_I_SUB_SPRITE_EXT_PALETTE);
	// Tiles :
	swiCopy(MENU_star_creuxTiles, gfx_star_creux_score, MENU_star_creuxTilesLen/2);


	nbr_pal_coeur =8;
	nbr_pal_coeur_creux=9;
	nbr_pal_score=10;
	nbr_pal_score_creux=11;

}



void loadSpriteMenu(){


	// Configure Sprites of the Menu :
	// --------CADRE

	gfx_cadre_menu = oamAllocateGfx(&oamSub, SpriteSize_64x64, SpriteColorFormat_256Color);

	// Palette :
	vramSetBankI(VRAM_I_LCD);
	swiCopy(MENU_CADREPal,  &VRAM_I_EXT_SPR_PALETTE[0], MENU_CADREPalLen/2);
	vramSetBankI(VRAM_I_SUB_SPRITE_EXT_PALETTE);

	// Tiles :
	swiCopy(MENU_CADRETiles, gfx_cadre_menu, MENU_CADRETilesLen/2);


	// ---------LOCK
	gfx_lock_menu = oamAllocateGfx(&oamSub, SpriteSize_16x16, SpriteColorFormat_256Color);

	// Palette :
	vramSetBankI(VRAM_I_LCD);
	swiCopy(MENU_lockPal,  &VRAM_I_EXT_SPR_PALETTE[1], MENU_lockPalLen/2);
	vramSetBankI(VRAM_I_SUB_SPRITE_EXT_PALETTE);

	// Tiles :
	swiCopy(MENU_lockTiles, gfx_lock_menu, MENU_lockTilesLen/2);


	// --------COEUR
	gfx_heart_menu = oamAllocateGfx(&oamSub, SpriteSize_8x16, SpriteColorFormat_256Color);

	// Palette :
	vramSetBankI(VRAM_I_LCD);
	swiCopy(MENU_heartPal,  &VRAM_I_EXT_SPR_PALETTE[2], MENU_heartPalLen/2);
	vramSetBankI(VRAM_I_SUB_SPRITE_EXT_PALETTE);

	// Tiles :
	swiCopy(MENU_heartTiles, gfx_heart_menu, MENU_heartTilesLen/2);

	// --------COEUR Creux
	gfx_heart_creux_menu = oamAllocateGfx(&oamSub, SpriteSize_8x16, SpriteColorFormat_256Color);

	// Palette :
	vramSetBankI(VRAM_I_LCD);
	swiCopy(MENU_heart_creuxPal,  &VRAM_I_EXT_SPR_PALETTE[3], MENU_heart_creuxPalLen/2);
	vramSetBankI(VRAM_I_SUB_SPRITE_EXT_PALETTE);

	// Tiles :
	swiCopy(MENU_heart_creuxTiles, gfx_heart_creux_menu, MENU_heart_creuxTilesLen/2);




}
