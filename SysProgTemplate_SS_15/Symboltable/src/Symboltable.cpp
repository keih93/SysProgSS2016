/*
 * Symboltable.cpp
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#include "../includes/Symboltable.h"
#include "../includes/StringTab.h"
#include "../includes/SymtabEntry.h"
#include <stdio.h>

Symboltable::Symboltable() {
	this->table = new StringTab();
	this->typ = NOTYP;

}

void Symboltable::initSymbols() {
	this->typ = TOKENWHILE;
	char* firsttyp = new char[5];
	firsttyp[0] = 'w';
	firsttyp[1] = 'h';
	firsttyp[2] = 'i';
	firsttyp[3] = 'l';
	firsttyp[4] = 'e';
	char* sectyp = new char[5];
	sectyp[0] = 'W';
	sectyp[1] = 'H';
	sectyp[2] = 'I';
	sectyp[3] = 'L';
	sectyp[4] = 'E';
	insert(firsttyp);
	insert(sectyp);
	this->typ = TOKENIF;
	char* thirdtyp = new char[2];
	thirdtyp[0] = 'i';
	thirdtyp[1] = 'f';
	char* fourthtyp = new char[2];
	fourthtyp[0] = 'I';
	fourthtyp[1] = 'F';
	insert(thirdtyp);
	insert (fourthtyp);
}

char* Symboltable::insert(char* lexem) {
	char* node = NULL;
	int count = countsize(lexem);
	if (isTyp(lexem, count)) {
		this->typ = INT;
	} else {
		if (lookup(lexem) == NULL) {
			node = this->table->insert(lexem, count);
			SymtabEntry* ele = new SymtabEntry();
			ele->setInfo(lexem, this->typ);
			sym[hashFunc(lexem)] = ele;
		} else {
			node = lookup(lexem)->getName();
		}
	}
	return node;
}

Info* Symboltable::lookup(char* key) {
	int index = hashFunc(key);
	SymtabEntry* element = sym[index];
	while (element != NULL) {
		if (!element->getInfo()->compareLex(key)) {
			element = element->getNext();
		} else {
			return element->getInfo();
		}
	}
	return NULL;
}

int Symboltable::countsize(char* lexem) {
	char* temp = lexem;
	int count = 0;
	while (temp[0] != '\0') {
		count++;
		temp++;
	}
	return count;
}

bool Symboltable::isTyp(char* lexem, int count) {
	char* typ = new char[4];
	typ[0] = 'i';
	typ[1] = 'n';
	typ[2] = 't';
	for (int i = 0; i < 3; i++) {
		if (lexem[i] != typ[i]) {
			return false;
		}
	}
	if (lexem[3] == '\0') {
		return true;
	}
	return false;
}

int Symboltable::hashFunc(char* lexem) {
	int first = lexem[0];
	int second = lexem[1];
	int last = lexem[2];
	return (first + second + last);
}

Symboltable::~Symboltable() {
// TODO Auto-generated destructor stub
}
