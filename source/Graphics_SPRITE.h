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

void clearSprite();
void initSprite();
void loadSprite(int myLevel);
void loadSpriteMenu();








#endif /* GRAPHICS_SPRITE_H_ */
