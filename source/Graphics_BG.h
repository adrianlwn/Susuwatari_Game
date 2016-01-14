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

#include "BG_main_2.h"
#include  "BG_sub_2.h"

#include "BG_main_3.h"
#include  "BG_sub_3.h"

#include "BG_main_3.h"
#include  "BG_sub_3.h"

#include "BG_main_4.h"
#include  "BG_sub_4.h"

#include "BG_main_5.h"
#include  "BG_sub_5.h"

#include "BG_main_6.h"
#include  "BG_sub_6.h"

#include "BG_main_7.h"
#include  "BG_sub_7.h"

#include "BG_main_8.h"
#include  "BG_sub_8.h"


#include "MENU_main.h"
#include "MENU_BG_sub.h"

#include "MESSAGE_BG.h"
#include "START_BG.h"

// ECRIRE LES HEADERS ICI

void configureGraphics_Main();
void configureGraphics_Sub();

void loadGraphics_Menu();

void loadGraphics_Main(int myLevel);
void loadGraphics_Sub(int myLevel);

void loadGraphics_Message();
void loadGraphics_Start();





#endif /* GRAPHICS_BG_H_ */
