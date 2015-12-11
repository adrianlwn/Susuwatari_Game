/*
 * init.c
 *
 *  Created on: 8 déc. 2015
 *      Author: adrian
 */
#include "init.h"

void init_NDS(){

	// Initialization of graphics main and sub :
	configureGraphis_Main();
	configureGraphics_Sub();

	loadGraphics_Main();
	loadGraphics_Sub();

	configureSprite();

}
