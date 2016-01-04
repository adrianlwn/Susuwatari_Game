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

#include "Susu24px.h"
#include "Susu34px.h"
#include "Susu44px.h"
#include "Susu54px.h"
#include "Susu64px.h"

#include "Graphics_Items.h"

u16 *gfx_susu_main[5],*gfx_susu_sub[5]; //
u16 * gfx_star;
u16 * gfx_clover;
u16 * gfx_mushroom;

u16 * gfx_star_sub;
u16 * gfx_clover_sub;
u16 * gfx_mushroom_sub;

u16* gfx_cadre_menu;
void initSprite();
void configureSprite();
void configureSpriteMenu();








#endif /* GRAPHICS_SPRITE_H_ */
