/*
 * Token.cpp
 *
 *  Created on: Apr 13, 2016
 *      Author: ngng1012
 */
#include "../includes/Token.h"
#include <iostream>
#include "string.h"

Token::Token(TokenType tokent, int l, int c, char* info) {
	this->column = c;
	this->line = l;
	this->type = tokent;
	this->infokey = info;
	this->value = -1;
}

Token::Token(TokenType tokent, int l, int c, int value) {
	this->column = c;
	this->line = l;
	this->type = tokent;
	//this->infokey = [' ','\0'];
	this->value = value;
}

Token::~Token() {

}

void Token::printToken() {
	std::cout << "Line: " << this->line << '\n';
	std::cout << "Column: " << this->column << '\n';
	std::cout << "Type: " << this->type << '\n';
	if (this->value != -1) {
		std::cout << "Value: " << this->value << '\n' << '\n';
	} else {
		std::cout << "Lexem: " << this->infokey << '\n' << '\n';
	}
}

