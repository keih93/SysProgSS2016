/*
 * SymtabEntry.cpp
 *
 *  Created on: May 15, 2016
 *      Author: quang
 */
#include "../includes/SymtabEntry.h"
#include "../includes/Symboltable.h"
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

SymtabEntry::SymtabEntry() {
	this->info = new Info();
	this->next = NULL;
}

void SymtabEntry::setInfo(char* name, TokenType typ){
	this->info->setName(name);
	this->info->setTyp(typ);
}

Info* SymtabEntry::getInfo() {
	return this->info;
}

void SymtabEntry::setNext(SymtabEntry* entry){
	this->next = entry;
}

SymtabEntry* SymtabEntry::getNext() {
	return this->next;
}

