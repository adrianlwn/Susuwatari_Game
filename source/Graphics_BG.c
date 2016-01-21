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
		BG_mainTiles = BG_main_1Tiles;
		BG_mainTilesLen = BG_main_1TilesLen;
		BG_mainMap = BG_main_1Map;
		BG_mainMapLen = BG_main_1MapLen;
		BG_mainPal = BG_main_1Pal;
		BG_mainPalLen = BG_main_1PalLen;
		break;
	case 2 : //LEVEL 2
		BG_mainTiles = BG_main_2Tiles;
				BG_mainTilesLen = BG_main_2TilesLen;
				BG_mainMap = BG_main_2Map;
				BG_mainMapLen = BG_main_2MapLen;
				BG_mainPal = BG_main_2Pal;
				BG_mainPalLen = BG_main_2PalLen;
		break;

	case 3:
		BG_mainTiles = BG_main_3Tiles;
				BG_mainTilesLen = BG_main_3TilesLen;
				BG_mainMap = BG_main_3Map;
				BG_mainMapLen = BG_main_3MapLen;
				BG_mainPal = BG_main_3Pal;
				BG_mainPalLen = BG_main_3PalLen;
		break;

	case 4 :
		BG_mainTiles = BG_main_4Tiles;
				BG_mainTilesLen = BG_main_4TilesLen;
				BG_mainMap = BG_main_4Map;
				BG_mainMapLen = BG_main_4MapLen;
				BG_mainPal = BG_main_4Pal;
				BG_mainPalLen = BG_main_4PalLen;
		break;

	case 5 :
		BG_mainTiles = BG_main_5Tiles;
				BG_mainTilesLen = BG_main_5TilesLen;
				BG_mainMap = BG_main_5Map;
				BG_mainMapLen = BG_main_5MapLen;
				BG_mainPal = BG_main_5Pal;
				BG_mainPalLen = BG_main_5PalLen;
		break;

	case 6 :
		BG_mainTiles = BG_main_6Tiles;
				BG_mainTilesLen = BG_main_6TilesLen;
				BG_mainMap = BG_main_6Map;
				BG_mainMapLen = BG_main_6MapLen;
				BG_mainPal = BG_main_6Pal;
				BG_mainPalLen = BG_main_6PalLen;
		break;

	case 7 :
		BG_mainTiles = BG_main_7Tiles;
				BG_mainTilesLen = BG_main_7TilesLen;
				BG_mainMap = BG_main_7Map;
				BG_mainMapLen = BG_main_7MapLen;
				BG_mainPal = BG_main_7Pal;
				BG_mainPalLen = BG_main_7PalLen;
		break;

	case 8 :
		BG_mainTiles = BG_main_8Tiles;
				BG_mainTilesLen = BG_main_8TilesLen;
				BG_mainMap = BG_main_8Map;
				BG_mainMapLen = BG_main_8MapLen;
				BG_mainPal = BG_main_8Pal;
				BG_mainPalLen = BG_main_8PalLen;
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
		BG_subTiles = BG_sub_1Tiles;
		BG_subTilesLen = BG_sub_1TilesLen;
		BG_subMap = BG_sub_1Map;
		BG_subMapLen = BG_sub_1MapLen;
		BG_subPal = BG_sub_1Pal;
		BG_subPalLen = BG_sub_1PalLen;
		break;

	case 2 : //LEVEL 2
		BG_subTiles = BG_sub_2Tiles;
				BG_subTilesLen = BG_sub_2TilesLen;
				BG_subMap = BG_sub_2Map;
				BG_subMapLen = BG_sub_2MapLen;
				BG_subPal = BG_sub_2Pal;
				BG_subPalLen = BG_sub_2PalLen;
		break;

	case 3:
		BG_subTiles = BG_sub_3Tiles;
				BG_subTilesLen = BG_sub_3TilesLen;
				BG_subMap = BG_sub_3Map;
				BG_subMapLen = BG_sub_3MapLen;
				BG_subPal = BG_sub_3Pal;
				BG_subPalLen = BG_sub_3PalLen;
		break;

	case 4 :
		BG_subTiles = BG_sub_4Tiles;
				BG_subTilesLen = BG_sub_4TilesLen;
				BG_subMap = BG_sub_4Map;
				BG_subMapLen = BG_sub_4MapLen;
				BG_subPal = BG_sub_4Pal;
				BG_subPalLen = BG_sub_4PalLen;
		break;

	case 5 :
		BG_subTiles = BG_sub_5Tiles;
				BG_subTilesLen = BG_sub_5TilesLen;
				BG_subMap = BG_sub_5Map;
				BG_subMapLen = BG_sub_5MapLen;
				BG_subPal = BG_sub_5Pal;
				BG_subPalLen = BG_sub_5PalLen;
		break;

	case 6 :
		BG_subTiles = BG_sub_6Tiles;
				BG_subTilesLen = BG_sub_6TilesLen;
				BG_subMap = BG_sub_6Map;
				BG_subMapLen = BG_sub_6MapLen;
				BG_subPal = BG_sub_6Pal;
				BG_subPalLen = BG_sub_6PalLen;
		break;

	case 7 :
		BG_subTiles = BG_sub_7Tiles;
				BG_subTilesLen = BG_sub_7TilesLen;
				BG_subMap = BG_sub_7Map;
				BG_subMapLen = BG_sub_7MapLen;
				BG_subPal = BG_sub_7Pal;
				BG_subPalLen = BG_sub_7PalLen;
		break;

	case 8 :
		BG_subTiles = BG_sub_8Tiles;
				BG_subTilesLen = BG_sub_8TilesLen;
				BG_subMap = BG_sub_8Map;
				BG_subMapLen = BG_sub_8MapLen;
				BG_subPal = BG_sub_8Pal;
				BG_subPalLen = BG_sub_8PalLen;
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

