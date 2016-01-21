/*
 * interruptions.c
 *
 *  Created on: 3 janv. 2016
 *      Author: adrian
 */

#include "interruptions.h"
#include "Graphics_Items.h"

	int sec=0;
	int i=-1;

void ISR_TIMER(){


	if (levelSelected==6){
		sec=sec+1;
		if(sec==5){
			i=i+1;
			sec=0;
			//for (i=nbr_mushroom ; i< nbr_mushroom +nbr_clover ; i++)
		   if ( i <nbr_clover )
		   {itemDisappear(nbr_mushroom+i);}
		}
	}

	else if (levelSelected==7){

		sec=sec+1;
		if(sec==5){
			sec=0;
			i=i+1;
			//for (i=nbr_mushroom ; i< nbr_mushroom +nbr_clover ; i++)
		   if ( i<5) //nbr_clover )
		   {itemDisappear(nbr_mushroom+i);
		    itemDisappear(nbr_mushroom+i+5);}
		}
		}

	else if (levelSelected==8){

		sec=sec+1;
		if(sec==5){

			//for (i=nbr_mushroom ; i< nbr_mushroom +nbr_clover ; i++)
		   for(i=-1; i<nbr_clover;i++ )
		   {
			  itemDisappear(nbr_mushroom+i);}
		}

		   if(sec==10){
			   for(i=-1; i<nbr_clover;i++ )
			 		   {
			 			  Items[nbr_mushroom+i]->hidden=0;}
			   sec=0;
			 		}

		   		  ;}

		}


void timerInit(){

	TIMER0_CR =TIMER_ENABLE | TIMER_DIV_1024 |TIMER_IRQ_REQ;
	TIMER0_DATA=TIMER_FREQ_1024(1);

	irqSet(IRQ_TIMER0, &ISR_TIMER);

}
