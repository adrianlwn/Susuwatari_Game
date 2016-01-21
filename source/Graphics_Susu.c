/*
 * Susu.c
 *
 *  Created on: 13 déc. 2015
 *      Author: adrian
 */

#include "Graphics_Susu.h"
#include "Graphics_Items.h"
#include "Graphics_SPRITE.h"

#define HAUTEUR 192
#define LARGEUR 256
#define DECALAGE 96
#define H_SCORE 12

#define halfwidth 32


void initSusu(pSusu mySusu){

	// Allocate la memoire oam pour la taille du sprite.
	mySusu->size=4;
	mySusu->oamIndex = mySusu->size;

	mySusu->gfx_main = gfx_susu_main[mySusu->size];
	mySusu->gfx_sub = gfx_susu_sub[mySusu->size];
	// Liste des différents diametres.
	mySusu->liste_diametre[0] = 24; // pixels de large
	mySusu->liste_diametre[1] = 34; // pixels de large
	mySusu->liste_diametre[2] = 44; // pixels de large
	mySusu->liste_diametre[3] = 54; // pixels de large
	mySusu->liste_diametre[4] = 64; // pixels de large

	mySusu->rayon = mySusu->liste_diametre[mySusu->size] /2 ;


	mySusu->angle= deg2oamAngle(90);
	mySusu->orientation = mySusu->angle;


	mySusu->v_angle=0;
	mySusu->a_angle=1;

	mySusu->x = LARGEUR/2;
	mySusu->y = DECALAGE + HAUTEUR+HAUTEUR/2;
	mySusu->v= 0;
	mySusu->a = -0.002;


}


// Initialisation de l'etat du touch screen.
TouchState myTouchState = NOT_TOUCHED;


void SusuMove(pSusu mySusu){
	/* Tant que le stylet touche le susu ( à l'intérieur du cercle de rayon ___
	 * et de centre les coordonees du susu ) le susu tourne sur lui meme.
	 * sa vitesse augmente.
	 * quand le stylet ne touche plus le susu, la vitesse n'augmente plus , et le susu part avec
	 *  cette vitesse  dans la direction dans laquelle il regarde quand  on le lâche */

	int touch_inside =0 ;
	int held =0, up=0 , down =0;

	// On scanne la position du Susu et on enregistre l'etat du touch screen
	scanKeys();
	touchPosition pos;
	touchRead(&pos);
	held=keysHeld();
	down = keysDown();
	up=keysUp();

	// On verifie si la position du touch screen est dans la surface du Susu
	touch_inside=InSusuSurface( mySusu, pos.px,  pos.py  + DECALAGE + HAUTEUR);

	//Petite machine d'etat fini régissant le comportement en fonction de la position et de l'etat actuel.
	switch (myTouchState) {

	case NOT_TOUCHED: // Cas ou le Susu n'est pas touché
		// Deceleration
		if (mySusu->v >= - mySusu->a){
			mySusu->v = mySusu->v + mySusu->a;
		}
		else {
			mySusu->v  =0 ;
		}

		// Changment d'etat si touché
		if(touch_inside == 1 && (down & KEY_TOUCH)){
			myTouchState = TOUCHING;
		}

		break;
	case TOUCHING : // Action a entreprendre au moment ou le Susu est touché.
		mySusu->v=0;
		mySusu->v_angle = 50;
		myTouchState = TOUCHED;
		break;

	case TOUCHED : // Cas ou le Susu est touché.
		//touch_inside == 0 && (held & KEY_TOUCH) ) ||
		if ((up & KEY_TOUCH) ||  (touch_inside == 0 && (held & KEY_TOUCH)) ){
			myTouchState = RELEASING;
		}
		else {

			// ------- DEPLACEMENT SELON LE STYLET !!!! ------------OFF---------------
			// permet de déplacement en fonction de la position du stylet
			//setSusuPosition( mySusu, pos.px,  pos.py  + DECALAGE + HAUTEUR);
			SusuRotate( mySusu); // le susu tourne sur lui même de plus en plus vite
			//Test gauche
			if (mySusu->x - mySusu->rayon < 0  ){
				mySusu->x = 1+ mySusu->rayon;
			}
			//Test droite
			if (mySusu->x + mySusu->rayon > LARGEUR  ){
				mySusu->x = LARGEUR - (1+ mySusu->rayon);
			}
			//test bas :
			if (mySusu->y + mySusu->rayon > 2*HAUTEUR + DECALAGE - H_SCORE){
				mySusu->y = 2*HAUTEUR + DECALAGE  - H_SCORE - (1+ mySusu->rayon);
			}
		}
		break;

	case RELEASING : // Actions à entreprendre au moment ou le Susu est laché, ou quand le stylet sort de celui-ci
		mySusu->v=1.5 +mySusu->v_angle/300;
		mySusu->v_angle=0;
		myTouchState = NOT_TOUCHED;
		break;

	default:
		myTouchState = NOT_TOUCHED;
		break;
	}

	mySusu->x += mySusu->v*cos(2*M_PI*mySusu->angle/32768)  ;
	mySusu->y -= mySusu->v*sin(2*M_PI*mySusu->angle/32768)  ;

}



