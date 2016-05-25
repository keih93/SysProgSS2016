/*
 * SymtabEntry.h
 *
 *  Created on: May 12, 2016
 *      Author: quang
 */

#ifndef SYMBOLTABLE_INCLUDES_SYMTABENTRY_H_
#define SYMBOLTABLE_INCLUDES_SYMTABENTRY_H_
#include "Information.h"

class SymtabEntry{
public:
	SymtabEntry();
	SymtabEntry(char* name, char* typ);
	void setInfo(char* name, char* typ);
	Info* getInfo();
	SymtabEntry* getNext();
	Info* creatInfo();
private:
	Info* info;
	SymtabEntry* next;
};



#endif /* SYMBOLTABLE_INCLUDES_SYMTABENTRY_H_ */
