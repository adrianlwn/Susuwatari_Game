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
#include "menu.h"

#include "Star.h"
#include "Mushroom.h"
#include  "Clover.h"
#include "Graphics_SPRITE.h"

#define HAUTEUR 192
#define LARGEUR 256
#define DECALAGE 96


void initLevel1(){
	// LOAD GAME GRAPHICS
		loadGraphics_Main(1);
		loadGraphics_Sub(1);


		theSusu = malloc(sizeof(Susu));
		initSusu(theSusu);


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
	loadGraphics_Main(2);
		loadGraphics_Sub(2);


		theSusu = malloc(sizeof(Susu));
		initSusu(theSusu);


		int i;
		for(i = 0 ; i <15 ; i++){
			Items[i]= malloc(sizeof(Item));
		}


		chooseItems (Items);
		setItemsPosition( Items);
		initItems(Items);


		initPlayer(thePlayer);
}

void initLevel3(){
	loadGraphics_Main(3);
		loadGraphics_Sub(3);


		theSusu = malloc(sizeof(Susu));
		initSusu(theSusu);


		int i;
		for(i = 0 ; i <15 ; i++){
			Items[i]= malloc(sizeof(Item));
		}


		chooseItems (Items);
		setItemsPosition( Items);
		initItems(Items);


		initPlayer(thePlayer);
}

void initLevel4(){
	loadGraphics_Main(4);
		loadGraphics_Sub(4);


		theSusu = malloc(sizeof(Susu));
		initSusu(theSusu);


		int i;
		for(i = 0 ; i <15 ; i++){
			Items[i]= malloc(sizeof(Item));
		}


		chooseItems (Items);
		setItemsPosition( Items);
		initItems(Items);


		initPlayer(thePlayer);
}

void initLevel5(){
	loadGraphics_Main(5);
		loadGraphics_Sub(5);


		theSusu = malloc(sizeof(Susu));
		initSusu(theSusu);


		int i;
		for(i = 0 ; i <15 ; i++){
			Items[i]= malloc(sizeof(Item));
		}


		chooseItems (Items);
		setItemsPosition( Items);
		initItems(Items);


		initPlayer(thePlayer);
}

void initLevel6(){
	loadGraphics_Main(6);
		loadGraphics_Sub(6);


		theSusu = malloc(sizeof(Susu));
		initSusu(theSusu);


		int i;
		for(i = 0 ; i <15 ; i++){
			Items[i]= malloc(sizeof(Item));
		}


		chooseItems (Items);
		setItemsPosition( Items);
		initItems(Items);


		initPlayer(thePlayer);
}

void initLevel7(){
	loadGraphics_Main(7);
		loadGraphics_Sub(7);


		theSusu = malloc(sizeof(Susu));
		initSusu(theSusu);


		int i;
		for(i = 0 ; i <15 ; i++){
			Items[i]= malloc(sizeof(Item));
		}


		chooseItems (Items);
		setItemsPosition( Items);
		initItems(Items);


		initPlayer(thePlayer);
}

void initLevel8(){
	loadGraphics_Main(8);
		loadGraphics_Sub(8);


		theSusu = malloc(sizeof(Susu));
		initSusu(theSusu);


		int i;
		for(i = 0 ; i <15 ; i++){
			Items[i]= malloc(sizeof(Item));
		}


		chooseItems (Items);
		setItemsPosition( Items);
		initItems(Items);


		initPlayer(thePlayer);
}


int previousIndexTouched, indexTouched;

void playGame(){

	checkGameOver(thePlayer, theSusu);
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
			LifeScore(thePlayer);

		}


		else if( Items[indexTouched]->itemType == STAR)
		{ thePlayer->score++;
		itemDisappear(indexTouched);
		StarScore(thePlayer);


		}


		else if( Items[indexTouched]->itemType == CLOVER)
		{ setSusuBigger(theSusu);
		itemDisappear(indexTouched);
		if (thePlayer->life <5){
		thePlayer->life++;}
		LifeScore(thePlayer);


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

void checkGameOver(pPlayer myPlayer, pSusu mySusu){
	int nb_max_stars = 5;

	// --- LEVEL ACCOMPLISHED :
	// quand toutes les etoiles sont ramassées.
	if (myPlayer->score == nb_max_stars){
		levelList[levelSelected-1]->best_score = mySusu->size +1;
		levelList[levelSelected]->locked = false;

		writeScore();
		goToEndLevel();

	}

	// --- LEVEL FAILED :
	// Si le joueur perd toutes ses vies. Ou si le Susu a une vitesse 0 sur l'ecran du haut.
	if (myPlayer->life == 0 || (mySusu->v == 0 && mySusu->y < HAUTEUR + DECALAGE - mySusu->rayon)){
		goToEndLevel();

		}

}



