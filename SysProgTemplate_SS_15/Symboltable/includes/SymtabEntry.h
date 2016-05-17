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
	SymtabEntry(char* name, char* typ);
	Info* getInfo();
	Info* creatInfo();
	Information* intInfo;
private:
	Info* info;
};



#endif /* SYMBOLTABLE_INCLUDES_SYMTABENTRY_H_ */
