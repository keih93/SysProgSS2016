/*
 * Symboltable.cpp
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#include "../includes/Symboltable.h"
#include "../includes/StringTab.h"
#include "../includes/SymtabEntry.h"

Symboltable::Symboltable() {
	this->table = new StringTab();
	//this->sym = new SymtabEntry[512];
	 this->sym = new SymtabEntry[512];

}

char* Symboltable::insert(char* lexem){

}

int Symboltable::hashFunc(char* lexem){

}

Symboltable::~Symboltable() {
	// TODO Auto-generated destructor stub
}
