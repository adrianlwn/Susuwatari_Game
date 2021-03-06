/*
 * items.h
 *
 *  Created on: 13 déc. 2015
 *      Author: adrian
 */

#ifndef SOURCE_GRAPHICS_ITEMS_H_
#define SOURCE_GRAPHICS_ITEMS_H_

#include <nds.h>
#include"Graphics_Susu.h"
#include "Star.h"
#include "Mushroom.h"
#include  "Clover.h"


//---Structure OBJET---//

typedef struct Item_struct {

	// Statique :
	enum {
			MUSHROOM,
			STAR,
			CLOVER
		}itemType;

	double x,y ; // positions dans la matrice de pixel 256x(192*2)
	double angle;

	// Gestion mémoire :
	int oamIndex; //numero of sprite;
	u16 *gfx_main, *gfx_sub; // memory adresses for copying data;

	int hidden; // variable bool caché=1/affiché =0;

} Item, *pItem;
// ----Item_struc: structure d'un Star avec toutes ses propriétés
//----typedef: 'Item_struct' devient un type nommé 'Item'
//----pItem: pointeur sur un type Star


int nbr_mushroom;
int nbr_clover;
int nbr_star;
int nbr_items;


//---- Initialisation des propriétés de l'item,  placement tile et palette de l'item dans la mémoire (swicopy)
void initItems(pItem myItem[]);

//---- Changer la position des Items
void setItemsPosition(pItem myItem[],int myLevel);


//---afficher toute la liste des Items
void displayItems(pItem myItem[]);

//---Choisir le nombre de trèfle/champignon/étoile en fonction du niveau
void chooseItems (pItem myItem[], int myLevel);


#endif /* SOURCE_GRAPHICS_ITEMS_H_ */
