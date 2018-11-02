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
	SymtabEntry* insert(char* lexem, TokenType typ, bool squareBracketfound);
	SymtabEntry* find(char* lexem, TokenType typ);
	int hashFunc(char* lexem);
	void initSymbols();
	bool contains(char* key);
private:
	SymtabEntry* sym[4096];
	StringTab* table;
	Info* lookup(char* key, TokenType typ);
	bool compareLexem(char* lexem1, char* lexem2);
	int length(char *lexem);
	int countsize(char* lexem);
	bool isTyp(char* lexem, int count);
	bool isNoKeyword(char* lexem);
};

#endif /* SYMBOLTABLE_H_ */
