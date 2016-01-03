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


	initPlayer(thePlayer);

	counter = 0;


}

void playGame(){



	SusuMove(theSusu);
	BounceUpdate(theSusu, theMapObstacle);
	int result=collision(theSusu, Items[0]);

	if(result ==1 && Items[indexTouched]->hidden == 0)
	{


		if( Items[indexTouched]->itemType==MUSHROOM)
		{setSusuSmaller(theSusu);
		itemDisappear(indexTouched);
		thePlayer->life--;
		//LifeScore(thePlayer);

		}


		else if( Items[indexTouched]->itemType==STAR)
		{ thePlayer->score++;
		itemDisappear(indexTouched);
		//StarScore(thePlayer);
		}


		else if( Items[indexTouched]->itemType==CLOVER)
		{ setSusuBigger(theSusu);
		itemDisappear(indexTouched);
		thePlayer->life++;
		//LifeScore(thePlayer);
		}




	}

	displayItems(Items[0]);
	SusuUpdate(theSusu);


}



int collision( pSusu mySusu, pItem myItem){
	int i;

	for(i=0; i< 15 ; i++)
	{
		if( InSusuSurface(mySusu, (u16)myItem[i].x ,(u16)myItem[i].y)==1)
		{
			indexTouched=i;
			return 1;
		}
	}
	return 0;
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



