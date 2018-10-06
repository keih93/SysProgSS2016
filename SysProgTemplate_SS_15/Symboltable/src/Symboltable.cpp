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
#include <stdexcept>
#include <string.h>

Symboltable::Symboltable() {
	this->table = new StringTab();
	initSymbols();
}

void Symboltable::initSymbols() {

	char* firsttyp = new char[6];
	firsttyp[0] = 'w';
	firsttyp[1] = 'h';
	firsttyp[2] = 'i';
	firsttyp[3] = 'l';
	firsttyp[4] = 'e';
	firsttyp[5] = '\0';
	char* sectyp = new char[6];
	sectyp[0] = 'W';
	sectyp[1] = 'H';
	sectyp[2] = 'I';
	sectyp[3] = 'L';
	sectyp[4] = 'E';
	sectyp[5] = '\0';
	insert(firsttyp, KeywordWHILE, false);
	insert(sectyp, KeywordWHILE, false);

	char* thirdtyp = new char[3];
	thirdtyp[0] = 'i';
	thirdtyp[1] = 'f';
	thirdtyp[2] = '\0';
	char* fourthtyp = new char[3];
	fourthtyp[0] = 'I';
	fourthtyp[1] = 'F';
	fourthtyp[2] = '\0';
	insert(thirdtyp, KeywordIF, false);
	insert(fourthtyp, KeywordIF, false);

	char* elseOneTyp = new char[5];
	elseOneTyp[0] = 'e';
	elseOneTyp[1] = 'l';
	elseOneTyp[2] = 's';
	elseOneTyp[3] = 'e';
	elseOneTyp[4] = '\0';
	char* elseTwoTyp = new char[5];
	elseTwoTyp[0] = 'E';
	elseTwoTyp[1] = 'L';
	elseTwoTyp[2] = 'S';
	elseTwoTyp[3] = 'E';
	elseTwoTyp[4] = '\0';
	insert(elseOneTyp, KeywordELSE, false);
	insert(elseTwoTyp, KeywordELSE, false);

	char* readTyp = new char[5];
	readTyp[0] = 'r';
	readTyp[1] = 'e';
	readTyp[2] = 'a';
	readTyp[3] = 'd';
	readTyp[4] = '\0';
	char* writeTyp = new char[6];
	writeTyp[0] = 'w';
	writeTyp[1] = 'r';
	writeTyp[2] = 'i';
	writeTyp[3] = 't';
	writeTyp[4] = 'e';
	writeTyp[5] = '\0';
	insert(readTyp, KeywordREAD, false);
	insert(writeTyp, KeywordWRITE, false);

	char* intTyp = new char[6];
	intTyp[0] = 'i';
	intTyp[1] = 'n';
	intTyp[2] = 't';
	intTyp[3] = '\0';
	insert(intTyp, KeywordINT, false);

}

SymtabEntry* Symboltable::insert(char* lexem, TokenType typ,
		bool squareBracketfound) {
	int index = hashFunc(lexem);
	int count = countsize(lexem);
	SymtabEntry* element = sym[index];
	if (element == NULL) {
		char* key = this->table->insert(lexem, count);
		element = new SymtabEntry();
		element->setInfo(key, typ);
		sym[index] = element;
		element->isArray = false;
		if (squareBracketfound) {
			element->isArray = true;
		}
		return element;
	} else {
		if (isNoKeyword(lexem)) {
			fprintf(stderr, "\nDuplicate Variable: %s\n", lexem);
			throw std::logic_error("duplicate Identifier");
		}
	}
	return NULL; //this can not happen
}

SymtabEntry* Symboltable::find(char* lexem, TokenType typ) {
	int index = hashFunc(lexem);
	int count = countsize(lexem);
	SymtabEntry* element = sym[index];
	if (NULL == element) {
		fprintf(stderr, "\nIdentifier not defined: %s\n", lexem);
		throw std::logic_error("Identifier not defined");
	}
	SymtabEntry* temp = element;
	while (element != NULL) {
		if (!element->getInfo()->compareLex(lexem)) {
			element = element->getNext();
		} else {
			return element;
		}
	}
	char* key = this->table->insert(lexem, count);
	element = new SymtabEntry();
	element->setInfo(key, typ);
	temp->setNext(element);
	return element;
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

int Symboltable::hashFunc(char* lexem) {
	int first = lexem[0];
	int second = lexem[1];
	int last = lexem[2];
	return (first + second + last);
}

bool Symboltable::isNoKeyword(char* lexem) {
	if (strcmp(lexem, "int") != 0 && strcmp(lexem, "while") != 0
			&& strcmp(lexem, "if") != 0 && strcmp(lexem, "read") != 0
			&& strcmp(lexem, "write") != 0 && strcmp(lexem, "WHILE") != 0
			&& strcmp(lexem, "IF") != 0 && strcmp(lexem, "else") != 0
			&& strcmp(lexem, "ELSE") != 0) {
		return true;
	}
	return false;
}

bool Symboltable::contains(char* lexem) {
	int index = hashFunc(lexem);
	SymtabEntry* element = sym[index];
	if (element == NULL) {
		return false;
	}
	return true;
}

Symboltable::~Symboltable() {
}
