/*
 * Parser.cpp
 *
 *  Created on: Dec 6, 2017
 *      Author: Quang
 */

#include "../includes/Parser.h"

Parser::~Parser() {
}

Parser::Parser(Scanner* scan) {
	this->scanner = scan;
	this->tok = this->scanner->nextToken();
}

void Parser::nextToken() {
	this->tok = this->scanner->nextToken();
}

int Parser::isPROG() {

	return 0;
}

int Parser::isDECLS() {
	while (this->tok->gettype() != Semicolon) {
		if (!this->isDECL()) {
			return 0;
		}
	}
	return 0;
}

int Parser::isSTATEMENTS() {
	if (this->isSTATEMENT()) {
		return 1;
	}
	return 0;
}

int Parser::isSTATEMENT() {
	return 0;
}
int Parser::isDECL() {

	return 0;
}

int Parser::isEXP() {
	return 0;
}

int Parser::isOP() {
//	if(accept(type));
//			return 1;
	return 0;
}

int Parser::accept(TokenType T) {
	if (this->tok->gettype() == T) {
		nextToken();
		return 1;
	}
	return 0;
}

int Parser::expect(TokenType T) {
	if (accept(T))
		return 1;
	return 0;
}

