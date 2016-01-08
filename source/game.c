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
#include "Graphics_BG.h"
#include "Graphics_Items.h"

#include "Star.h"
#include "Mushroom.h"
#include  "Clover.h"
#include "Graphics_SPRITE.h"


void initLevel1(){
	// LOAD GAME GRAPHICS
		loadGraphics_Main(1);
		loadGraphics_Sub(1);


		theSusu = malloc(sizeof(Susu));
		initSusu(theSusu);


		initMapObstacle( theMapObstacle);
		int i;
		for(i = 0 ; i <15 ; i++){
			Items[i]= malloc(sizeof(Item));
		}


		chooseItems (Items);
		setItemsPosition( Items);
		initItems(Items);


		initPlayer(thePlayer);
}

void initLevel2(){

}

void initLevel3(){

}

void initLevel4(){

}

void initLevel5(){

}

void initLevel6(){

}

void initLevel7(){

}

void initLevel8(){

}




int previousIndexTouched, indexTouched;

void playGame(){


	SusuMove(theSusu);
	BounceUpdate(theSusu, theMapObstacle);
	previousIndexTouched = indexTouched;
	indexTouched=collision();


	if(indexTouched != -1 && Items[indexTouched]->hidden == 0 && previousIndexTouched != indexTouched)
	{


		if( Items[indexTouched]->itemType == MUSHROOM)
		{
			setSusuSmaller(theSusu);

			itemDisappear(indexTouched);
			thePlayer->life--;
			//LifeScore(thePlayer);

		}


		else if( Items[indexTouched]->itemType == STAR)
		{ thePlayer->score++;
		itemDisappear(indexTouched);
		//StarScore(thePlayer);


		}


		else if( Items[indexTouched]->itemType == CLOVER)
		{ setSusuBigger(theSusu);
		itemDisappear(indexTouched);
		thePlayer->life++;
		//LifeScore(thePlayer);


		}

	}

	displayItems(Items);
	SusuUpdate(theSusu);


}




int collision(){
	int i;
	int indexTouched = -1;
	for(i=0; i< 15 ; i++){
		if( InSusuSurface(theSusu, Items[i]->x, Items[i]->y) ==1)
		{
			indexTouched=i;
		}
	}
	return indexTouched;
}





void itemDisappear(int indexTouched)
{
	Items[indexTouched]->hidden=1;
}

void StarScore(pPlayer myPlayer)
{
	int i;
	int halfwidth=16;

	for(i=0; i< myPlayer->score; i++)
	{
		//tiles ?
		oamSet( &oamSub, 	// oam handler
				i+5,				// Number of sprite
				256-32-i*32- halfwidth ,192-32- halfwidth ,			// Coordinates
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
				i+5+5,				// Number of sprite
				0+i*32- halfwidth , 192-32- halfwidth ,			// Coordinates
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



