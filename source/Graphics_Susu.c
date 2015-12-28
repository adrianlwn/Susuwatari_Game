/*
 * Susu.c
 *
 *  Created on: 13 déc. 2015
 *      Author: adrian
 */

#include "Graphics_Susu.h"
#include "Graphics_Items.h"
#include "Graphics_SPRITE.h"
#include "Susu.h"

void initSusu(pSusu mySusu){
	mySusu->angle=0;
	mySusu->new_angle = mySusu->angle;
	mySusu->size=5;
	mySusu->rayon = 32;
	mySusu->v= 1;
	mySusu->v_angle=150;
	mySusu->x = 100;
	mySusu->y = 200;
	mySusu->oamIndex = 0;
	// Allocate la memoire oam pour la taille du sprite.
	mySusu->gfx_main = gfx_susu;
	mySusu->gfx_sub = gfx_sub_susu;


}
void setSusuPosition(pSusu mySusu,double x, double y){
	mySusu->x = x;
	mySusu->y = y;

}

double deg2oamAngle(double angle){
	return angle*32768/360;
}

void setSusuAngle(pSusu mySusu,double angle){
	mySusu->angle = deg2oamAngle(angle);
	mySusu->new_angle = mySusu->angle;
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

void SusuRotateToNewAngle(pSusu mySusu){
	int delta = mySusu->angle - mySusu->new_angle;
	int etha = 100; //
	if(delta > etha){
		mySusu->angle += 100;
	} else if (delta < - etha){
		mySusu->angle -= 100;
	} else {
		mySusu->angle = mySusu->new_angle;
	}
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
	// C'est la moité de la longueur du coté du sprite. Dans la suite cela sert a decaller la position du Susu
	// de facon à ce que la coordonnée du Susu corresponde au centre de celui-ci.
	int halfwidth = 32;

// Dans l'écran MAIN  //

	//on affiche le Susu si :
	if ( (mySusu->y >= 0- halfwidth ) && ( mySusu->y <= 192+ halfwidth)){
		oamSet(&oamMain, 	// oam handler
<<<<<<< HEAD
				0,				// Number of sprite
				(int)mySusu->x - halfwidth ,(int)mySusu->y - halfwidth,			// Coordinates
=======
				mySusu->oamIndex,				// Number of sprite
				(int)mySusu->x,(int)mySusu->y,			// Coordinates
>>>>>>> master
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
<<<<<<< HEAD
						0,				// Number of sprite
						(int)mySusu->x - halfwidth,(int)mySusu->y - halfwidth,			// Coordinates
=======
						mySusu->oamIndex,				// Number of sprite
						(int)mySusu->x,(int)mySusu->y,			// Coordinates
>>>>>>> master
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




// Dans l'écran SUB //

	//On affiche le  Susu si :
	if( (mySusu->y >= 192- halfwidth ) && ( mySusu->y <= 2*192 + halfwidth )){
		oamSet(&oamSub, 	// oam handler
<<<<<<< HEAD
				0,				// Number of sprite
				(int)mySusu->x- halfwidth ,(int)mySusu->y-192 - halfwidth,			// Coordinates
=======
				mySusu->oamIndex,				// Number of sprite
				(int)mySusu->x,(int)mySusu->y-192,			// Coordinates
>>>>>>> master
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
<<<<<<< HEAD
						0,				// Number of sprite
						(int)mySusu->x - halfwidth ,(int)mySusu->y-192 - halfwidth,			// Coordinates
=======
				         mySusu->oamIndex,				// Number of sprite
						(int)mySusu->x,(int)mySusu->y-192,			// Coordinates
>>>>>>> master
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

