/*
 * audio.c
 *
 *  Created on: 9 janv. 2016
 *      Author: adrian
 */

#include "audio.h"

void audioInit(){
	mmInitDefaultMem((mm_addr)soundbank_bin);


}

void loadMusic(){
	// Load the main music
		mmLoad(MOD_ENIGMA);
}

void loadEffect(){
	mmLoadEffect(SFX_SUSUBOUNCE);
}