void setSusuPosition(pSusu mySusu,int px, int py){
	mySusu->x =  px;
	mySusu->y = py;
}

double deg2oamAngle(double angle){
	return angle*32768/360;
}

double oamAngle2deg(double angle){
	return 360*angle/32768;
}


void setSusuAngle(pSusu mySusu,double angle){
	mySusu->angle = deg2oamAngle(((int)angle)%360);
}



void setSusuBigger(pSusu mySusu){

	if (mySusu->size < 4) {

		mySusu->size++; // Augmenter la taille
		mySusu->oamIndex = mySusu->size; // Changer l'index OAM

		mySusu->gfx_main = gfx_susu_main[mySusu->size]; // On associe l'adresse memoire correspondante
		mySusu->gfx_sub = gfx_susu_sub[mySusu->size];

		mySusu->rayon = mySusu->liste_diametre[mySusu->size] /2 ; // Nouveau rayon

		// Maintenant on déplace le Susu si il grandit trop pres du bord (en effet il est bloqué dans ce cas)
		if (mySusu->x - mySusu->rayon < 0  ){
			mySusu->x = (1+ mySusu->rayon);
		}
		if (mySusu->x + mySusu->rayon > LARGEUR  ){
			mySusu->x = LARGEUR -  (1+ mySusu->rayon);
		}

		if (mySusu->y - mySusu->rayon < 0  ){
			mySusu->y = (1+ mySusu->rayon);
		}
		if (mySusu->y + mySusu->rayon > 2*HAUTEUR + DECALAGE ){
			mySusu->y = 2*HAUTEUR + DECALAGE - (1+ mySusu->rayon);
		}
	}


}
void setSusuSmaller(pSusu mySusu){
	if (mySusu->size  > 0) {

		mySusu->size--;
		mySusu->oamIndex = mySusu->size;

		mySusu->gfx_main = gfx_susu_main[mySusu->size];
		mySusu->gfx_sub = gfx_susu_sub[mySusu->size];

		mySusu->rayon = mySusu->liste_diametre[mySusu->size] /2 ;

	}
}


void SusuRotate(pSusu mySusu){

	mySusu->v_angle+=mySusu->a_angle;


	mySusu->angle += mySusu->v_angle;
	mySusu->orientation = mySusu->angle;

}

void SusuRotateToNewAngle(pSusu mySusu){
	int delta = (int)(mySusu->angle - mySusu->orientation) % 32768 ;

	int etha = 50;
	if(delta > etha  ){
		if(delta > 32768/2){
			mySusu->orientation -= 200;
		}else {
			mySusu->orientation += 200;
		}

	} else if (delta < - etha ){
		if(delta < -32768/2){
			mySusu->orientation += 200;
		}else {
			mySusu->orientation -= 200;
		}
	} else {
		mySusu->orientation = mySusu->angle;
	}
	mySusu->orientation = (int)mySusu->orientation;
}


