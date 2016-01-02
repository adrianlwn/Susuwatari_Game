#include "SusuBounce.h"


void initMapObstacle(mapObstacle myMapObstacle){
	// Effacer l'ensemble de la map en mettant chaque angle de chaque pixel à -1.
	// Cela veut aussi dire que chaque position de la map d'obstacle contiendra un angle positif en cas d'obstacle.
	int i,j;
	for(i = 0 ; i < 256 ; i ++){
		for(j = 0 ; j < 2*192 ; j++){
			myMapObstacle[i][j] = -1;
		}
	}

	// Maintenant on initialise les bordures exterieures de notre environnement. (on aurait pu le faire precedement mais
	// par soucis de clarté, nous le faisons ici.) Sur les cotés on met des angle 0 et 90°,
	// dans les angles on met des angles 45° et 135°.

	for (i=0 ; i <256 ; i++){
		myMapObstacle[i][0] = deg2oamAngle(180);
		myMapObstacle[i][2*192-1] = 0;
	}

	for(j = 0 ; j < 2*192 ; j ++ ){
		myMapObstacle[0][j] = deg2oamAngle(270);
		myMapObstacle[256-1][j] = 	deg2oamAngle(90);
	}
	/*
	myMapObstacle[0][0] = 45*32768/360;
	myMapObstacle[256-1][0] = 135*32768/360;
	myMapObstacle[0][192*2-1] = 135*32768/360;
	myMapObstacle[256-1][192*2-1] = 45*32768/360;
*/
	// Maintenant on peut tracer d'autres formes sur lesquelles le Susu peut rebondir.
	// ...
	// ...

}

void BounceUpdate(pSusu mySusu, mapObstacle myMapObstacle){
	// ------ NEW VERSION ----------
	// On utilise une methode plus simple et plus fiable pour la detection des murs.
	// On etablit la conditions du rebond :

	// mur gauche :
	if(mySusu->x <= 0 + mySusu->diametre){
		BounceSusu(mySusu, 90);
	}
	// mur droite :
	if (mySusu->x >= 256 - mySusu->diametre) {
		BounceSusu(mySusu, 90);
		//setSusuAngle(mySusu, ( 2*(int)mySusu->angle + 90)   );

	}
	// mur haut :
	if (mySusu->y <= 0 + mySusu->diametre) {
		BounceSusu(mySusu,0);
	}
	// mur bas :
	if ( mySusu->y >= 192*2 - mySusu->diametre){
		BounceSusu(mySusu, 0);
	}

	// ----- OLD VERSION -------
	/*
	// On va etablir les conditions du rebond
	int alpha, x_c, y_c;
	for(alpha = 0 ; alpha <= 100 ; alpha ++ ){
		x_c = mySusu->diametre*cos(2*M_PI * ((double)alpha )/ 100);
		y_c = - mySusu->diametre*sin(2*M_PI * ((double)alpha )/ 100 );

		if ( myMapObstacle[(int)(mySusu->x+ x_c)][ (int)(mySusu->y + y_c)] != -1 ){
			BounceSusu(mySusu,myMapObstacle[(int)x_c][(int)y_c]);
		}
	}
*/
	// Condition de rotation au ralentis pour atteindre la valeur limite.
	SusuRotateToNewAngle(mySusu);

}
void BounceSusu(pSusu mySusu, double bounce_angle){
	int angle_previous = oamAngle2deg( mySusu->angle);

	setSusuAngle(mySusu, - angle_previous + 2* bounce_angle);

		//mySusu->angle = deg2oamAngle(180);
		//mySusu->new_angle = deg2oamAngle(180);

}


