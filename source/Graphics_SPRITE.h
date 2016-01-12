/*
 * Graphics_SPRITE.h
 *
 *  Created on: 8 déc. 2015
 *      Author: adrian
 */

#ifndef GRAPHICS_SPRITE_H_
#define GRAPHICS_SPRITE_H_
#include <nds.h>
#include "Star.h"
#include "Mushroom.h"
#include  "Clover.h"
// For Level 1 :
#include "Susu24px_1.h"
#include "Susu34px_1.h"
#include "Susu44px_1.h"
#include "Susu54px_1.h"
#include "Susu64px_1.h"

// For Level 2 :
#include "Susu24px_2.h"
#include "Susu34px_2.h"
#include "Susu44px_2.h"
#include "Susu54px_2.h"
#include "Susu64px_2.h"

// For Level 3 :
#include "Susu24px_3.h"
#include "Susu34px_3.h"
#include "Susu44px_3.h"
#include "Susu54px_3.h"
#include "Susu64px_3.h"

// For Level 4 :
#include "Susu24px_4.h"
#include "Susu34px_4.h"
#include "Susu44px_4.h"
#include "Susu54px_4.h"
#include "Susu64px_4.h"

// For Level 5 :
#include "Susu24px_5.h"
#include "Susu34px_5.h"
#include "Susu44px_5.h"
#include "Susu54px_5.h"
#include "Susu64px_5.h"

// For Level 6 :
#include "Susu24px_6.h"
#include "Susu34px_6.h"
#include "Susu44px_6.h"
#include "Susu54px_6.h"
#include "Susu64px_6.h"

// For Level 7 :
#include "Susu24px_7.h"
#include "Susu34px_7.h"
#include "Susu44px_7.h"
#include "Susu54px_7.h"
#include "Susu64px_7.h"

// For Level 8 :
#include "Susu24px_8.h"
#include "Susu34px_8.h"
#include "Susu44px_8.h"
#include "Susu54px_8.h"
#include "Susu64px_8.h"


#include "MENU_CADRE.h"
#include "MENU_lock.h"
#include "MENU_heart.h"
#include "MENU_heart_creux.h"

#include "Graphics_Items.h"

u16 *gfx_susu_main[5],*gfx_susu_sub[5]; //
u16 * gfx_star;
u16 * gfx_clover;
u16 * gfx_mushroom;

u16 * gfx_star_sub;
u16 * gfx_clover_sub;
u16 * gfx_mushroom_sub;

u16* gfx_cadre_menu;
u16* gfx_heart_menu;
u16* gfx_heart_creux_menu;
u16* gfx_lock_menu;

int nbr_pal_mushroom;
int nbr_pal_clover;
int nbr_pal_star;s

void clearSprite();
void initSprite();
void loadSprite(int myLevel);
void loadSpriteMenu();








#endif /* GRAPHICS_SPRITE_H_ */
