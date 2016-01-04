/*
 * menu.c
 *
 *  Created on: 8 déc. 2015
 *      Author: adrian
 */
#include "menu.h"


void initMenu(){
	loadGraphics_Menu();
	levelSelected = 1;
}

void playMenu(){
	updateMenu();
}



void updateMenu(){
	int x ,y;
	x = ((levelSelected-1) %4+1 )*8 + ((levelSelected-1) %4 )*54;
	if (levelSelected <=4){
		y = 50;
	}else{
		y = 121;
	}
	oamSet(&oamSub, 	// oam handler

			0,				// Number of sprite
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
	oamUpdate(&oamSub);
}
