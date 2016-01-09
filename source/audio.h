/*
 * audio.h
 *
 *  Created on: 9 janv. 2016
 *      Author: adrian
 */

#ifndef SOURCE_AUDIO_H_
#define SOURCE_AUDIO_H_
#include <nds.h>
#include <maxmod9.h>
#include "soundbank.h"
#include "soundbank_bin.h"

void audioInit();
void loadMusic();
void loadEffect();

#endif /* SOURCE_AUDIO_H_ */
