/*
 * Scanner.cpp
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#include "../includes/Scanner.h"
#include "../includes/Token.h"
#include "../../Automat/includes/Automat.h"
#include "../../Buffer/includes/Buffer.h"

Scanner::~Scanner() {
	// TODO Auto-generated destructor stub
}

Scanner::Scanner() {
	buf = new Buffer("test.txt");
	automat = new Automat(this);
	//posix_memalign((void**) &buffer, 512, 512);
	pointer = 0;
}

void Scanner::stop(){

}

Token* Scanner::mkToken(TokenType t, int l, int c, char* info) {
	return new Token(t, l, c, info);
}

Token* Scanner::mkToken(TokenType t, int l, int c, int value) {
	return new Token(t, l, c, value);
}

Token* Scanner::nextToken() {
	int tokenfound = 0;
	Token* t;
	pointer = 0;
	while (tokenfound == 0) {
		char c = buf->getchar();
		buffer[pointer] = c;
		pointer++;
		tokenfound = automat->handleChar(c);
	}
	TokenType type = automat->getTokenType();
	int line = automat->getLine();
	int column = automat->getColumn();
	int val = automat->getValue();
	if (val == -1) {
		t = this->mkToken(type, line, column, mkLexem());
	} else {
		t = this->mkToken(type, line, column, val);
	}
	return t;
}

char* Scanner::mkLexem() {
	char* lex = new char[pointer + 1];
	for (int i = 0; i < pointer + 1; i++) {
		lex[i] = buffer[i];
	}
	char* tempbuffer = new char[4];
		for(int i = pointer; i < pointer; i++ );

	return lex;
}

void Scanner::ungetChar(int i) {
	this->pointer = this->pointer - i;
}
