/*
 * items->c
 *
 *  Created on: 13 déc-> 2015
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





// /!\ 5
void chooseItems (pItem myItem[], int myLevel){

	switch(myLevel){
	case 1:
		nbr_mushroom=5;
		nbr_clover=5;
		nbr_star=5;
		break;

	case 2:
			nbr_mushroom=5;
			nbr_clover=5;
			nbr_star=5;
			break;

	case 3:
			nbr_mushroom=5;
			nbr_clover=5;
			nbr_star=5;
			break;

	case 4:
			nbr_mushroom=5;
			nbr_clover=5;
			nbr_star=5;
			break;

	case 5:
			nbr_mushroom=5;
			nbr_clover=5;
			nbr_star=5;
			break;

	case 6:
			nbr_mushroom=5;
			nbr_clover=5;
			nbr_star=5;
			break;

	case 7:
			nbr_mushroom=5;
			nbr_clover=5;
			nbr_star=5;
			break;

	case 8:
			nbr_mushroom=5;
			nbr_clover=5;
			nbr_star=5;
			break;

	}

 nbr_items= nbr_mushroom +nbr_clover +nbr_star;

	int i;
	for (i=0 ; i<nbr_mushroom ; i++)
	{myItem[i]->itemType=MUSHROOM;}

	for (i=nbr_mushroom ; i< nbr_mushroom +nbr_clover ; i++)
	{myItem[i]->itemType=CLOVER;}

	for (i=nbr_mushroom +nbr_clover  ; i< nbr_mushroom +nbr_clover  +nbr_star; i++)
	{myItem[i]->itemType=STAR;}
	}


// /!\ 5

void initItems(pItem myItem[]){

	int i;
	for(i=0; i<nbr_items;i++)
	{
		myItem[i]->oamIndex = i+5; // Index OAM est incrémenté de 5 car on reserve la place pour les 5 susus de taille différentes

		myItem[i]->hidden =0;// ils sont tous affichés au début du jeu

		// sert à qlqch ???, on le fait dans displayItems
		if(myItem[i]->itemType==MUSHROOM) {myItem[i]->gfx_main=gfx_mushroom;}
		if(myItem[i]->itemType==STAR) {myItem[i]->gfx_main=gfx_star;}
		if(myItem[i]->itemType==CLOVER) {myItem[i]->gfx_main=gfx_clover;}
	}
}


// /!\ 5
void displayItems(pItem myItem[])
{

	// C'est la moité de la longueur du coté du sprite Item-> Dans la suite cela sert à décaller la position de l'Item
	// de facon à ce que la coordonnée de l'Item corresponde au centre de celui-ci->
	int halfwidth = 16;
	int i;
	for(i=0; i<nbr_items;i++)
	{

		if(myItem[i]->itemType==MUSHROOM)
		{
			oamSet( &oamMain, 	// oam handler
					myItem[i]->oamIndex,				// Number of sprite
					(int)myItem[i]->x- halfwidth , (int) myItem[i]->y- halfwidth ,			// Coordinates
					0,				// Priority
					nbr_pal_mushroom,				// Palette to use
					SpriteSize_32x32,			// Sprite size
					SpriteColorFormat_256Color,	// Color format
					gfx_mushroom,			// Loaded graphic to display
					-1,				// Affine rotation to use (-1 none)
					false,			// Double size if rotating
					myItem[i]->hidden,			// Hide this sprite
					false, false,	// Horizontal or vertical flip
					false			// Mosaic
			);
		}

		if(myItem[i]->itemType==STAR)
		{
			oamSet(&oamMain, 	// oam handler
					myItem[i]->oamIndex,				// Number of sprite
					(int)myItem[i]->x- halfwidth , (int)myItem[i]->y- halfwidth ,			// Coordinates
					0,				// Priority
					nbr_pal_star,				// Palette to use
					SpriteSize_32x32,			// Sprite size
					SpriteColorFormat_256Color,	// Color format
					gfx_star,			// Loaded graphic to display
					-1,				// Affine rotation to use (-1 none)
					false,			// Double size if rotating
					myItem[i]->hidden,			// Hide this sprite
					false, false,	// Horizontal or vertical flip
					false			// Mosaic
			);
		}

		if(myItem[i]->itemType==CLOVER)
		{
			oamSet(&oamMain, 	// oam handler
					myItem[i]->oamIndex,				// Number of sprite
					(int)myItem[i]->x- halfwidth , (int)myItem[i]->y- halfwidth ,			// Coordinates
					0,				// Priority
					nbr_pal_clover,				// Palette to use
					SpriteSize_32x32,			// Sprite size
					SpriteColorFormat_256Color,	// Color format
					gfx_clover,			// Loaded graphic to display
					-1,				// Affine rotation to use (-1 none)
					false,			// Double size if rotating
					myItem[i]->hidden,				// Hide this sprite
					false, false,	// Horizontal or vertical flip
					false			// Mosaic
			);
		}


	}

}


// /!\ 5
void setItemsPosition(pItem myItem[]){

	//1ere ligne
	myItem[0]->x=20;
	myItem[0]->y=160;

	myItem[1]->x=115;
	myItem[1]->y=160;

	myItem[2]->x=220;
	myItem[2]->y=160;

	//2e ligne

	myItem[3]->x=60;
	myItem[3]->y=80;

	myItem[4]->x=170;
	myItem[4]->y=80;

	myItem[5]->x=20;
	myItem[5]->y=80;

	myItem[6]->x=220;
	myItem[6]->y=80;

	myItem[10]->x=115;
	myItem[10]->y=80;


	//3e ligne

	myItem[11]->x=20;
	myItem[11]->y=20;

	myItem[12]->x=115;
	myItem[12]->y=20;

	myItem[13]->x=220;
	myItem[13]->y=20;

	//entre deux lignes

	myItem[7]->x=60;
	myItem[7]->y=120;

	myItem[8]->x=115;
	myItem[8]->y=120;

	myItem[14]->x=220;
	myItem[14]->y=120;

	myItem[9]->x=115;
	myItem[9]->y=50;

}








