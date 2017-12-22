/*
 * Parser.cpp
 *
 *  Created on: Dec 6, 2017
 *      Author: Quang
 */

#include "../includes/Parser.h"
#include "../../Scanner/includes/Scanner.h"
#include "../../Scanner/includes/Token.h"

Parser::~Parser() {
}

Parser::Parser(Scanner* scan) {
	this->scanner = scan;
	this->tok = scan->nextToken();
}

void Parser::switchtoken(){
	this->tok = this->scanner->nextToken();
}

int Parser::isPROG() {
	if ((this->isDECLS() && this->isSTATEMENTS()) | this->isSTATEMENTS()) {
		return 1;
	}
	return 0;
}

int Parser::isDECLS() {
	if (this->isDECL()) {
		return 1;
	}
	if (this->tok == NULL)
		return 1;
	return 0;
}

int Parser::isSTATEMENTS() {
	if (this->isSTATEMENT()) {
		return 1;
	}
	return 0;
}

int Parser::isSTATEMENT(){
	return 0;
}
int Parser::isDECL() {
	if (this->tok->gettype() == 'int') { //switch later for enum number
		this->switchtoken(); //next token
		if (this->isARRAY()) {
			this->switchtoken();
			if (this->tok->gettype() == 'Identifier') {
				return 1;
			}
		}
		if (this->scanner->nextToken()->gettype() == 'Identifier') {
			return 1;
		}
	}
	return 0;
}

int Parser::isARRAY() {
	if (this->tok->gettype() == 'sign[') {
		this->switchtoken();
		if (this->tok->gettype() == 'Integer') {
			this->switchtoken();
			if (this->tok->gettype() == 'sign]') {
				return 1;
			}
		}
	}
	return 0;
}

int Parser::isEXP(){
	return 0;
}

int Parser::isIndex(){
	return 0;
}

int Parser::isEXP2(){
	return 0;
}

int Parser::isOP(){
	return 0;
}

int Parser::isOP_EXP(){
	return 0;
}





