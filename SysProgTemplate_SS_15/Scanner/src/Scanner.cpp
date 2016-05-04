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

Scanner::~Scanner() {}

Scanner::Scanner(Buffer* bufe) {
	buf = bufe;
	automat = new Automat(this);
	buffer = new char[100];
	pointer = 0; //steht auf dem nächsten zu verarbeitenden Zeichen
	end = 0; //rechtes Ende der zu verarbeitenden Zeichen
}

void Scanner::stop() {
	//return 1;
}

Token* Scanner::mkToken(TokenType t, int l, int c, char* info) { //Token für einen Identifier oder ein fehlerhaftes Zeichen erzeugen
	return new Token(t, l, c, info);
}

Token* Scanner::mkToken(TokenType t, int l, int c, int value) { //Token für einen Integer erzeugen
	return new Token(t, l, c, value);
}

Token* Scanner::nextToken() {
	int tokenfound = 0;
	char c;
	while (tokenfound == 0) {
		if (pointer == end) { //neues Zeichen einlesen
			buffer[end] = buf->getchar();
			end++;
		}
		c = buffer[pointer]; //nächstes Zeichen verarbeiten
		pointer++;
		tokenfound = automat->handleChar(c);
	}
	TokenType type = automat->getTokenType();
	int line = automat->getLine();
	int column = automat->getColumn();
	int val = automat->getValue();
	if (type == ze_ro) {
		// erkanntes Token überschreiben --> überlesen
		this->copyChar();
		return this->nextToken();
	} else if (type == Integer) { //Token für einen Integer
		this->copyChar();
		return this->mkToken(type, line, column, val);
	} else {
		//nur im Fall von einem Identifier, Integer oder Fehler wird ein Token erzeugt
		return this->mkToken(type, line, column, mkLexem()); //Token für einen Identifier oder Fehlertoken
	}
}

char* Scanner::mkLexem() {
	char* lex;
	lex = new char[pointer];
	for (int i = 0; i < pointer; i++) {
		lex[i] = buffer[i];
	}
	this->copyChar();
	return lex;
}

void Scanner::ungetChar(int i) {
	this->pointer = this->pointer - i;
}

void Scanner::copyChar() {
	int i = 0;
	int temp = pointer;
	while (temp < end) {
		buffer[i] = buffer[temp];
		temp++;
		i++;
	}
	end = i;
	pointer = 0;
}
