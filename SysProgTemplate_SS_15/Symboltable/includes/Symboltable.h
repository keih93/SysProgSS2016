/*
 * Symboltable.h
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#ifndef SYMBOLTABLE_H_
#define SYMBOLTABLE_H_
#include "Information.h"
#include "StringTab.h"
#include "SymtabEntry.h"

class Symboltable {
public:
	Symboltable();
	~Symboltable();
	char* insert(char* lexem);
	int hashFunc(char* lexem);
private:
	char* typ;
	SymtabEntry* sym[];
	StringTab* table;
	Information* lookup(char* key);
	bool compareLexem(char* lexem1, char* lexem2);
};

#endif /* SYMBOLTABLE_H_ */
