/*
 * Graphics_BG.h
 *
 *  Created on: 7 déc. 2015
 *      Author: adrian
 */

#ifndef GRAPHICS_BG_H_
#define GRAPHICS_BG_H_
#include <nds.h>

#include "BG_main_1.h"
#include  "BG_sub_1.h"
#include "MENU_main.h"
#include "MENU_BG_sub.h"

// ECRIRE LES HEADERS ICI

void configureGraphics_Main();
void configureGraphics_Sub();

void loadGraphics_Menu();

void loadGraphics_Main(int myLevel);
void loadGraphics_Sub(int myLevel);






#endif /* GRAPHICS_BG_H_ */
