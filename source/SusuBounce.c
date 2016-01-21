#include "SusuBounce.h"

#define HAUTEUR 192
#define LARGEUR 256
#define DECALAGE 96
#define H_SCORE 12

void BounceUpdate(){
	// On utilise une methode  simple et  fiable pour la detection des murs.
	// On etablit la conditions du rebond :

	//------OBSTACLES :

	// mur gauche :
	if(mySusu->x <= 0 + mySusu->rayon){
		BounceSusu(90);
	}
	// mur droite :
	if (mySusu->x >= LARGEUR - mySusu->rayon) {
		BounceSusu(90);
		//setSusuAngle(mySusu, ( 2*(int)mySusu->angle + 90)   );

	}
	// mur haut :
	if (mySusu->y <= 0 + mySusu->rayon) {
		BounceSusu(0);
	}
	// mur bas :
	if ( mySusu->y >= DECALAGE + HAUTEUR*2 - H_SCORE - mySusu->rayon){
		BounceSusu( 0);
	}

	// Condition de rotation au ralentis pour atteindre la valeur limite.
	SusuRotateToNewAngle();

}
void BounceSusu( double bounce_angle){

	int angle_previous = oamAngle2deg( mySusu->angle);

	setSusuAngle( - angle_previous + 2* bounce_angle);
	mmEffect(SFX_SUSUBOUNCE);

}


