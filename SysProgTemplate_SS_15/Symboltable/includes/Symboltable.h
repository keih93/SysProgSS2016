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
	void initSymbols();
private:
	Typ typ;
	SymtabEntry* sym[512];
	StringTab* table;
	Info* lookup(char* key);
	bool compareLexem(char* lexem1, char* lexem2);
	int countsize(char* lexem);
	bool isTyp(char* lexem, int count);

};

#endif /* SYMBOLTABLE_H_ */
