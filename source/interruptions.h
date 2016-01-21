/*
 * interruptions.h
 *
 *  Created on: 3 janv. 2016
 *      Author: adrian
 */

#ifndef SOURCE_INTERRUPTIONS_H_
#define SOURCE_INTERRUPTIONS_H_

#include <nds.h>
#include "menu.h"

void ISR_TIMER(); // A partir du niveau 6, on utilise les timers pour faire disparaître
//et réapparaître les trèfles;

void timerInit();
void timerReset();
#endif /* SOURCE_INTERRUPTIONS_H_ */
