/*
 * interruptions.c
 *
 *  Created on: 3 janv. 2016
 *      Author: adrian
 */

#include "interruptions.h"
#include "Graphics_Items.h"

	int sec=0;
	int a=-1;

void ISR_TIMER(){


	if (levelSelected==6){
		sec=sec+1;
		if(sec==5){
			a=a+1;
			sec=0;
			//for (i=nbr_mushroom ; i< nbr_mushroom +nbr_clover ; i++)
		   if ( a <nbr_clover )
		   {itemDisappear(nbr_mushroom+a);}
		}
	}

	else if (levelSelected==7){

		sec=sec+1;
		if(sec==5){
			sec=0;
			a=a+1;
			//for (i=nbr_mushroom ; i< nbr_mushroom +nbr_clover ; i++)
		   if ( a<5) //nbr_clover )
		   {itemDisappear(nbr_mushroom+a);
		    itemDisappear(nbr_mushroom+a+5);}
		}
		}

	else if (levelSelected==8){

		sec=sec+1;
		if(sec==5){

			//for (i=nbr_mushroom ; i< nbr_mushroom +nbr_clover ; i++)
		   for(a=0; a<nbr_clover;a++ )
		   {
			  itemDisappear(nbr_mushroom+a);}
		}

		   if(sec==10){
			   for(a=0; a<nbr_clover;a++ )
			 		   {
			 			  Items[nbr_mushroom+a]->hidden=0;}
			   sec=0;
			 		}

		   		  ;}

		}

void timerReset()
{
sec=0;
 a=-1;
}

void timerInit(){

	TIMER0_CR =TIMER_ENABLE | TIMER_DIV_1024 |TIMER_IRQ_REQ;
	TIMER0_DATA=TIMER_FREQ_1024(1);

	irqSet(IRQ_TIMER0, &ISR_TIMER);

}
