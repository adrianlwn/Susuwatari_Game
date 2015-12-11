/*
 * Template Nintendo DS
 * May 2011
 */

#include <nds.h>
#include <stdio.h>

#include "init.h"

int main(void) {
<<<<<<< HEAD
	
    consoleDemoInit();
    printf("\nTemplate nds loveyolo it\n");
=======
>>>>>>> master

	typedef enum {
		INIT,
		MENU,
		PLAY,
		END
	} state ;


	state state_G = INIT;

	int i=0;

	while(1){
		i++;
		switch (state_G) {
		case INIT :
			init_NDS();
		    consoleDemoInit();
		    printf("C'est l'heure de l'Init %d\n",i);


			state_G = MENU;
			break;
		case MENU:
			printf("C'est l'heure du Menu %d\n",i);
			state_G = PLAY;
			break;
		case PLAY:
			printf("C'est l'heure du Jeu %d\n",i);
			state_G = END;
			break;
		case END :

			break;
		default :
			break;
		}





		swiWaitForVBlank();
	}

}
