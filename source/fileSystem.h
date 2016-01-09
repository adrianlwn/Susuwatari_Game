/*
 * fileSystem.h
 *
 *  Created on: 8 janv. 2016
 *      Author: adrian
 */

#ifndef SOURCE_FILESYSTEM_H_
#define SOURCE_FILESYSTEM_H_
#include <nds.h>
#include <stdio.h>
#include <sys/dir.h>
#include <fat.h>
#include <dirent.h>

#include "game.h"
#include "menu.h"

// Structures declaration
DIR* di;
struct dirent *pent;
FILE* file;
struct stat st;

void writeInit();
void writeScore();
void readScore();
#endif /* SOURCE_FILESYSTEM_H_ */
