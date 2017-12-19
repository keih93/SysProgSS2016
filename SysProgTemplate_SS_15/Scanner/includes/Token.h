/*
 * Token.h
 *
 *  Created on: Apr 13, 2016
 *      Author: ngng1012
 */

#ifndef SCANNER_INCLUDES_TOKEN_H_
#define SCANNER_INCLUDES_TOKEN_H_

#include <fstream>
#include "../../Symboltable/includes/SymtabEntry.h"

class Token {
private:
	TokenType type;
	int line;
	int column;
	char* infokey;
	int value;
	SymtabEntry* entry;

public:
	Token();
	void printToken(std::ofstream& out);
	char* getType();
	Token(TokenType tokent, int l, int c, char* info);
	Token(TokenType tokent, int l, int c, int value);
	Token(TokenType tokent, int l, int c, SymtabEntry* entry);
	char* typeToString(TokenType typ);
	virtual ~Token();
};

#endif /* SCANNER_INCLUDES_TOKEN_H_ */
