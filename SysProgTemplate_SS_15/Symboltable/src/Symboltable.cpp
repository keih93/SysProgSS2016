/*
 * Symboltable.cpp
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#include "../includes/Symboltable.h"
#include "../includes/StringTab.h"
#include "../includes/SymtabEntry.h"
#include "stdio.h"

Symboltable::Symboltable() {
	this->table = new StringTab();
	this->typ = NULL;
}

char* Symboltable::insert(char* lexem) {
	char* node = NULL;
	if (isTyp(lexem)) {
		this->typ = lexem;
	} else {
		int count = countsize(lexem);
		SymtabEntry* element = this->sym[hashFunc(lexem)];
		if (element->intInfo->compareLex(lexem)) {
			node = this->table->insert(lexem, count);
			element = new SymtabEntry(node, typ);
		} else {
			node = lookup(lexem);
		}
	}
	return node;
}

Information* Symboltable::lookup(char* key){
	SymtabEntry* element = SymtabEntry[hashFunc(key)];
	if(element != NULL){
		return NULL;
	}
	return element->getInfo();
}

int Symboltable::countsize(char* lexem) {
	char* temp = lexem;
	int count;
	while (temp != '\0') {
		count++;
		temp++;
	}
	return count;
}

int Symboltable::hashFunc(char* lexem) {
	int first = lexem[0];
	int second = lexem[1];
	int last = lexem[2];
	return (first + second + last) - (65 * 3);
}

Symboltable::~Symboltable() {
	// TODO Auto-generated destructor stub
}
