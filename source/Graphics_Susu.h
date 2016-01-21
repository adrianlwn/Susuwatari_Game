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




//---Structure du SUSUWATARI (sprite)---//

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

<<<<<<< HEAD
// ----Susu_struc: structure du Susu avec toutes ses propriétés
//----typedef: 'Susu_struct' devient un type nommé 'Susu'
//----pSusu: pointeur sur un type Susu




//---Etat du SUSU dans l'écran du sub---//

=======
pSusu mySusu;
>>>>>>> master
typedef enum TouchState {
	NOT_TOUCHED,
	TOUCHING,
	TOUCHED,
	RELEASING,


} TouchState;

//Transformer l'oamAngle  en degré et vice-versa
double deg2oamAngle(double angle);
double oamAngle2deg(double angle);


//---- Initialisation des propriétés du Susu,  placement tile et palette du Susu dans la mémoire (swicopy)
void initSusu();

//---- Changer la position du Susu
void setSusuPosition(int x, int y);

//---- Changer la direction du Susu instantanément
void setSusuAngle( double angle);

<<<<<<< HEAD
=======
//---- Changer la direction du Susu avec retard.
void setSusuOrientation( double angle);

>>>>>>> master

//---- Agrandir le  Susu
void setSusuBigger();

//---- Rapetisser le Susu
void setSusuSmaller();

//---- Rotation du Susu ON /OFF
void SusuRotate();

//----  Rotation du Susu jusqu'à atteindre la valeur de new_angle (Rotation assez lente pour effet realiste)
void SusuRotateToNewAngle();

<<<<<<< HEAD

//--- Implémente la manière de mettre le susu en mouvement avec le stylet;
void SusuMove(pSusu mySusu);


//----Continuité du Susu écran MAIN-SUB
void SusuUpdate(pSusu mySusu);

//---Vérifie si les coordonnées  (px,py) sont aux alentours du centre du susu dans un rayon a=(taille du sprite)/2;
int InSusuSurface(pSusu mySusu, u16 px, u16 py);
=======
void SusuMove();
void SusuMoveTest2();

//----Continué du Susu écran MAIN-SUB
void SusuUpdate();

int InSusuSurface( u16 px, u16 py);
>>>>>>> master

#endif /* SOURCE_GRAPHICS_SUSU_H_ */
