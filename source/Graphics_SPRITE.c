/*
 * Graphics_SPRITE.c
 *
 *  Created on: 8 déc. 2015
 *      Author: adrian
 */
#include "Graphics_SPRITE.h"

#define	SPRITE_WIDTH	64
#define	SPRITE_HEIGHT	64

u16 *gfx_main, *gfx_sub;



void configureSprite(){
	VRAM_B_CR = VRAM_ENABLE | VRAM_B_MAIN_SPRITE_0x06400000;
	VRAM_D_CR = VRAM_ENABLE | VRAM_D_SUB_SPRITE;

	oamInit(&oamMain, SpriteMapping_1D_64,false);
	oamInit(&oamSub, SpriteMapping_1D_64,false);

	gfx_main = oamAllocateGfx(&oamMain, SpriteSize_64x64, SpriteColorFormat_256Color);
	gfx_sub = oamAllocateGfx( &oamSub, SpriteSize_64x64, SpriteColorFormat_256Color);
	swiCopy(SusuPal, SPRITE_PALETTE, SusuPalLen/2);
	swiCopy(SusuPal, SPRITE_PALETTE_SUB, SusuPalLen/2);
	swiCopy(SusuTiles, gfx_main, SusuTilesLen/2);
	swiCopy(SusuTiles, gfx_sub, SusuTilesLen/2);

}

void mapSprite(int x, int y, int SpriteL){
	oamSetXY(&oamMain,0,x,y);
	oamSetXY(&oamSub,0,x-192,y);


}

void displaySusu(pSusu mySusu){
	//mapSprite((int)mySusu->x,(int)mySusu->y,64);
	oamSet(&oamMain, 	// oam handler
    		0,				// Number of sprite
    		(int)mySusu->x,(int)mySusu->y,			// Coordinates
    		0,				// Priority
    		0,				// Palette to use
    		SpriteSize_64x64,			// Sprite size
    		SpriteColorFormat_256Color,	// Color format
    		gfx_main,			// Loaded graphic to display
    		-1,				// Affine rotation to use (-1 none)
    		false,			// Double size if rotating
    		false,			// Hide this sprite
    		false, false,	// Horizontal or vertical flip
    		false			// Mosaic
    		);
	oamSet(&oamSub, 	// oam handler
	    		0,				// Number of sprite
	    		(int)mySusu->x,(int)mySusu->y-192,			// Coordinates
	    		0,				// Priority
	    		0,				// Palette to use
	    		SpriteSize_64x64,			// Sprite size
	    		SpriteColorFormat_256Color,	// Color format
	    		gfx_sub,			// Loaded graphic to display
	    		-1,				// Affine rotation to use (-1 none)
	    		false,			// Double size if rotating
	    		false,			// Hide this sprite
	    		false, false,	// Horizontal or vertical flip
	    		false			// Mosaic
	    		);
	oamUpdate(&oamMain);
	oamUpdate(&oamSub);

	swiWaitForVBlank();
}


void displayItems(){


	//Position


    	//Read held keys

/*
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
*/


    	//Update the sprites



}



