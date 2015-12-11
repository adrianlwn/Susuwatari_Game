/*
 * Graphics_BG.c
 *
 *  Created on: 7 déc. 2015
 *      Author: adrian
 */
#include "Graphics_BG.h"

void configureGraphis_Main(){
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



void loadGraphics_Main(){
	BGCTRL[3] = BG_COLOR_256 | BG_32x32 | BG_MAP_BASE(0) | BG_TILE_BASE(1);
	dmaCopy(BG_mainTiles,BG_TILE_RAM(1),BG_mainTilesLen);
	dmaCopy(BG_mainMap,BG_MAP_RAM(0),BG_mainMapLen);
	dmaCopy(BG_mainPal,BG_PALETTE,BG_mainPalLen);

}
void loadGraphics_Sub(){
	BGCTRL_SUB[3] = BG_COLOR_256 | BG_32x32 | BG_MAP_BASE(0) | BG_TILE_BASE(1);
	dmaCopy(BG_subTiles ,BG_TILE_RAM_SUB(1) , BG_subTilesLen );
	dmaCopy(BG_subMap,BG_MAP_RAM_SUB(0),BG_subMapLen);
		dmaCopy(BG_subPal,BG_PALETTE_SUB,BG_subPalLen);


}
