/*
 * StringTab.h
 *
 *  Created on: May 12, 2016
 *      Author: quang
 */

#ifndef SYMBOLTABLE_INCLUDES_STRINGTAB_H_
#define SYMBOLTABLE_INCLUDES_STRINGTAB_H_
#include "StringTabNode.h"

class StringTab {
public:
	StringTab();
	char* insert(char* lexem, int size);
private:
	char* freeP;
	int freeSpace;
	StringTabNode* node;
};

#endif /* SYMBOLTABLE_INCLUDES_STRINGTAB_H_ */
