/*
 * Susu.h
 *
 *  Created on: 13 déc. 2015
 *      Author: adrian
 */

#ifndef SOURCE_GRAPHICS_SUSU_H_
#define SOURCE_GRAPHICS_SUSU_H_

#include <math.h>
#include <nds.h>
#include "Susu.h"


typedef struct mySusu {
	// Statique :

	double x,y ; // positions dans la matrice de pixel 256x(192*2)
	double angle;
	int size ; // Taille relative du susu : 5 -> taille normale, [0,10]-> ensemble des tailles

	// Dynamique

	double v; // vitesse
	double v_angle ; // vitesse de rotation angulaire

	// Gestion mémoire :

	int oamIndex; //numero of sprite;
	u16 *gfx_main, *gfx_sub; // memory adresses for copying data;

} Susu, *pSusu;

void initSusu(pSusu mySusu);
void setSusuPosition(pSusu mySusu,double x, double y);
void setSusuAngle(pSusu mySusu, double angle);
void setSusuBigger(pSusu mySusu);
void setSusuSmaller(pSusu mySusu);

void SusuRotate(pSusu mySusu,int ON);


void SusuMoveTest(pSusu mySusu);
void SusuMoveTest2(pSusu mySusu);


void SusuUpdate(pSusu mySusu);
#endif /* SOURCE_GRAPHICS_SUSU_H_ */
