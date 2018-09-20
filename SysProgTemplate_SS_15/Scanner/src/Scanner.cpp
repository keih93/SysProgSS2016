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
#include <stdexcept>

Scanner::~Scanner() {
}

Scanner::Scanner(Buffer* bufe, Symboltable* symboltable) {
	this->stopp = 0;
	this->sym = symboltable;
	this->sym->initSymbols();
	this->buf = bufe;
	this->automat = new Automat(this);
	this->buffer = new char[100];
	this->pointer = 0; //steht auf dem nächsten zu verarbeitenden Zeichen
	this->end = 0; //rechtes Ende der zu verarbeitenden Zeichen
	squareBracketRightFound = false;
	identifierIsArray = false;
}

void Scanner::stop() {
	this->stopp = 1;
}

int Scanner::getStop() {
	return this->stopp;
}

Token* Scanner::mkToken(TokenType t, int l, int c, char* info) { //Token für einen Identifier oder ein fehlerhaftes Zeichen erzeugen
	return new Token(t, l, c, info);
}

Token* Scanner::mkToken(TokenType t, int l, int c, int value) { //Token für einen Integer erzeugen
	return new Token(t, l, c, value);
}

Token* Scanner::mkToken(TokenType t, int l, int c, SymtabEntry* entry) { //Token für einen Identifier oder ein fehlerhaftes Zeichen erzeugen
	return new Token(t, l, c, entry);
}

Token* Scanner::nextToken(bool isDecl) {
	int tokenfound = 0;
	char c;
	while (tokenfound == 0) {
		if (pointer == end) { //neues Zeichen einlesen
			buffer[end] = buf->getchar(); //end of char behandeln
			end++;
		}
		c = buffer[pointer]; //nächstes Zeichen verarbeiten
		pointer++;
		tokenfound = automat->handleChar(c);
		if (this->getStop() == 1) {
			return NULL;
		}
	}

	TokenType type = automat->getTokenType();
	int line = automat->getLine();
	int column = automat->getColumn();
	int val = automat->getValue();
	//nur im Fall von einem Identifier, Integer, Zeichen oder Fehler wird ein Token erzeugt

	if (type == ze_ro) {
		// erkanntes Token überschreiben --> überlesen
		this->copyChar();
		return this->nextToken(isDecl);
	} else if (type == Integer) { //Token für einen Integer
		this->copyChar();
		return this->mkToken(type, line, column, val);
	} else {
		char* templexem = new char[pointer];
		templexem = mkLexem();
		if (!isDecl) {
			if (identifierIsArray) {
				if (strcmp(templexem, "[") != 0) {
					fprintf(stderr, "\nIncompatible Types: Identifier is an array. Line: %d Column: %d.\n", line,column);
					throw std::logic_error("Incompatible Types");
				}
			} else {
				if (strcmp(templexem, "[") == 0) {
					fprintf(stderr, "\nIncompatible Types: Identifier is not an array. Line: %d Column: %d.\n", line,column);
					throw std::logic_error("Incompatible Types");
				}
			}
		}
		identifierIsArray = false;
		if (strcmp(templexem, "]") == 0) {
			squareBracketRightFound = true;
		}
		if (type == Identifier) {
			SymtabEntry* entry;
			if (isDecl) {
				entry = this->sym->insert(templexem, type,
						squareBracketRightFound);
				squareBracketRightFound = false;
				type = entry->getInfo()->getTyp();
			} else {
				entry = this->sym->find(templexem, type);
				type = entry->getInfo()->getTyp();
				if (entry->isArray) {
					identifierIsArray = true;
				}
			}
			return this->mkToken(type, line, column, entry); //Token für einen Identifier
		}
		return this->mkToken(type, line, column, templexem); //Token für einen Zeichen oder Fehlertoken
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

