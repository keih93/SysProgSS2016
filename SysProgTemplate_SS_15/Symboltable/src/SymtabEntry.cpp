/*
 * SymtabEntry.cpp
 *
 *  Created on: May 15, 2016
 *      Author: quang
 */
#include "../includes/SymtabEntry.h"
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

SymtabEntry::SymtabEntry(char* name, char* typ) {
	this->info = new Info(name, typ);
	this->intInfo = new Information();
	this->next = new SymtabEntry();
}

void SymtabEntry::setInfo(char* name, char* typ){
	this->info->setName(name);
	this->info->setTyp(typ);
}

Info* SymtabEntry::getInfo() {
	return this->info;
}


SymtabEntry* SymtabEntry::getNext() {
	return this->next;
}

