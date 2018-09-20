/*
 * Scanner.h
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#ifndef SCANNER_H_
#define SCANNER_H_
#include "Token.h"
#include "IScanner.h"
#include "../../Automat/includes/Automat.h"
#include "../../Buffer/includes/Buffer.h"
#include "../../Symboltable/includes/Symboltable.h"


class Scanner :public IScanner {
private:
	Buffer* buf;
	Automat* automat;
	char* buffer;
	int pointer;
	char* mkLexem();
	int end;
	int stopp;
public:
	Symboltable* sym;
	Scanner(Buffer* bufe, Symboltable* sym);
	virtual ~Scanner();
	Token* nextToken(bool isDecl);
	void freeToken(Token token);
	Token* mkToken(TokenType t, int l, int c, char* info);
	Token* mkToken(TokenType tokent, int l, int c, int value);
	Token* mkToken(TokenType tokent, int l, int c, SymtabEntry* entry);
	void ungetChar(int index);
	void copyChar();
	void stop();
	int getStop();
};

#endif /* SCANNER_H_ */
