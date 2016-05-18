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
	//this->sym = new SymtabEntry[512];
	this->typ = NULL;

}

char* Symboltable::insert(char* lexem) {
	char* i = new char[3];
	i[0] = 'i';
	i[1] = 'n';
	i[2] = 't';
	char* node = NULL;
	if (compareLexem(i, lexem)) {
		this->typ = i;
	} else {
		if (!this->sym[hashFunc(lexem)]->intInfo->compareLex(lexem)) {
			node = this->table->insert(lexem, countsize(lexem));
			this->sym[hashFunc(lexem)] = new SymtabEntry(node, typ);
		}
		else{
			node = this->sym[hashFunc(lexem)]->getInfo()->getName();
		}
	}
return node;
}

int countsize(char* lexem) {
	char* temp = lexem;
	int count;
	while (temp != '\0') {
		count++;
		temp++;
	}
	return count;
}

bool Symboltable::compareLexem(char* lexem1, char* lexem2) {
	char* temp1 = lexem1;
	char* temp2 = lexem2;
	while (temp1 != '\0' && temp2 != '\0') {
		if (temp1 != temp2) {
			return false;
		}
		temp1++;
		temp2++;
	}
	if (temp1 == temp2) {
		return true;
	}
	return false;
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
