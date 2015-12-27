/*
 * items.c
 *
 *  Created on: 13 déc. 2015
 *      Author: adrian
 */

#include "Graphics_Items.h"
#include <nds.h>
#include "Star.h"
#include "Mushroom.h"
#include  "Clover.h"



void initItem(pItem myItem){
	myItem->itemType= STAR;
	//myItem->angle=0;
	//myItem->size=5;
	myItem->v= 0;
	//myItem->v_angle =150;
	myItem->x = 200;
	myItem->y = 100;
	myItem->oamIndex = 1;
	myItem->gfx_main = oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);
	myItem->gfx_sub = oamAllocateGfx( &oamSub, SpriteSize_16x16, SpriteColorFormat_256Color);



	vramSetBankF(VRAM_F_LCD);
		swiCopy(StarPal,  &VRAM_F_EXT_SPR_PALETTE[1], StarPalLen/2);
		// set vram to ex palette
			vramSetBankF(VRAM_F_SPRITE_EXT_PALETTE);

			vramSetBankI(VRAM_I_LCD);
					swiCopy(StarPal,  &VRAM_I_EXT_SPR_PALETTE[1], StarPalLen/2);
					// set vram to ex palette
						vramSetBankI(VRAM_I_SUB_SPRITE_EXT_PALETTE);

		swiCopy(StarTiles, myItem->gfx_main, StarTilesLen/2);
		swiCopy(StarTiles, myItem->gfx_sub , StarTilesLen/2);

}

void displayItem(pItem myItem)
{
		oamSet(&oamMain, 	// oam handler
						1,				// Number of sprite
						(int)myItem->x, (int)myItem->y,			// Coordinates
						0,				// Priority
						1,				// Palette to use
						SpriteSize_16x16,			// Sprite size
						SpriteColorFormat_256Color,	// Color format
						myItem->gfx_main,			// Loaded graphic to display
						-1,				// Affine rotation to use (-1 none)
						false,			// Double size if rotating
						false,			// Hide this sprite
						false, false,	// Horizontal or vertical flip
						false			// Mosaic
				);
}



void setItemPosition(pItem myItem,double x, double y){
	myItem->x = x;
	myItem->y = y;
}
