/*
 * game.c
 *
 *  Created on: 8 déc. 2015
 *      Author: adrian
 */
#include "game.h"
#include <stdio.h>
#include <nds.h>
#include "Graphics_Susu.h"
#include "Graphics_Items.h"
#include "Star.h"
#include "Mushroom.h"
#include  "Clover.h"
#include "Graphics_SPRITE.h"



void initGame(){

	theSusu = malloc(sizeof(Susu));
	initSusu(theSusu);


	initMapObstacle( theMapObstacle);

	Items[0]= malloc(sizeof(Item));

	chooseItems (Items[0]);
	initItems(Items[0]);
	setItemsPosition( Items[0]);
	displayItems(Items[0]);

	initPlayer(thePlayer);

	counter = 0;


}

void playGame(){


	SusuMove(theSusu);
	BounceUpdate(theSusu, theMapObstacle);

	if(collision(theSusu, Items, Touched)==1)
	{
		if(Touched->itemType==MUSHROOM)
		{ setSusuSmaller(theSusu);
		  thePlayer->life--;}

		if(Touched->itemType==STAR)
			{ thePlayer->score++;
			itemDisappear(Touched);
			// StarScore(thePlayer);}

		if(Touched->itemType==CLOVER)
				{ setSusuBigger(theSusu);
				itemDisappear(Touched);
				  thePlayer->life++;
				 // LifeScore(thePlayer);}
	}

	SusuUpdate(theSusu);


}



int collision( pSusu mySusu, pItem Items[], pItem Touched){
	int i;

for(i=0; i< sizeof(Items) ; i++)
{
	if( InSusuSurface(mySusu, Items[i]->x , Items[i]->y))
	{
	*Touched=*Items[i];
	return 1;
	}
 }
return 0;
}





void itemDisappear(pItem Item )
{
	int halfwidth=16;

	 if(Item->itemType==STAR)
	 {
	 oamSet( &oamMain, 	// oam handler
			 				       Item->oamIndex,				// Number of sprite
			 						(int)Item->x- halfwidth , (int)Item->y- halfwidth ,			// Coordinates
			 						0,				// Priority
			 						0+5,				// Palette to use
			 						SpriteSize_32x32,			// Sprite size
			 						SpriteColorFormat_256Color,	// Color format
									gfx_star,			// Loaded graphic to display
			 						-1,				// Affine rotation to use (-1 none)
			 						false,			// Double size if rotating
			 						true,			// Hide this sprite
			 						false, false,	// Horizontal or vertical flip
			 						false			// Mosaic
									);

	 }

	 if(Item->itemType==CLOVER)
	 {
	 oamSet( &oamMain, 	// oam handler
			 				       Item->oamIndex,				// Number of sprite
			 						(int)Item->x- halfwidth , (int)Item->y- halfwidth ,			// Coordinates
			 						0,				// Priority
			 						1+5,				// Palette to use
			 						SpriteSize_32x32,			// Sprite size
			 						SpriteColorFormat_256Color,	// Color format
									gfx_clover,			// Loaded graphic to display
			 						-1,				// Affine rotation to use (-1 none)
			 						false,			// Double size if rotating
			 						true,			// Hide this sprite
			 						false, false,	// Horizontal or vertical flip
			 						false			// Mosaic
									);
	 }

}

void StarScore(pPlayer myPlayer)
{
	int i;
	 int halfwidth=16;

	for(i=0; i< myPlayer->score; i++)
	{
		 oamSet( &oamSub, 	// oam handler
				 				        i+1,				// Number of sprite
				 						256-i*32- halfwidth , 192- halfwidth ,			// Coordinates
				 						0,				// Priority
				 						5,				// Palette to use
				 						SpriteSize_32x32,			// Sprite size
				 						SpriteColorFormat_256Color,	// Color format
										gfx_star_sub,			// Loaded graphic to display
				 						-1,				// Affine rotation to use (-1 none)
				 						false,			// Double size if rotating
				 						false,			// Hide this sprite
				 						false, false,	// Horizontal or vertical flip
				 						false			// Mosaic
										);
	}
}

void LifeScore(pPlayer myPlayer)
{
	int i;
	 int halfwidth=16;

	for(i=0; i< myPlayer->life; i++)
	{
		 oamSet( &oamSub, 	// oam handler
				 				        i+1+5,				// Number of sprite
				 						0+i*32- halfwidth , 192- halfwidth ,			// Coordinates
				 						0,				// Priority
				 						6,				// Palette to use
				 						SpriteSize_32x32,			// Sprite size
				 						SpriteColorFormat_256Color,	// Color format
										gfx_clover_sub,			// Loaded graphic to display
				 						-1,				// Affine rotation to use (-1 none)
				 						false,			// Double size if rotating
				 						false,			// Hide this sprite
				 						false, false,	// Horizontal or vertical flip
				 						false			// Mosaic
										);
	}
}


void initPlayer(pPlayer myPlayer){

	myPlayer->life=5;
	myPlayer->score=0;
	LifeScore( myPlayer);
	StarScore( myPlayer);


}



