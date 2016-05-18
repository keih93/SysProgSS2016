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
}

Info* SymtabEntry::getInfo() {
	return this->info;
}

