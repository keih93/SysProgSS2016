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
#include "../../Symboltable/includes/Symboltable.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

Scanner::~Scanner() {}

Scanner::Scanner(Buffer* bufe, Symboltable* symboltable) {
	this->stopp = 0;
	this->sym = symboltable;
	this->sym->initSymbols();
	this->buf = bufe;
	this->automat = new Automat(this);
	this->buffer = new char[100];
	this->pointer = 0; //steht auf dem nächsten zu verarbeitenden Zeichen
	this->end = 0; //rechtes Ende der zu verarbeitenden Zeichen
}

void Scanner::stop() {
	this->stopp = 1;
}

int Scanner::getStop(){
	return this->stopp;
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
	//nur im Fall von einem Identifier, Integer, Zeichen oder Fehler wird ein Token erzeugt
	if (type == ze_ro) {
		// erkanntes Token überschreiben --> überlesen
		this->copyChar();
		return this->nextToken();
	} else if (type == Integer) { //Token für einen Integer
		this->copyChar();
		return this->mkToken(type, line, column, val);
	} else {
		char* templexem = new char[pointer];
		templexem =	mkLexem();
		if(type == Identifier){
			this->sym->insert(templexem);
			//this->sym->insert(templexem, type);
			//SymtabEntry* entry = this->sym->insert(templexem);
			//type = entry->getType();
			//return this->mkToken(type, line, column, entry);
		}
		return this->mkToken(type, line, column, templexem); //Token für einen Identifier, Zeichen oder Fehlertoken
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
	while (pointer < end) {
		buffer[i] = buffer[pointer];
		pointer++;
		i++;
	}
	end = i;
	pointer = 0;
}
