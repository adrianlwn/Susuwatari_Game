#include "SusuBounce.h"

mapObstacle myMapObstacle;

void initMapObstacle(){
	// Effacer l'ensemble de la map en mettant chaque angle de chaque pixel à -1.
	// Cela veut aussi dire que chaque position de la map d'obstacle contiendra un angle positif en cas d'obstacle.
	int i,j;
	for(i = 0 ; i < 256 ; i ++){
		for(j = 0 ; j < 2*192 ; j++){
			myMapObstacle[i][j] = -1;
		}
	}

	// Maintenant on initialise les bordures exterieures de notre environnement. (on aurait pu le faire precedement mais
	// par soucis de clarté, nous le faisons ici.)
	for (i=0 ; i <256 ; i++){
		myMapObstacle[i][0] = 0;
		myMapObstacle[i][2*192-1] = 0;
	}
	for(j = 0 ; i < 2*192 ; j ++ ){
		myMapObstacle[0][j] = 90*32768/360;
		myMapObstacle[256-1][j] = 	90*32768/360;
	}

	// Maintenant on peut tracer d'autres formes et inventer ainsi d'autres rebonds.


}
void bounceSusu(pSusu mySusu){



}


