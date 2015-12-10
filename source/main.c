/*
 * Template Nintendo DS
 * May 2011
 */

#include <nds.h>
#include <stdio.h>

int main(void) {
	
    consoleDemoInit();
    printf("\nTemplate nds loveyolo it\n");

    while(1)
        swiWaitForVBlank();	
}
