/*
 * items.c
 *
 *  Created on: 13 déc. 2015
 *      Author: adrian
 */

#include "Graphics_Items.h"
#include "Graphics_SPRITE.h"
#include <nds.h>
#include "Star.h"
#include "Mushroom.h"
#include  "Clover.h"
#include <stdlib.h>
#include <time.h>






void initItems(pItem myItem){

	int i;
	for(i=0; i<15;i++)
	{
	myItem[i].v= 0;
	myItem[i].oamIndex = i+1;

	if(myItem[i].itemType==MUSHROOM) {myItem[i].gfx_main=gfx_mushroom;}
	if(myItem[i].itemType==STAR) {myItem[i].gfx_main=gfx_star;}
    if(myItem[i].itemType==CLOVER) {myItem[i].gfx_main=gfx_clover;}


}
}

void displayItems(pItem myItem)
{
	int i;
	for(i=0; i<15;i++)
	{

		   if(myItem[i].itemType==MUSHROOM)
		 	   {
		 		oamSet(&oamMain, 	// oam handler
		 				       myItem[i].oamIndex,				// Number of sprite
		 						(int)myItem[i].x, (int) myItem[i].y,			// Coordinates
		 						0,				// Priority
		 						3,				// Palette to use
		 						SpriteSize_32x32,			// Sprite size
		 						SpriteColorFormat_256Color,	// Color format
								gfx_mushroom,			// Loaded graphic to display
		 						-1,				// Affine rotation to use (-1 none)
		 						false,			// Double size if rotating
		 						false,			// Hide this sprite
		 						false, false,	// Horizontal or vertical flip
		 						false			// Mosaic
		 				);
		 	   }

	   if(myItem[i].itemType==STAR)
	   {
		oamSet(&oamMain, 	// oam handler
				        myItem[i].oamIndex,				// Number of sprite
						(int)myItem[i].x, (int)myItem[i].y,			// Coordinates
						0,				// Priority
						1,				// Palette to use
						SpriteSize_32x32,			// Sprite size
						SpriteColorFormat_256Color,	// Color format
						gfx_star,			// Loaded graphic to display
						-1,				// Affine rotation to use (-1 none)
						false,			// Double size if rotating
						false,			// Hide this sprite
						false, false,	// Horizontal or vertical flip
						false			// Mosaic
				);
	   }

	   if(myItem[i].itemType==CLOVER)
	 	   {
	 		oamSet(&oamMain, 	// oam handler
	 				        myItem[i].oamIndex,				// Number of sprite
	 						(int)myItem[i].x, (int)myItem[i].y,			// Coordinates
	 						0,				// Priority
	 						2,				// Palette to use
	 						SpriteSize_32x32,			// Sprite size
	 						SpriteColorFormat_256Color,	// Color format
						gfx_clover,			// Loaded graphic to display
	 						-1,				// Affine rotation to use (-1 none)
	 						false,			// Double size if rotating
	 						false,			// Hide this sprite
	 						false, false,	// Horizontal or vertical flip
	 						false			// Mosaic
	 				);
	 	   }


	}





}



void setItemsPosition(pItem myItem){

	int j;

for(j=0;j<5;j++)
{
myItem[j].x=j*32;
myItem[j].y=0;}

for(j=5;j<10;j++)
{
 myItem[j].x=(j-5)*32;
myItem[j].y=32;}

for(j=10;j<15;j++)
{
	myItem[j].x=(j-10)*32;
myItem[j].y=2*32;}


}






