/*
 * init.c
 *
 *  Created on: 8 déc. 2015
 *      Author: adrian
 */
#include "init.h"

void init_NDS(){

	// Initialization of graphics main and sub :
	configureGraphics_Main();
	configureGraphics_Sub();


	configureSprite();

}
