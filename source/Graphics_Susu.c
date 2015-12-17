/*
 * Susu.c
 *
 *  Created on: 13 déc. 2015
 *      Author: adrian
 */

#include "Graphics_Susu.h"

void initSusu(pSusu mySusu){
	mySusu->angle=0;
	mySusu->size=5;
	mySusu->v=0;
	mySusu->v_angle=150;
	mySusu->x = 100;
	mySusu->y = 200;
	mySusu->oamIndex = 0;
	mySusu->gfx_main = oamAllocateGfx(&oamMain, SpriteSize_64x64, SpriteColorFormat_256Color);
	mySusu->gfx_sub = oamAllocateGfx( &oamSub, SpriteSize_64x64, SpriteColorFormat_256Color);
		swiCopy(SusuPal, SPRITE_PALETTE, SusuPalLen/2);
		swiCopy(SusuPal, SPRITE_PALETTE_SUB, SusuPalLen/2);
		swiCopy(SusuTiles, mySusu->gfx_main, SusuTilesLen/2);
		swiCopy(SusuTiles, mySusu->gfx_sub, SusuTilesLen/2);

}
void setSusuPosition(pSusu mySusu,double x, double y){
	mySusu->x = x;
	mySusu->y = y;

}
void setSusuAngle(pSusu mySusu,double angle){
	mySusu->angle = angle;
}
void setSusuBigger(pSusu mySusu){

	if (mySusu->size < 10) {
		mySusu->size++;
	}

}
void setSusuSmaller(pSusu mySusu){
	if (mySusu->size  < 0) {
		mySusu->size--;
	}
}

void SusuRotate(pSusu mySusu){
	mySusu->angle += mySusu->v_angle;
	oamRotateScale(&oamMain,0,mySusu->angle,1 <<8, 1 <<8);
	oamRotateScale(&oamSub,0,mySusu->angle,1 <<8, 1 <<8);

}

void SusuMoveTest(pSusu mySusu){
	int keys;
 	scanKeys();

    	keys = keysHeld();

    	//Modify position of the sprite accordingly
    	if(keys & KEY_RIGHT) mySusu->x +=2;
    	if(keys & KEY_DOWN)  mySusu->y +=2;
    	if(keys & KEY_LEFT) mySusu->x -=2;
    	if(keys & KEY_UP)  mySusu->y -=2;
}

void SusuUpdate(pSusu mySusu){
	//mapSprite((int)mySusu->x,(int)mySusu->y,64);

	if ( (mySusu->y >= 0 ) && ( mySusu->y <= 192)){
		oamSet(&oamMain, 	// oam handler
				0,				// Number of sprite
				(int)mySusu->x,(int)mySusu->y,			// Coordinates
				0,				// Priority
				0,				// Palette to use
				SpriteSize_64x64,			// Sprite size
				SpriteColorFormat_256Color,	// Color format
				mySusu->gfx_main,			// Loaded graphic to display
				0,				// Affine rotation to use (-1 none)
				false,			// Double size if rotating
				false,			// Hide this sprite
				false, false,	// Horizontal or vertical flip
				false			// Mosaic
		);


		oamUpdate(&oamMain);
	}
	if( (mySusu->y >= 192-64 ) && ( mySusu->y <= 2*192 )){
		oamSet(&oamSub, 	// oam handler
				0,				// Number of sprite
				(int)mySusu->x,(int)mySusu->y-192,			// Coordinates
				0,				// Priority
				0,				// Palette to use
				SpriteSize_64x64,			// Sprite size
				SpriteColorFormat_256Color,	// Color format
				mySusu->gfx_sub,			// Loaded graphic to display
				0,				// Affine rotation to use (-1 none)
				false,			// Double size if rotating
				false,			// Hide this sprite
				false, false,	// Horizontal or vertical flip
				false			// Mosaic
		);
		oamUpdate(&oamSub);
	}
	swiWaitForVBlank();
}


