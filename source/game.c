/*
 * game.c
 *
 *  Created on: 8 déc. 2015
 *      Author: adrian
 */
#include "game.h"
#include <stdio.h>
#include <nds.h>
#include "Graphics_Susu.h"
#include "Graphics_BG.h"
#include "Graphics_Items.h"
#include "menu.h"

#include "Star.h"
#include "Mushroom.h"
#include  "Clover.h"
#include "Graphics_SPRITE.h"

#define HAUTEUR 192
#define LARGEUR 256
#define DECALAGE 96


void initPlayer(pPlayer myPlayer){

	myPlayer->life=5;
	myPlayer->score=0;
	LifeScore( myPlayer);
	StarScore( myPlayer);


}

void initLevel(int levelNum){
	// LOAD GAME GRAPHICS
	loadGraphics_Main(levelNum);
	loadGraphics_Sub(levelNum);


	theSusu = malloc(sizeof(Susu));
	initSusu(theSusu);

	int i;
	for(i = 0 ; i <100 ; i++){
		Items[i]= malloc(sizeof(Item));
	}


	chooseItems (Items,levelNum);
	setItemsPosition( Items,levelNum);
	initItems(Items);


	initPlayer(thePlayer);
}


/* --- Fonction play Game :
 * Fonction qui tourne dans la boucle du jeu et qui est chargée d'appeller toutes les fonctions
 *  qui actualisent les positions des element et l'etat du Jeu (gameOver, colisions avec items)
 */

void playGame(){

	//--Verifie si on a atteint la situation de GameOver, si c'est le cas, on quitte l'etat actuel du jeu
	checkGameOver(thePlayer, theSusu);
	// --Deplacement selon la vitesse
	SusuMove(theSusu);
	//-- Actualisation du rebond (angle du mouvement change)
	BounceUpdate(theSusu);

	// --index de l'element avec lequel il y a eu collision :
	int indexTouched = collision();

	// -- Gestion de la collision :
	if(indexTouched != -1 )
	{

		if( Items[indexTouched]->itemType == MUSHROOM)
			// Reduction de la taille du Susu et perte d'une vie, disparition de l'element touché
		{

			setSusuSmaller(theSusu);

			itemDisappear(indexTouched);

			thePlayer->life--;
			// Actualisation du score en bas de l'ecran

			LifeScore(thePlayer);

		}


		else if( Items[indexTouched]->itemType == STAR)
			// Le susu gagne une etoile (5 etoiles pour finir le niveau) et l'etoile disparait
		{
			thePlayer->score++;
			itemDisappear(indexTouched);
			// Actualisation du score en bas de l'ecran
			StarScore(thePlayer);


		}


		else if( Items[indexTouched]->itemType == CLOVER)
			// Le Susu gagne une vie et grossit en meme temps (5 vies maximum)
		{
			setSusuBigger(theSusu);
			itemDisappear(indexTouched);
			if (thePlayer->life <5)
			{
				thePlayer->life++;
			}
			// Actualisation du score en bas de l'ecran
			LifeScore(thePlayer);


		}

	}
	/* Appel de la fonction qui actualise physiquement la position et l'etat des sprites des
	 * items
	 */
	displayItems(Items);

	/*Appel de la fonction SusuUpdate qui deplace physiquement le Sprite Susu en
	*fonction  de sa nouvelle position taille, orientation, etc ...
	*/
	SusuUpdate(theSusu);


}



/* FONCTION collision :
 * Renvoie l'index de l'item touché
 */
int collision(){

	// valeur par defaut de l'index de l'element touché
	int indexTouched = -1;

	int i;
	// On parcours la liste complete des items
	for(i=0; i< 100 ; i++){

		// verification pour savoir si le centre de l'item "visible" est dans la surface du SusuWatari
		if( InSusuSurface(theSusu, Items[i]->x, Items[i]->y) ==1  && Items[i]->hidden == 0)
		{
			indexTouched=i;
		}
	}
	return indexTouched;
}




/* FONCTION itemDisappear :
 * Change l'etat hidden de l'item dans la liste des item en fonction de l'index donné
 */
void itemDisappear(int indexTouched)
{
	Items[indexTouched]->hidden=1;
}

