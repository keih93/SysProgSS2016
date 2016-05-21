/*
 * StringTab.cpp
 *
 *  Created on: May 15, 2016
 *      Author: quang
 */
#include "../includes/StringTab.h"
#include "string.h"

StringTab::StringTab(){
	this->freeSpace = 0;
	this->freeP = new char();
	node = new StringTabNode();
}

char* StringTab::insert(char* lexem, int size) {
	char* tmp = this->freeP;
	if (size < this->freeSpace) {
		memcpy(this->freeP, lexem, size + 1);
		this->freeP[size] = '\0';
		this->freeP += size + 1;
		this->freeSpace -= size + 1;
	} else { /* todo */
	}
	return tmp;
}

