/*
 * Symboltable.h
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */
#include "Information.h"
#include "StringTab.h"
#include "SymtabEntry.h"
#ifndef SYMBOLTABLE_H_
#define SYMBOLTABLE_H_

class Symboltable {
public:
	char* insert(char* lexem);

private:
	SymtabEntry* sym;
	StringTab* table;
	Information* lookup(char* key);


};

#endif /* SYMBOLTABLE_H_ */
