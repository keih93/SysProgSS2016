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
	Info getInfo();
	Info creatInfo(char* name, char* typ);
	Information intInfo;
private:
	Info info;
};



#endif /* SYMBOLTABLE_INCLUDES_SYMTABENTRY_H_ */
