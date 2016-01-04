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

// ----Susu_struc: structure du Susu avec toutes ses propriétés
//----typedef: 'Susu_struct' devient un type nommé 'Susu'
//----pSusu: pointeur sur un type Susu

typedef struct Susu_struct {
	// Statique :

	double x,y ; // positions dans la matrice de pixel 256x(192*2)
	double angle , orientation; // angle actuel de deplacement, et angle d'affichage du Susu.
	int size ; // Taille relative du susu : 5 tailles différentes   [0,4]-> ensemble des tailles
	int rayon ; // rayon du susu changeant selon le paramettre "size"
	int liste_diametre[5];// liste des rayons selon les différentes tailles.


	// Dynamique

	double v; // vitesse
	double a; // acceleration (ou deceleration)
	double v_angle ; // vitesse de rotation angulaire
	double a_angle; //accélération angulaire

	// Gestion mémoire :

	int oamIndex; //numero of sprite;
	u16 *gfx_main, *gfx_sub; // memory adresses for copying data;


} Susu, *pSusu;

typedef enum TouchState {
	NOT_TOUCHED,
	TOUCHING,
	TOUCHED,
	RELEASING,


} TouchState;

double deg2oamAngle(double angle);
double oamAngle2deg(double angle);


//---- Initialisation des propriétés du Susu,  placement tile et palette du Susu dans la mémoire (swicopy)
void initSusu(pSusu mySusu);

//---- Changer la position du Susu
void setSusuPosition(pSusu mySusu,double x, double y);

//---- Changer la direction du Susu instantanément
void setSusuAngle(pSusu mySusu, double angle);

//---- Changer la direction du Susu avec retard.
void setSusuOrientation(pSusu mySusu, double angle);


//---- Agrandir le  Susu
void setSusuBigger(pSusu mySusu);

//---- Rapetisser le Susu
void setSusuSmaller(pSusu mySusu);

//---- Rotation du Susu ON /OFF
void SusuRotate(pSusu mySusu,int ON);

//----  Rotation du Susu jusqu'à atteindre la valeur de new_angle (Rotation assez lente pour effet realiste)
void SusuRotateToNewAngle(pSusu mySusu);

void SusuMove(pSusu mySusu);
void SusuMoveTest2(pSusu mySusu);

//----Continué du Susu écran MAIN-SUB
void SusuUpdate(pSusu mySusu);

int InSusuSurface(pSusu mySusu, u16 px, u16 py);

#endif /* SOURCE_GRAPHICS_SUSU_H_ */
