/*
 * Susu.c
 *
 *  Created on: 13 déc. 2015
 *      Author: adrian
 */

#include "Graphics_Susu.h"
#include "Graphics_Items.h"
#include "Graphics_SPRITE.h"
#include "Susu.h"

void initSusu(pSusu mySusu){

	// Allocate la memoire oam pour la taille du sprite.
	mySusu->size=2;
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


	mySusu->angle=0;
	mySusu->orientation = 0;

	mySusu->v= 0;
	mySusu->v_angle=150;
	mySusu->a_angle=2;

	mySusu->x = 100;
	mySusu->y = 250;


}

void setSusuPosition(pSusu mySusu,double x, double y){
	mySusu->x = x;
	mySusu->y = y;
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

void setSusuOrientation(pSusu mySusu, double angle){
	mySusu->orientation = deg2oamAngle(((int)angle));
}


void setSusuBigger(pSusu mySusu){

	if (mySusu->size < 4) {

		mySusu->size++;
		mySusu->oamIndex = mySusu->size;

		mySusu->gfx_main = gfx_susu_main[mySusu->size];
		mySusu->gfx_sub = gfx_susu_sub[mySusu->size];

		mySusu->rayon = mySusu->liste_diametre[mySusu->size] /2 ;


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

void SusuRotate(pSusu mySusu,int ON){

	if (ON == false){

		mySusu->v_angle = 0;
	}
	else{mySusu->v_angle+=mySusu->a_angle;

	}
	mySusu->angle += mySusu->v_angle;
	mySusu->orientation = mySusu->angle;

}

void SusuRotateToNewAngle(pSusu mySusu){
	int delta = (int)(mySusu->angle - mySusu->orientation) % 32768 ;
	/*if (delta >= 32768/2 ){
		delta -= 32768;
	}*/
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
	int halfwidth = 32;
	int j;

	// Dans l'écran MAIN  //

	//on affiche le Susu si :

	if ( (mySusu->y >= 0- halfwidth ) && ( mySusu->y <= 192+ halfwidth)){
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
	if( (mySusu->y >= 192- halfwidth ) && ( mySusu->y <= 2*192 + halfwidth )){
		oamSet(&oamSub, 	// oam handler
				mySusu->oamIndex,		// Number of sprite

				(int)mySusu->x- halfwidth ,(int)mySusu->y-192 - halfwidth,			// Coordinates

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
				(int)mySusu->x - halfwidth ,(int)mySusu->y-192 - halfwidth,			// Coordinates

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

	swiWaitForVBlank();
}

//----Vérifie si (px,py) se trouve sur le Susu
int InSusuSurface(pSusu mySusu, u16 px, u16 py){

	double a,b;
	int r;


	a= mySusu->x;
	b= mySusu->y;
	r= mySusu->rayon;


	if((px-a) * (px-a) + (py-b) * (py-b) <=(r * r))
	{
		return 1;}

	else {
		return 0;}
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
	int held, up , down;


	scanKeys();

	held=keysHeld();
	down = keysDown();
	up=keysUp();

	touchPosition pos;
	touchRead(&pos);
	touch_inside=InSusuSurface( mySusu, pos.px,  pos.py + 192);

	switch (myTouchState) {
	case NOT_TOUCHED:
		if(touch_inside == 1 && (down & KEY_TOUCH)){
			myTouchState = TOUCHING;
		}

		break;
	case TOUCHING :
		mySusu->v=0;
		myTouchState = TOUCHED;
		break;
	case TOUCHED :

		SusuRotate( mySusu, true); // le susu tourne sur lui même de plus en plus vite
		if ((touch_inside == 0 && (held & KEY_TOUCH) ) || (up & KEY_TOUCH) ){
			myTouchState = RELEASING;
		}
		break;
	case RELEASING :
		mySusu->v=0.4 +mySusu->v_angle/500;
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



void SusuMoveTest2(pSusu mySusu){
	int keys;
	scanKeys();

	keys = keysHeld();
	if(keys & KEY_RIGHT) mySusu->angle-= 150;
	if(keys & KEY_LEFT) mySusu->angle+= 150;
	mySusu->angle =(int)mySusu->angle  %32768;
	mySusu->x += mySusu->v*cos(2*M_PI*mySusu->angle/32768)  ;
	mySusu->y -= mySusu->v*sin(2*M_PI*mySusu->angle/32768)  ;
};

