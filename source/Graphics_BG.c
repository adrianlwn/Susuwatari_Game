/*
 * Graphics_BG.c
 *
 *  Created on: 7 déc. 2015
 *      Author: adrian
 */
#include "Graphics_BG.h"



void configureGraphics_Main(){
	//Enable a proper RAM memory bank for the main engine
	VRAM_A_CR = VRAM_ENABLE //Enable
			| VRAM_A_MAIN_BG; //Bank for the main engine

	//Configure the main engine in mode 0 (2D) and activate Backgrounds 3 (Tiled Mode - Fond d'ecran)
	REG_DISPCNT = MODE_0_2D  | DISPLAY_BG3_ACTIVE;


}

void configureGraphics_Sub(){

	//Enable a proper RAM memory bank for sub engine
	VRAM_C_CR = VRAM_ENABLE
			| VRAM_C_SUB_BG;
	//Configure the sub engine in mode 0 (2D) and activate Background 3  (Tiled Mode - Fond d'ecran)
	REG_DISPCNT_SUB = MODE_0_2D | DISPLAY_BG3_ACTIVE;

}



void loadGraphics_Main(int myLevel){
	const unsigned int *BG_mainTiles;
	int BG_mainTilesLen;
	const unsigned short *BG_mainMap;
	int BG_mainMapLen;
	const unsigned short *BG_mainPal;
	int BG_mainPalLen;
	// CHOOSE SPECIFIC BG
	switch (myLevel) {
	case 1 : // LEVEL 1
		BG_mainTiles = &BG_main_1Tiles;
		BG_mainTilesLen = BG_main_1TilesLen;
		BG_mainMap = &BG_main_1Map;
		BG_mainMapLen = BG_main_1MapLen;
		BG_mainPal = &BG_main_1Pal;
		BG_mainPalLen = BG_main_1PalLen;
		break;
	case 2 : //LEVEL 2
		break;

	case 3:
		break;

	case 4 :
		break;

	case 5 :
		break;

	case 6 :
		break;

	case 7 :
		break;

	case 8 :
		break;
	}
	// LOADING SPECIFIED BG :
	BGCTRL[3] = BG_COLOR_256 | BG_32x32 | BG_MAP_BASE(0) | BG_TILE_BASE(1);
	dmaCopy(BG_mainTiles,BG_TILE_RAM(1),BG_mainTilesLen);
	dmaCopy(BG_mainMap,BG_MAP_RAM(0),BG_mainMapLen);
	dmaCopy(BG_mainPal,BG_PALETTE,BG_mainPalLen);

}


void loadGraphics_Sub(int myLevel){

	const unsigned int *BG_subTiles;
	int BG_subTilesLen;
	const unsigned short *BG_subMap;
	int BG_subMapLen;
	const unsigned short *BG_subPal;
	int BG_subPalLen;
	// CHOOSE SPECIFIC BG
	switch (myLevel) {
	case 1 : // LEVEL 1
		BG_subTiles = &BG_sub_1Tiles;
		BG_subTilesLen = BG_sub_1TilesLen;
		BG_subMap = &BG_sub_1Map;
		BG_subMapLen = BG_sub_1MapLen;
		BG_subPal = &BG_sub_1Pal;
		BG_subPalLen = BG_sub_1PalLen;
		break;
	case 2 : //LEVEL 2
		break;

	case 3:
		break;

	case 4 :
		break;

	case 5 :
		break;

	case 6 :
		break;

	case 7 :
		break;

	case 8 :
		break;
	}

	BGCTRL_SUB[3] = BG_COLOR_256 | BG_32x32 | BG_MAP_BASE(0) | BG_TILE_BASE(1);
	dmaCopy(BG_subTiles ,BG_TILE_RAM_SUB(1) , BG_subTilesLen );
	dmaCopy(BG_subMap,BG_MAP_RAM_SUB(0),BG_subMapLen);
	dmaCopy(BG_subPal,BG_PALETTE_SUB,BG_subPalLen);


}

void loadGraphics_Menu(){

	BGCTRL[3] = BG_COLOR_256 | BG_32x32 | BG_MAP_BASE(0) | BG_TILE_BASE(1);
	dmaCopy(MENU_mainTiles,BG_TILE_RAM(1),MENU_mainTilesLen);
	dmaCopy(MENU_mainMap,BG_MAP_RAM(0),MENU_mainMapLen);
	dmaCopy(MENU_mainPal,BG_PALETTE,MENU_mainPalLen);

	BGCTRL_SUB[3] = BG_COLOR_256 | BG_32x32 | BG_MAP_BASE(0) | BG_TILE_BASE(1);
	dmaCopy(MENU_BG_subTiles ,BG_TILE_RAM_SUB(1) , MENU_BG_subTilesLen );
	dmaCopy(MENU_BG_subMap,BG_MAP_RAM_SUB(0),MENU_BG_subMapLen);
	dmaCopy(MENU_BG_subPal,BG_PALETTE_SUB,MENU_BG_subPalLen);

}

