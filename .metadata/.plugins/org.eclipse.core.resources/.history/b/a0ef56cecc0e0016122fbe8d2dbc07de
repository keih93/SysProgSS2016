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
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

Scanner::~Scanner() {
}

Scanner::Scanner(Buffer* bufe) {
	buf = bufe;
	automat = new Automat(this);
	buffer = new char[10];
	hasungetc = 0;
	pointer = 0;
	temppointer = 0;
	end = 0;
}

void Scanner::stop() {

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
	char c;
	int i = 0;
	while (tokenfound == 0) {
		if (temppointer == 0) {
			if (end != 0) {
				c = buffer[pointer];
				pointer++;
				if (pointer == end) {
					end = 0;
					pointer = 0;
				}
			} else {
				buffer[pointer] = buf->getchar();
				c = buffer[pointer];
				pointer++;

			}

		} else {
			if (buffer[pointer] != '\0') {
				while (pointer < temppointer || end > pointer) {
					buffer[i] = buffer[pointer];
					pointer++;
					i++;
				}
				if (pointer == temppointer) {
					end = i;
					pointer = 0;
					temppointer = 0;
					c = buffer[pointer];
					pointer++;
					if (pointer == end) {
						end = 0;
					//	pointer = 0;
					}
				}

			}
		}
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
	char* lex = new char[pointer];
	for (int i = 0; i < pointer; i++) {
		lex[i] = buffer[i];
	}

	return lex;
}

void Scanner::ungetChar(int i) {
	this->temppointer = this->pointer;
	this->pointer = this->pointer - i;
}