void StarScore(pPlayer myPlayer)
{
	int i;
	int halfwidth=5;


	for(i=0; i<5; i++)
	{

		oamSet( &oamSub, 	// oam handler
				i+5+5 +5 +5,				// Number of sprite
				185+i*11- halfwidth , 192-6- halfwidth ,			// Coordinates
				0,				// Priority
				nbr_pal_score_creux,				// Palette to use
				SpriteSize_8x16,			// Sprite size
				SpriteColorFormat_256Color,	// Color format
				gfx_star_creux_score ,			// Loaded graphic to display
				-1,				// Affine rotation to use (-1 none)
				false,			// Double size if rotating
				false,			// Hide this sprite
				false, false,	// Horizontal or vertical flip
				false			// Mosaic
		);

		if(i < myPlayer->score )
		{


			oamSet( &oamSub, 	// oam handler
					i+5,				// Number of sprite
					185+i*11- halfwidth ,192-6- halfwidth ,			// Coordinates
					0,				// Priority
					nbr_pal_score,				// Palette to use
					SpriteSize_8x16,			// Sprite size
					SpriteColorFormat_256Color,	// Color format
					gfx_star_score,			// Loaded graphic to display
					-1,				// Affine rotation to use (-1 none)
					false,			// Double size if rotating
					false,			// Hide this sprite
					false, false,	// Horizontal or vertical flip
					false			// Mosaic
			);
		}
		else {

			oamSet( &oamSub, 	// oam handler
					i+5,				// Number of sprite
					185+i*11- halfwidth ,192-6- halfwidth ,			// Coordinates
					0,				// Priority
					nbr_pal_score,				// Palette to use
					SpriteSize_8x16,			// Sprite size
					SpriteColorFormat_256Color,	// Color format
					gfx_star_score,			// Loaded graphic to display
					-1,				// Affine rotation to use (-1 none)
					false,			// Double size if rotating
					true,			// Hide this sprite
					false, false,	// Horizontal or vertical flip
					false			// Mosaic
			);
		}

	}

}

void LifeScore(pPlayer myPlayer)
{
	int i;
	int halfwidth=5;

	for(i=0; i< 5; i++)

	{

		oamSet( &oamSub, 	// oam handler
				i+5+5 +5,				// Number of sprite
				55+i*11- halfwidth , 192-4- halfwidth ,			// Coordinates
				0,				// Priority
				nbr_pal_coeur_creux,				// Palette to use
				SpriteSize_8x16,			// Sprite size
				SpriteColorFormat_256Color,	// Color format
				gfx_heart_creux_score ,			// Loaded graphic to display
				-1,				// Affine rotation to use (-1 none)
				false,			// Double size if rotating
				false,			// Hide this sprite
				false, false,	// Horizontal or vertical flip
				false			// Mosaic
		);

		if(i<myPlayer->life)
		{
			oamSet( &oamSub, 	// oam handler
					i+5+5,				// Number of sprite
					55+i*11- halfwidth , 192-4- halfwidth ,			// Coordinates
					0,				// Priority
					nbr_pal_coeur,				// Palette to use
					SpriteSize_8x16,			// Sprite size
					SpriteColorFormat_256Color,	// Color format
					gfx_heart_score,			// Loaded graphic to display
					-1,				// Affine rotation to use (-1 none)
					false,			// Double size if rotating
					false,			// Hide this sprite
					false, false,	// Horizontal or vertical flip
					false			// Mosaic
			);
		}

		else{
			oamSet( &oamSub, 	// oam handler
					i+5+5,				// Number of sprite
					55+i*11- halfwidth , 192-4- halfwidth ,			// Coordinates
					0,				// Priority
					nbr_pal_coeur,				// Palette to use
					SpriteSize_8x16,			// Sprite size
					SpriteColorFormat_256Color,	// Color format
					gfx_heart_score,			// Loaded graphic to display

					-1,				// Affine rotation to use (-1 none)
					false,			// Double size if rotating
					true,			// Hide this sprite
					false, false,	// Horizontal or vertical flip
					false			// Mosaic
			);
		}
	}
}





void checkGameOver(pPlayer myPlayer, pSusu mySusu){
	int nb_max_stars = 5;

	// --- LEVEL ACCOMPLISHED :
	// quand toutes les etoiles sont ramassées.
	if (myPlayer->score == nb_max_stars){
		levelList[levelSelected-1]->best_score = mySusu->size +1;
		levelList[levelSelected]->locked = false;

		// On ecrit le score dans le fichier. Si le score est meilleur que l'actuel Best Score :
		if (thePlayer->score >= levelList[levelSelected-1]->best_score ){
			writeScore();}
		goToEndLevel();

	}

	// --- LEVEL FAILED :
	// Si le joueur perd toutes ses vies. Ou si le Susu a une vitesse 0 sur l'ecran du haut.
	if (myPlayer->life == 0 || (mySusu->v == 0 && mySusu->y < HAUTEUR + DECALAGE - mySusu->rayon)){
		goToEndLevel();

	}


}




