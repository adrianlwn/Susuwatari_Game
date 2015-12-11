/*
 * Template Nintendo DS
 * May 2011
 */

#include <nds.h>
#include <stdio.h>

#include "init.h"
#include "Graphics_SPRITE.h"



int main(void) {

	typedef enum {
		INIT,
		MENU,
		PLAY,
		END
	} state ;


	state state_G = INIT;


	while(1){

		switch (state_G) {
		case INIT :
			init_NDS();



			state_G = MENU;
			break;
		case MENU:

			state_G = PLAY;
			break;
		case PLAY:
			displayPlayer();
			//state_G = END;
			break;
		case END :

			break;
		default :
			break;
		}





	}

}