void loadGraphics_Start(){
	// Chargement de l'ecran Main

	BGCTRL[3] = BG_COLOR_256 | BG_32x32 | BG_MAP_BASE(0) | BG_TILE_BASE(1);
	dmaCopy(MENU_mainTiles,BG_TILE_RAM(1),MENU_mainTilesLen);
	dmaCopy(MENU_mainMap,BG_MAP_RAM(0),MENU_mainMapLen);
	dmaCopy(MENU_mainPal,BG_PALETTE,MENU_mainPalLen);
	// Chargement de l'ecran Sub

	BGCTRL_SUB[3] = BG_COLOR_256 | BG_32x32 | BG_MAP_BASE(0) | BG_TILE_BASE(1);
	dmaCopy(START_BGTiles ,BG_TILE_RAM_SUB(1) , START_BGTilesLen );
	dmaCopy(START_BGMap,BG_MAP_RAM_SUB(0),START_BGMapLen);
	dmaCopy(START_BGPal,BG_PALETTE_SUB,START_BGPalLen);

}

void loadGraphics_Message(){
	// Inutile de recharger le Main screen qui restera toujours le meme
	/*
	BGCTRL[3] = BG_COLOR_256 | BG_32x32 | BG_MAP_BASE(0) | BG_TILE_BASE(1);
	dmaCopy(MENU_mainTiles,BG_TILE_RAM(1),MENU_mainTilesLen);
	dmaCopy(MENU_mainMap,BG_MAP_RAM(0),MENU_mainMapLen);
	dmaCopy(MENU_mainPal,BG_PALETTE,MENU_mainPalLen);
	 */

	BGCTRL_SUB[3] = BG_COLOR_256 | BG_32x32 | BG_MAP_BASE(0) | BG_TILE_BASE(1);
	dmaCopy(MESSAGE_BGTiles ,BG_TILE_RAM_SUB(1) , MESSAGE_BGTilesLen );
	dmaCopy(MESSAGE_BGMap,BG_MAP_RAM_SUB(0),MESSAGE_BGMapLen);
	dmaCopy(MESSAGE_BGPal,BG_PALETTE_SUB,MESSAGE_BGPalLen);

}


