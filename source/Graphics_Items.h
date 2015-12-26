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

// ----Item_struc: structure d'un Star avec toutes ses propriétés
//----typedef: 'Item_struct' devient un type nommé 'Item'
//----pItem: pointeur sur un type Star

typedef struct Item_struct {

	// Statique :
	enum {
			MUSHROOM,
			STAR,
			CLOVER
		}itemType;

	double x,y ; // positions dans la matrice de pixel 256x(192*2)
	double angle;
	int size ; // Taille relative du susu : 5 -> taille normale, [0,10]-> ensemble des tailles

	// Dynamique:
	double v; // vitesse
	//double v_angle ; // vitesse de rotation angulaire

	// Gestion mémoire :
	int oamIndex; //numero of sprite;
	u16 *gfx_main, *gfx_sub; // memory adresses for copying data;

} Item, *pItem;


//---- Initialisation des propriétés de l'item,  placement tile et palette de l'item dans la mémoire (swicopy)
void initItem(pItem myItem);

//---- Changer la position du Susu
void setItemPosition(pItem myItem,double x, double y);

#endif /* SOURCE_GRAPHICS_ITEMS_H_ */
