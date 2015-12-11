/*
 * Graphics_SPRITE.c
 *
 *  Created on: 8 déc. 2015
 *      Author: adrian
 */
#include "Graphics_SPRITE.h"
#include "Player.h"
#define	SPRITE_WIDTH	64
#define	SPRITE_HEIGHT	64

u16* gfx;
//int x = 0, y= 0,
int keys;

void configurePlayer(){
	VRAM_B_CR = VRAM_ENABLE | VRAM_B_MAIN_SPRITE_0x06400000;

	oamInit(&oamMain, SpriteMapping_1D_64,false);

	gfx = oamAllocateGfx(&oamMain, SpriteSize_64x64, SpriteColorFormat_256Color);

	swiCopy(SusuPal, SPRITE_PALETTE, SusuPalLen/2);
	swiCopy(SusuTiles, gfx, SusuTilesLen/2);
}

void displayPlayer(){


	//Position


    	//Read held keys
    	scanKeys();
    	keys = keysHeld();

    	//Modify position of the sprite accordingly
    	if((keys & KEY_RIGHT) && (x < (SCREEN_WIDTH - SPRITE_WIDTH))) x+=2;
    	if((keys & KEY_DOWN) && (y < (SCREEN_HEIGHT - SPRITE_HEIGHT))) y+=2;
    	if((keys & KEY_LEFT) && (x  > 0)) x-=2;
    	if((keys & KEY_UP) && (y  > 0)) y-=2;

    	oamSet(&oamMain, 	// oam handler
    		0,				// Number of sprite
    		x, y,			// Coordinates
    		0,				// Priority
    		0,				// Palette to use
    		SpriteSize_64x64,			// Sprite size
    		SpriteColorFormat_256Color,	// Color format
    		gfx,			// Loaded graphic to display
    		-1,				// Affine rotation to use (-1 none)
    		false,			// Double size if rotating
    		false,			// Hide this sprite
    		false, false,	// Horizontal or vertical flip
    		false			// Mosaic
    		);


    	swiWaitForVBlank();
    	//Update the sprites
		oamUpdate(&oamMain);



}
