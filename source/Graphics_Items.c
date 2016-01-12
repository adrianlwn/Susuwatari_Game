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
		nbr_mushroom=6;
		nbr_clover=0;
		nbr_star=5;
		break;

	case 2:
			nbr_mushroom=6;
			nbr_clover=1;
			nbr_star=5;
			break;

	case 3:
			nbr_mushroom=6;
			nbr_clover=2;
			nbr_star=5;
			break;

	case 4:
			nbr_mushroom=5;
			nbr_clover=2;
			nbr_star=5;
			break;

	case 5:
			nbr_mushroom=4;
			nbr_clover=4;
			nbr_star=5;
			break;

	case 6:
			nbr_mushroom=10;
			nbr_clover=4;
			nbr_star=5;
			break;

	case 7:
			nbr_mushroom=15;
			nbr_clover=10;
			nbr_star=5;
			break;

	case 8:
			nbr_mushroom=20;
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
void setItemsPosition(pItem myItem[], int myLevel){

	switch(myLevel)
	{

	case 1:


		//Mushrooms
		myItem[0]->x=15;
		myItem[0]->y=20;

		myItem[1]->x=15;
		myItem[1]->y=50;

		myItem[2]->x=15;
		myItem[2]->y=80;

		myItem[3]->x=240;
		myItem[3]->y=20;

		myItem[4]->x=240;
		myItem[4]->y=50;

		myItem[5]->x=240;
		myItem[5]->y=80;


		//Star

		myItem[6]->x=125;
		myItem[6]->y=20;

		myItem[7]->x=125;
		myItem[7]->y=50;

	    myItem[8]->x=125;
		myItem[8]->y=80;

	    myItem[9]->x=90;
		myItem[9]->y=50;

		myItem[10]->x=160;
		myItem[10]->y=50;

	break;


	case 2:


		//Mushrooms
		myItem[0]->x=15;
		myItem[0]->y=20;

		myItem[1]->x=15;
		myItem[1]->y=50;

		myItem[2]->x=15;
		myItem[2]->y=80;

		myItem[3]->x=240;
		myItem[3]->y=20;

		myItem[4]->x=240;
		myItem[4]->y=50;

		myItem[5]->x=240;
		myItem[5]->y=80;


		//Trefle

		myItem[6]->x=125;
		myItem[6]->y=180;

		//Star
		myItem[7]->x=125;
		myItem[7]->y=20;

	    myItem[8]->x=90;
		myItem[8]->y=50;

	    myItem[9]->x=90;
		myItem[9]->y=80;

		myItem[10]->x=160;
		myItem[10]->y=50;

		myItem[11]->x=160;
		myItem[11]->y=80;

	break;

	case 3:


		//Mushrooms
		myItem[0]->x=15;
		myItem[0]->y=20;

		myItem[1]->x=15;
		myItem[1]->y=50;

		myItem[2]->x=40;
		myItem[2]->y=20;

		myItem[3]->x=240;
		myItem[3]->y=20;

		myItem[4]->x=240;
		myItem[4]->y=50;

		myItem[5]->x=210;
		myItem[5]->y=20;


		//Trefle

		myItem[6]->x=15;
		myItem[6]->y=180;

		myItem[7]->x=240;
		myItem[7]->y=180;

		//Star

	    myItem[8]->x=125;
		myItem[8]->y=20;

	    myItem[9]->x=90;
		myItem[9]->y=20;

		myItem[10]->x=160;
		myItem[10]->y=20;

		myItem[11]->x=100;
		myItem[11]->y=50;

		myItem[12]->x=140;
		myItem[12]->y=50;

	break;


	case 4:


		//Mushrooms
		myItem[0]->x=15;
		myItem[0]->y=20;

		myItem[1]->x=15;
		myItem[1]->y=180;

		myItem[2]->x=240;
		myItem[2]->y=20;

		myItem[3]->x=240;
		myItem[3]->y=180;

		myItem[4]->x=125;
		myItem[4]->y=100;

		//Trefle
		myItem[5]->x=15;
		myItem[5]->y=100;

		myItem[6]->x=240;
		myItem[6]->y=100;

		//Star
		myItem[7]->x=100;
		myItem[7]->y=80;


	    myItem[8]->x=150;
		myItem[8]->y=80;

	    myItem[9]->x=100;
		myItem[9]->y=120;

		myItem[10]->x=150;
		myItem[10]->y=120;

		myItem[11]->x=125;
		myItem[11]->y=180;

	break;

	case 5:


		//Mushrooms
		myItem[0]->x=15;
		myItem[0]->y=125;

		myItem[1]->x=240;
		myItem[1]->y=125;

		myItem[2]->x=105;
		myItem[2]->y=180;

		myItem[3]->x=135;
		myItem[3]->y=180;

		//Trefle
		myItem[4]->x=15;
		myItem[4]->y=20;

		myItem[5]->x=240;
		myItem[5]->y=20;

		myItem[6]->x=15;
		myItem[6]->y=180;


		myItem[7]->x=240;
		myItem[7]->y=180;

		//Star

	    myItem[8]->x=125;
		myItem[8]->y=100;

	    myItem[9]->x=60;
		myItem[9]->y=20;

		myItem[10]->x=190;
		myItem[10]->y=20;

		myItem[11]->x=60;
		myItem[11]->y=180;

		myItem[12]->x=190;
		myItem[12]->y=180;

	break;

	case 6:


		//Mushrooms
		myItem[0]->x=15;
		myItem[0]->y=20;

		myItem[1]->x=15;
		myItem[1]->y=50;

		myItem[2]->x=15;
		myItem[2]->y=80;

		myItem[3]->x=15;
		myItem[3]->y=110;

		myItem[4]->x=15;
		myItem[4]->y=140;

		myItem[5]->x=240;
		myItem[5]->y=20;

		myItem[6]->x=240;
		myItem[6]->y=50;

		myItem[7]->x=240;
		myItem[7]->y=80;

	    myItem[8]->x=240;
		myItem[8]->y=110;

	    myItem[9]->x=240;
		myItem[9]->y=140;

		//Trefle

		myItem[10]->x=65;
		myItem[10]->y=20;

		myItem[11]->x=105;
		myItem[11]->y=20;

		myItem[12]->x=145;
		myItem[12]->y=20;

		myItem[13]->x=185;
		myItem[13]->y=20;

		//Star
		myItem[14]->x=65;
		myItem[14]->y=180;

		myItem[15]->x=95;
		myItem[15]->y=160;

	    myItem[16]->x=125;
	    myItem[16]->y=140;

	    myItem[17]->x=155;
	    myItem[17]->y=160;

	    myItem[18]->x=185;
	 	myItem[18]->y=180;

	break;

	case 7:

		//Mushrooms
		myItem[0]->x=15;
		myItem[0]->y=20;

		myItem[1]->x=15;
		myItem[1]->y=50;

		myItem[2]->x=15;
		myItem[2]->y=80;

		myItem[3]->x=15;
		myItem[3]->y=110;

		myItem[4]->x=15;
		myItem[4]->y=140;

		myItem[5]->x=240;
		myItem[5]->y=20;

		myItem[6]->x=240;
		myItem[6]->y=50;

		myItem[7]->x=240;
		myItem[7]->y=80;

	    myItem[8]->x=240;
		myItem[8]->y=110;

	    myItem[9]->x=240;
		myItem[9]->y=140;

		myItem[10]->x=125;
		myItem[10]->y=20;

		myItem[11]->x=125;
		myItem[11]->y=50;

		myItem[12]->x=125;
		myItem[12]->y=80;

		myItem[13]->x=125;
		myItem[13]->y=110;

		myItem[14]->x=125;
		myItem[14]->y=140;

		//trefle

		myItem[15]->x=70;
		myItem[15]->y=20;

	    myItem[16]->x=70;
	    myItem[16]->y=50;

	    myItem[17]->x=70;
	    myItem[17]->y= 80;

	    myItem[18]->x=70;
	 	myItem[18]->y=110;

	 	 myItem[19]->x=70;
	     myItem[19]->y=140;

			myItem[20]->x=180;
			myItem[20]->y=20;

		    myItem[21]->x=180;
		    myItem[21]->y=50;

		    myItem[22]->x=180;
		    myItem[22]->y= 80;

		    myItem[23]->x=180;
		 	myItem[23]->y=110;

		 	 myItem[24]->x=180;
		     myItem[24]->y=140;


	//Star
				myItem[25]->x=40;
				myItem[25]->y=65;

			    myItem[26]->x=100;
			    myItem[26]->y= 95;

			    myItem[27]->x=150;
			    myItem[27]->y= 95;

			    myItem[28]->x=210;
			 	myItem[28]->y=65;

			 	 myItem[29]->x=125;
			     myItem[29]->y=170;

	break;

	case 8:

		//premier cercle

		//Mushrooms
		myItem[0]->x=16; //-24
		myItem[0]->y=72;//-8

		myItem[1]->x=62; // +22
		myItem[1]->y=72;//-8

		myItem[2]->x=22;//-18
		myItem[2]->y=98;//+18

		myItem[3]->x=58;// 18
		myItem[3]->y=98;//18

		//trefle
		myItem[20]->x=39;//-1
		myItem[20]->y=55;//-25

		//star
		myItem[25]->x=40;
		myItem[25]->y=80;

		//cinquieme cercle

		   myItem[16]->x=156;
			 myItem[16]->y=152;

			    myItem[17]->x=200;//!!
			    myItem[17]->y= 152;

			    myItem[18]->x=162;
			 	myItem[18]->y=178;

			 	 myItem[19]->x=179;
			     myItem[19]->y=135;

			     //trefle
				 	 myItem[24]->x=198;
				     myItem[24]->y=178;
			//Star
					 	 myItem[29]->x=180;
					     myItem[29]->y=160;
		//quatrieme cercle


		//star
		 myItem[28]->x=90;
		myItem[28]->y=160;

		//mushroom

		        myItem[12]->x=66;
				myItem[12]->y=152;

				myItem[13]->x=112;
				myItem[13]->y=152;

				myItem[14]->x=89;
				myItem[14]->y=135;

				myItem[15]->x=108;
				myItem[15]->y=178;
//trefle
				  myItem[23]->x=72;
				myItem[23]->y=178;



		// troisieme cercle

		//star
		   myItem[27]->x=125;
		   myItem[27]->y= 40;

		  //mushroom

		    myItem[8]->x=101;
			myItem[8]->y=32;

		    myItem[9]->x=124;
			myItem[9]->y=15;

			myItem[10]->x=107;
			myItem[10]->y=58;

			myItem[11]->x=143;
			myItem[11]->y=58;

			//trefle

			 myItem[22]->x=147;
			 myItem[22]->y= 32;


		//deuxieme cercle

		//star
		  myItem[26]->x=210;
		  myItem[26]->y= 80;

		  //mushroom

			myItem[4]->x=209;
			myItem[4]->y=55;

			myItem[5]->x=232;
			myItem[5]->y=74;

			myItem[6]->x=192;
			myItem[6]->y=98;

			myItem[7]->x=228;
			myItem[7]->y=98;

			//trefle
			myItem[21]->x=186;
			myItem[21]->y=72;


	break;




	default:

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
	break;

}
}








