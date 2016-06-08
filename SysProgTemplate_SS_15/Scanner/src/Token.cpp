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
	this->infokey = new char[100];
	this->value = value;
}

Token::~Token() {

}

void Token::printToken() {
	std::cout << "Line: " << this->line << ' ';
	std::cout << "Column: " << this->column << ' ';
	switch (this->type) {
	case 1:
		std::cout << "Type: " << "\"Sign\"" << ' ';
		break;
	case 2:
		std::cout << "Type: " << "\"Identifier\"" << ' ';
		break;
	case 3:
		std::cout << "Type: " << "\"Integer\"" << ' ';
		break;
	case 4:
		std::cout << "Type: " << "\"Assign\"" << ' ';
		break;
	case 5:
		std::cout << "Type: " << "\"EqualColonEqual\"" << ' ';
		break;
	case 6:
		std::cout << "Type: " << "\"Equal\"" << ' ';
		break;
	case 7:
		std::cout << "Type: " << "\"Plus\"" << ' ';
		break;
	case 8:
		std::cout << "Type: " << "\"SquareBracketLEFT\"" << ' ';
		break;
	case 9:
		std::cout << "Type: " << "\"SquareBracketRIGHT\"" << ' ';
		break;
	case 10:
		std::cout << "Type: " << "\"ParenthesesLEFT\"" << ' ';
		break;
	case 11:
		std::cout << "Type: " << "\"ParenthesesRIGHT\"" << ' ';
		break;
	case 12:
		std::cout << "Type: " << "\"BracesLEFT\"" << ' ';
		break;
	case 13:
		std::cout << "Type: " << "\"BracesRIGHT\"" << ' ';
		break;
	case 14:
		std::cout << "Type: " << "\"InequalitySignLEFT\"" << ' ';
		break;
	case 15:
		std::cout << "Type: " << "\"InequalitySignRIGHT\"" << ' ';
		break;
	case 16:
		std::cout << "Type: " << "\"Colon\"" << ' ';
		break;
	case 17:
		std::cout << "Type: " << "\"Minus\"" << ' ';
		break;
	case 18:
		std::cout << "Type: " << "\"Star\"" << ' ';
		break;
	case 19:
		std::cout << "Type: " << "\"ExclamationMark\"" << ' ';
		break;
	case 20:
		std::cout << "Type: " << "\"Semicolon\"" << ' ';
		break;
	case 21:
		std::cout << "Type: " << "\"And\"" << ' ';
		break;
	case 22:
		std::cout << "Type: " << "\"Error\"" << ' ';
		break;
	}
	if (this->value != -1) {
		std::cout << "Value: " << this->value << '\n' << '\n';
	} else {
		std::cout << "Lexem: " << this->infokey << '\n' << '\n';
	}
}

