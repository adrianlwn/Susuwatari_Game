/*
 * SusuBounce.h
 *
 *  Created on: 11 déc. 2015
 *      Author: valentine
 */

#ifndef SUSUWATARI_SUSUGAMEPLAY_H_
#define SUSUWATARI_SUSUGAMEPLAY_H_

#include "Graphics_Susu.h"


 typedef double mapObstacle[256][384] ;
void initMapObstacle(mapObstacle myMapObstacle);

void BounceUpdate(pSusu mySusu,mapObstacle myMapObstacle);
void BounceSusu(pSusu mySusu, double bounce_angle);

#endif /* SUSUWATARI_SUSUGAMEPLAY_H_ */
