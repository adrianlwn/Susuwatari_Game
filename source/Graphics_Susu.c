/*
 * Susu.c
 *
 *  Created on: 13 déc. 2015
 *      Author: adrian
 */

#include "Graphics_Susu.h"
#include "Susu.h"

void initSusu(pSusu mySusu){
	mySusu->angle=0;
	mySusu->size=5;
	mySusu->v= 1;
	mySusu->v_angle=150;
	mySusu->x = 0;
	mySusu->y = 0;
	mySusu->oamIndex = 0;
	// Allocate la memoire oam pour la taille du sprite.
	mySusu->gfx_main = oamAllocateGfx(&oamMain, SpriteSize_64x64, SpriteColorFormat_256Color);
	mySusu->gfx_sub = oamAllocateGfx( &oamSub, SpriteSize_64x64, SpriteColorFormat_256Color);
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

		swiCopy(SusuTiles, mySusu->gfx_main, SusuTilesLen/2);
		swiCopy(SusuTiles, mySusu->gfx_sub, SusuTilesLen/2);

}
void setSusuPosition(pSusu mySusu,double x, double y){
	mySusu->x = x;
	mySusu->y = y;

}
void setSusuAngle(pSusu mySusu,double angle){
	mySusu->angle = angle*32768/360;
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

void SusuRotate(pSusu mySusu,int ON){
	if (ON == false){
		mySusu->v_angle = 0;
	}
	mySusu->angle += mySusu->v_angle;


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

// Dans l'écran MAIN  //

	//on affiche le Susu si :
	if ( (mySusu->y >= 0-64 ) && ( mySusu->y <= 192)){
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
				false,			// Hide this sprite     /!\ Susu affiché  !!!
				false, false,	// Horizontal or vertical flip
				false			// Mosaic
		);
		oamRotateScale(&oamMain,0,mySusu->angle,1 <<8, 1 <<8);
	}
	//sinon on le cache :
	else {
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
						true,			// Hide this sprite    /!\ Susu caché !!!
						false, false,	// Horizontal or vertical flip
						false			// Mosaic
				);
		//oamSetHidden(&oamMain,0,true);



	}


	/*//----Rebond
     // si le Susu atteint un bord de l'écran MAIN:
	if(mySusu->y==0 || mySusu->x==0 || mySusu ->x==256)
	{
		int v_init;
	    v_init = mySusu->v; // sauvegarde la vitesse avec laquelle le Susu arrive sur le bord

		mySusu-> v=0;  // Le Susu s'arrête;
		oamRotateScale(&oamMain,0,mySusu->angle +90 ,1 <<8, 1 <<8);//le Susu tourne de 90°;
	    mySusu->v=v_init; //le Susu repart avec sa vitesse avant de toucher le bord;

	}*/


// Dans l'écran SUB //

	//On affiche le  Susu si :
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
		oamRotateScale(&oamSub,0,mySusu->angle,1 <<8, 1 <<8);
	}

	//Sinon on cache le Susu:
	else {
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
						true,			// Hide this sprite
						false, false,	// Horizontal or vertical flip
						false			// Mosaic
				);
		}



	/*//----Rebond
     // si le Susu atteint un bord de l'écran SUB:
	if( mySusu ->y==2*192 || mySusu->x==0 || mySusu ->x==256)
	{
		int v_init;
	    v_init = mySusu->v; // sauvegarde la vitesse avec laquelle le Susu arrive sur le bord

		mySusu-> v=0;  // Le Susu s'arrête;
		oamRotateScale(&oamSub,0,mySusu->angle ,1 <<8, 1 <<8);//le Susu tourne de 90°;//le Susu tourne de 90°;
	    mySusu->v=v_init; //le Susu avec sa vitesse avant de toucher le bord;

	}*/


	// Update the angle of the Susu

	oamUpdate(&oamMain);
	oamUpdate(&oamSub);

	swiWaitForVBlank();
}

void SusuMoveTest2(pSusu mySusu){
	int keys;
	 	scanKeys();

	    	keys = keysHeld();
	if(keys & KEY_RIGHT) mySusu->angle-= 150;
	if(keys & KEY_LEFT) mySusu->angle+= 150;

	mySusu->x += mySusu->v*cos(2*M_PI*mySusu->angle/32768)  ;
	mySusu->y -= mySusu->v*sin(2*M_PI*mySusu->angle/32768)  ;


};



