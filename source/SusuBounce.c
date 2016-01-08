#include "SusuBounce.h"

#define HAUTEUR 192
#define LARGEUR 256

void BounceUpdate(pSusu mySusu, mapObstacle myMapObstacle){
	// On utilise une methode  simple et  fiable pour la detection des murs.
	// On etablit la conditions du rebond :

	//------OBSTACLES :

	// mur gauche :
	if(mySusu->x <= 0 + mySusu->rayon){
		BounceSusu(mySusu, 90);
	}
	// mur droite :
	if (mySusu->x >= LARGEUR - mySusu->rayon) {
		BounceSusu(mySusu, 90);
		//setSusuAngle(mySusu, ( 2*(int)mySusu->angle + 90)   );

	}
	// mur haut :
	if (mySusu->y <= 0 + mySusu->rayon) {
		BounceSusu(mySusu,0);
	}
	// mur bas :
	if ( mySusu->y >= HAUTEUR*2 - mySusu->rayon){
		BounceSusu(mySusu, 0);
	}

	// Condition de rotation au ralentis pour atteindre la valeur limite.
	SusuRotateToNewAngle(mySusu);

}
void BounceSusu(pSusu mySusu, double bounce_angle){

	int angle_previous = oamAngle2deg( mySusu->angle);

	setSusuAngle(mySusu, - angle_previous + 2* bounce_angle);

}