void SusuUpdate(pSusu mySusu){
	// C'est la moité de la longueur du coté du sprite. Dans la suite cela sert à décaller la position du Susu
	// de facon à ce que la coordonnée du Susu corresponde au centre de celui-ci.
	int j;

	// Dans l'écran MAIN  //

	//on affiche le Susu si :

	if ( (mySusu->y >= 0- halfwidth ) && ( mySusu->y <= HAUTEUR+ halfwidth)){
		oamSet(&oamMain, 	// oam handler

				mySusu->oamIndex,			// Number of sprite

				(int)mySusu->x - halfwidth ,(int)mySusu->y - halfwidth,			// Coordinates

				0,				// Priority
				mySusu->oamIndex,				// Palette to use
				SpriteSize_64x64,			// Sprite size
				SpriteColorFormat_256Color,	// Color format
				mySusu->gfx_main,			// Loaded graphic to display
				0,				// Affine rotation to use (-1 none)
				false,			// Double size if rotating
				false,			// Hide this sprite     /!\ Susu affiché  !!!
				false, false,	// Horizontal or vertical flip
				false			// Mosaic
		);

		// Update the angle of the Susu
		oamRotateScale(&oamMain,0,mySusu->orientation,1 <<8, 1 <<8);


	}
	//sinon on le cache :
	else {
		oamSet(&oamMain, 	// oam handler

				mySusu->oamIndex,		// Number of sprite
				(int)mySusu->x - halfwidth,(int)mySusu->y - halfwidth,			// Coordinates


				0,				// Priority
				mySusu->oamIndex,				// Palette to use
				SpriteSize_64x64,			// Sprite size
				SpriteColorFormat_256Color,	// Color format
				mySusu->gfx_main,			// Loaded graphic to display
				0,				// Affine rotation to use (-1 none)
				false,			// Double size if rotating
				true,			// Hide this sprite    /!\ Susu caché !!!
				false, false,	// Horizontal or vertical flip
				false			// Mosaic
		);



	}

	// Dans l'écran SUB //

	//On affiche le  Susu si :
	if( (mySusu->y >=  DECALAGE + HAUTEUR- halfwidth ) && ( mySusu->y <= DECALAGE + 2*HAUTEUR + halfwidth )){
		oamSet(&oamSub, 	// oam handler
				mySusu->oamIndex,		// Number of sprite

				(int)mySusu->x- halfwidth ,(int)mySusu->y- (DECALAGE +HAUTEUR) - halfwidth,			// Coordinates

				0,				// Priority
				mySusu->oamIndex,				// Palette to use
				SpriteSize_64x64,			// Sprite size
				SpriteColorFormat_256Color,	// Color format
				mySusu->gfx_sub,			// Loaded graphic to display
				0,				// Affine rotation to use (-1 none)
				false,			// Double size if rotating
				false,			// Hide this sprite
				false, false,	// Horizontal or vertical flip
				false			// Mosaic
		);
		// Update the angle of the Susu
		oamRotateScale(&oamSub,0,mySusu->orientation,1 <<8, 1 <<8);
	}


	//Sinon on cache le Susu:
	else {
		oamSet(&oamSub, 	// oam handler

				mySusu->oamIndex,				// Number of sprite
				(int)mySusu->x - halfwidth ,(int)mySusu->y- (DECALAGE +HAUTEUR) - halfwidth,			// Coordinates

				0,				// Priority
				mySusu->oamIndex,				// Palette to use
				SpriteSize_64x64,			// Sprite size
				SpriteColorFormat_256Color,	// Color format
				mySusu->gfx_sub,			// Loaded graphic to display
				0,				// Affine rotation to use (-1 none)
				false,			// Double size if rotating
				true,			// Hide this sprite
				false, false,	// Horizontal or vertical flip
				false			// Mosaic
		);
	}
	// On cache tous les Susus qui ne sont pas actifs :
	for (j = 0; j <5 ; j++){
		if (mySusu->oamIndex != j){
			oamSetAffineIndex(&oamMain,j,-1,false);
			oamSetAffineIndex(&oamSub,j,-1,false);
			oamSetHidden(&oamMain,j,true);
			oamSetHidden(&oamSub,j,true);

		}
	}


	oamUpdate(&oamMain);
	oamUpdate(&oamSub);

}



//----Vérifie si (px,py) se trouve sur le Susu
int InSusuSurface(pSusu mySusu, u16 px, u16 py){

	double a,b;
	double r, distance;


	a= (double)mySusu->x;
	b= (double)mySusu->y;
	r= (double)mySusu->rayon;
	distance = (px-a) * (px-a) + (py-b) * (py-b);

	if( distance <=r * r )
	{
		return 1;}

	else {
		return 0;}
}


