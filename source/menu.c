/*
 * menu.c
 *
 *  Created on: 8 déc. 2015
 *      Author: adrian
 */
#include "menu.h"


void initMenu(){
	levelSelected = 1;
	// Initialize The Level List
	int i ;
	for( i = 0 ; i < 8 ; i++){
		levelList[i] =  malloc(sizeof(level));
		// a fait si il n'y a pas de sauvegarde :)
		levelList[i]->best_score = 0;
		levelList[i]->level_num = i+1 ;
		levelList[i]->locked = true;
	}

	levelList[0]->best_score = 0;
	levelList[0]->locked = false;

}

void loadMenu(){
	loadGraphics_Menu();
	readScore();
}

void playMenu(){
	updateMenu();
	handlingMenuKey();
}



void updateMenu(){

	// Gestion du Sprite cadre blanc :
	int x=0 ,y=0;
	int i_oam = 0;
	int i_level = 0;


	x = ((levelSelected-1) %4+1 )*8 + ((levelSelected-1) %4 )*54;
	if (levelSelected <=4){
		y = 50;
	}else{
		y = 121;
	}
	oamSet(&oamSub, 	// oam handler

			i_oam,				// Number of sprite
			x,y,			// Coordinates

			0,				// Priority
			0,				// Palette to use
			SpriteSize_64x64,			// Sprite size
			SpriteColorFormat_256Color,	// Color format
			gfx_cadre_menu,			// Loaded graphic to display
			-1,				// Affine rotation to use (-1 none)
			false,			// Double size if rotating
			false,			// Hide this sprite
			false, false,	// Horizontal or vertical flip
			false			// Mosaic
	);


	// Gestion des sprites "cadenas"
	int X_lock = 23, Y_lock = 44;	// position du cadenas dans le rectangle :

	for(i_level = 1; i_level <= 8; i_level++){
		i_oam ++;
		x = ((i_level-1) %4+1 )*8 + ((i_level-1) %4 )*54 + X_lock ;
		if (i_level <=4){
			y = 50+ Y_lock;
		}else{
			y = 121+Y_lock;
		}
		oamSet(&oamSub, 	// oam handler

				i_oam,				// Number of sprite
				x,y,			// Coordinates

				0,				// Priority
				1,				// Palette to use
				SpriteSize_16x16,			// Sprite size
				SpriteColorFormat_256Color,	// Color format
				gfx_lock_menu,			// Loaded graphic to display
				-1,				// Affine rotation to use (-1 none)
				false,			// Double size if rotating
				! levelList[i_level-1]->locked,			// Hide this sprite
				false, false,	// Horizontal or vertical flip
				false			// Mosaic
		);




	}

	// Gestion des sprites "coeur"

	int i_heart = 0;
	int X_heart = 6, Y_heart =50 ;

	for(i_level = 1; i_level <= 8; i_level++){

		x = ((i_level-1) %4+1 )*8 + ((i_level-1) %4 )*54 + X_heart ;
		if (i_level <=4) {
			y = 50+ Y_heart;}
		else{
			y = 121+Y_heart;}

		for(i_heart = 1; i_heart <=5; i_heart ++){
			i_oam ++;
			int hidden_full = !(!(levelList[i_level-1]->locked) && (i_heart <= levelList[i_level-1]->best_score));
			oamSet(&oamSub, 	// oam handler

					i_oam,				// Number of sprite
					x,y,			// Coordinates

					0,				// Priority
					2,				// Palette to use
					SpriteSize_8x16,			// Sprite size
					SpriteColorFormat_256Color,	// Color format
					gfx_heart_menu,			// Loaded graphic to display
					-1,				// Affine rotation to use (-1 none)
					false,			// Double size if rotating
					hidden_full,			// Hide this sprite
					false, false,	// Horizontal or vertical flip
					false			// Mosaic
			);

			i_oam ++;
			int hidden_empty =(levelList[i_level-1]->locked); // Condition d'affichage
			oamSet(&oamSub, 	// oam handler

					i_oam,				// Number of sprite
					x,y,			// Coordinates

					0,				// Priority
					3,				// Palette to use
					SpriteSize_8x16,			// Sprite size
					SpriteColorFormat_256Color,	// Color format
					gfx_heart_creux_menu,			// Loaded graphic to display
					-1,				// Affine rotation to use (-1 none)
					false,			// Double size if rotating
					hidden_empty,			// Hide this sprite
					false, false,	// Horizontal or vertical flip
					false			// Mosaic
			);


			x+=9;
		}
	}



	oamUpdate(&oamSub);
}


