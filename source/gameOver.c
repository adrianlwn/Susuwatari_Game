/*
 * gameOver.c
 *
 *  Created on: 13 janv. 2016
 *      Author: adrian
 */

#include "gameOver.h"

void playGameOver(){
	playSubGameOver();

	int i = 0, x = 17,y =77;
	// Main screen display

	oamSet(&oamMain, 	// oam handler

			i,				// Number of sprite
			x,y,			// Coordinates

			0,				// Priority
			i,				// Palette to use
			SpriteSize_64x64,			// Sprite size
			SpriteColorFormat_256Color,	// Color format
			gfx_gameover_main_1,			// Loaded graphic to display
			-1,				// Affine rotation to use (-1 none)
			false,			// Double size if rotating
			false,			// Hide this sprite
			false, false,	// Horizontal or vertical flip
			false			// Mosaic
	);

	i++;
	x+=64;

	oamSet(&oamMain, 	// oam handler

			i,				// Number of sprite
			x,y,			// Coordinates

			0,				// Priority
			i,				// Palette to use
			SpriteSize_64x64,			// Sprite size
			SpriteColorFormat_256Color,	// Color format
			gfx_gameover_main_2,			// Loaded graphic to display
			-1,				// Affine rotation to use (-1 none)
			false,			// Double size if rotating
			false,			// Hide this sprite
			false, false,	// Horizontal or vertical flip
			false			// Mosaic
	);

	i++;
	x+=64;

	oamSet(&oamMain, 	// oam handler

			i,				// Number of sprite
			x,y,			// Coordinates

			0,				// Priority
			i,				// Palette to use
			SpriteSize_64x64,			// Sprite size
			SpriteColorFormat_256Color,	// Color format
			gfx_gameover_main_3,			// Loaded graphic to display
			-1,				// Affine rotation to use (-1 none)
			false,			// Double size if rotating
			false,			// Hide this sprite
			false, false,	// Horizontal or vertical flip
			false			// Mosaic
	);

	i++;
	x+=64;

	oamSet(&oamMain, 	// oam handler

			i,				// Number of sprite
			x,y,			// Coordinates

			0,				// Priority
			i,				// Palette to use
			SpriteSize_64x64,			// Sprite size
			SpriteColorFormat_256Color,	// Color format
			gfx_gameover_main_4,			// Loaded graphic to display
			-1,				// Affine rotation to use (-1 none)
			false,			// Double size if rotating
			false,			// Hide this sprite
			false, false,	// Horizontal or vertical flip
			false			// Mosaic
	);

	i++;



	oamUpdate(&oamSub);
	oamUpdate(&oamMain);

}
void playSubGameOver(){
	int x=73,y = 29, i =0;
	oamSet(&oamSub, 	// oam handler

			i,				// Number of sprite
			x,y,			// Coordinates
			0,				// Priority
			i,				// Palette to use
			SpriteSize_64x64,			// Sprite size
			SpriteColorFormat_256Color,	// Color format
			gfx_gameover_sub_1,			// Loaded graphic to display
			-1,				// Affine rotation to use (-1 none)
			false,			// Double size if rotating
			false,			// Hide this sprite
			false, false,	// Horizontal or vertical flip
			false			// Mosaic
	);
	x+=64;
	i++;
	oamSet(&oamSub, 	// oam handler

			i,				// Number of sprite
			x,y,			// Coordinates

			0,				// Priority
			i,				// Palette to use
			SpriteSize_64x64,			// Sprite size
			SpriteColorFormat_256Color,	// Color format
			gfx_gameover_sub_2,			// Loaded graphic to display
			-1,				// Affine rotation to use (-1 none)
			false,			// Double size if rotating
			false,			// Hide this sprite
			false, false,	// Horizontal or vertical flip
			false			// Mosaic
	);
	x-=64;
	y = 102;
	i++;
	oamSet(&oamSub, 	// oam handler

			i,				// Number of sprite
			x,y,			// Coordinates

			0,				// Priority
			i,				// Palette to use
			SpriteSize_64x64,			// Sprite size
			SpriteColorFormat_256Color,	// Color format
			gfx_gameover_sub_3,			// Loaded graphic to display
			-1,				// Affine rotation to use (-1 none)
			false,			// Double size if rotating
			false,			// Hide this sprite
			false, false,	// Horizontal or vertical flip
			false			// Mosaic
	);
	x+=64;
	i++;
	oamSet(&oamSub, 	// oam handler

			i,				// Number of sprite
			x,y,			// Coordinates

			0,				// Priority
			i,				// Palette to use
			SpriteSize_64x64,			// Sprite size
			SpriteColorFormat_256Color,	// Color format
			gfx_gameover_sub_4,			// Loaded graphic to display
			-1,				// Affine rotation to use (-1 none)
			false,			// Double size if rotating
			false,			// Hide this sprite
			false, false,	// Horizontal or vertical flip
			false			// Mosaic
	);


}
void playSucess(){
	playSubGameOver();

	int i=0,x =70 , y = 50;
	// Main screen display

	oamSet(&oamMain, 	// oam handler
			i,				// Number of sprite
			x,y,			// Coordinates
			0,				// Priority
			i,				// Palette to use
			SpriteSize_64x64,			// Sprite size
			SpriteColorFormat_256Color,	// Color format
			gfx_sucess_main_1,			// Loaded graphic to display
			-1,				// Affine rotation to use (-1 none)
			false,			// Double size if rotating
			false,			// Hide this sprite
			false, false,	// Horizontal or vertical flip
			false			// Mosaic
	);

	i++;
	x+=64;

	oamSet(&oamMain, 	// oam handler
			i,				// Number of sprite
			x,y,			// Coordinates
			0,				// Priority
			i,				// Palette to use
			SpriteSize_64x64,			// Sprite size
			SpriteColorFormat_256Color,	// Color format
			gfx_sucess_main_2,			// Loaded graphic to display
			-1,				// Affine rotation to use (-1 none)
			false,			// Double size if rotating
			false,			// Hide this sprite
			false, false,	// Horizontal or vertical flip
			false			// Mosaic
	);

	x =32 ;
	y = 105;
	i++;


	oamSet(&oamMain, 	// oam handler
			i,				// Number of sprite
			x,y,			// Coordinates
			0,				// Priority
			i,				// Palette to use
			SpriteSize_64x64,			// Sprite size
			SpriteColorFormat_256Color,	// Color format
			gfx_sucess_main_3,			// Loaded graphic to display
			-1,				// Affine rotation to use (-1 none)
			false,			// Double size if rotating
			false,			// Hide this sprite
			false, false,	// Horizontal or vertical flip
			false			// Mosaic
	);

	i++;
	x+=64;

	oamSet(&oamMain, 	// oam handler

			i,				// Number of sprite
			x,y,			// Coordinates

			0,				// Priority
			i,				// Palette to use
			SpriteSize_64x64,			// Sprite size
			SpriteColorFormat_256Color,	// Color format
			gfx_sucess_main_4,			// Loaded graphic to display
			-1,				// Affine rotation to use (-1 none)
			false,			// Double size if rotating
			false,			// Hide this sprite
			false, false,	// Horizontal or vertical flip
			false			// Mosaic
	);

	i++;
	x+=64;

		oamSet(&oamMain, 	// oam handler

				i,				// Number of sprite
				x,y,			// Coordinates

				0,				// Priority
				i,				// Palette to use
				SpriteSize_64x64,			// Sprite size
				SpriteColorFormat_256Color,	// Color format
				gfx_sucess_main_5,			// Loaded graphic to display
				-1,				// Affine rotation to use (-1 none)
				false,			// Double size if rotating
				false,			// Hide this sprite
				false, false,	// Horizontal or vertical flip
				false			// Mosaic
		);



	oamUpdate(&oamSub);
	oamUpdate(&oamMain);
}
