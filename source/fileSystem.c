/*
 * fileSystem.c
 *
 *  Created on: 8 janv. 2016
 *      Author: adrian
 */

#include "fileSystem.h"

void writeInit(){
	fatInitDefault();

}

void readScore(){
	di = opendir("/NDS/");
	file = fopen("/NDS/SusuSave.txt", "r");
	if(file == NULL){
		file = fopen("/SusuSave.txt", "w+");
		//while((pent = readdir(di))!= NULL){
			stat(pent->d_name, &st);

			fprintf(file, " %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i",
					levelList[0]->best_score, levelList[0]->locked,
					levelList[1]->best_score, levelList[1]->locked,
					levelList[2]->best_score, levelList[2]->locked,
					levelList[3]->best_score, levelList[3]->locked,
					levelList[4]->best_score, levelList[4]->locked,
					levelList[5]->best_score, levelList[5]->locked,
					levelList[6]->best_score, levelList[6]->locked,
					levelList[7]->best_score, levelList[7]->locked);
		//}



	}

	//while((pent = readdir(di))!= NULL){
		stat(pent->d_name, &st);
		fscanf(file, " %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i",
				&levelList[0]->best_score, &levelList[0]->locked,
				&levelList[1]->best_score, &levelList[1]->locked,
				&levelList[2]->best_score, &levelList[2]->locked,
				&levelList[3]->best_score, &levelList[3]->locked,
				&levelList[4]->best_score, &levelList[4]->locked,
				&levelList[5]->best_score, &levelList[5]->locked,
				&levelList[6]->best_score, &levelList[6]->locked,
				&levelList[7]->best_score, &levelList[7]->locked);
	//}

	closedir(di);
	fclose(file);
}
void writeScore(){
	di = opendir("/NDS/");
	file = fopen("/NDS/SusuSave.txt", "w+");

	//while((pent = readdir(di))!= NULL){
		stat(pent->d_name, &st);
		fprintf(file, " %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i",
				levelList[0]->best_score, levelList[0]->locked,
				levelList[1]->best_score, levelList[1]->locked,
				levelList[2]->best_score, levelList[2]->locked,
				levelList[3]->best_score, levelList[3]->locked,
				levelList[4]->best_score, levelList[4]->locked,
				levelList[5]->best_score, levelList[5]->locked,
				levelList[6]->best_score, levelList[6]->locked,
				levelList[7]->best_score, levelList[7]->locked);
	//}
	closedir(di);
	fclose(file);
}
