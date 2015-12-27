/*
 * SusuBounce.h
 *
 *  Created on: 11 déc. 2015
 *      Author: valentine
 */

#ifndef SUSUWATARI_SUSUGAMEPLAY_H_
#define SUSUWATARI_SUSUGAMEPLAY_H_

#include "Graphics_Susu.h"


 typedef double mapObstacle[256][2*192] ;
void initMapObstacle();

void BounceUpdate(pSusu mySusu);
void BounceSusu(pSusu mySusu, double bounce_angle);

#endif /* SUSUWATARI_SUSUGAMEPLAY_H_ */
