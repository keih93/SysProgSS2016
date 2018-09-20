/*
 * Token.cpp
 *
 *  Created on: Apr 13, 2016
 *      Author: ngng1012
 */
#include "../includes/Token.h"
#include <fstream>
#include "string.h"

Token::Token(TokenType tokent, int l, int c, char* info) {
	this->column = c;
	this->line = l;
	this->type = tokent;
	this->infokey = info;
	this->value = -1;
	this->entry = NULL;
}

Token::Token(TokenType tokent, int l, int c, int value) {
	this->column = c;
	this->line = l;
	this->type = tokent;
	this->infokey = new char[100];
	this->value = value;
	this->entry = NULL;
}

Token::Token(TokenType tokent, int l, int c, SymtabEntry* entry) {
	this->column = c;
	this->line = l;
	this->type = tokent;
	this->infokey = entry->getInfo()->getName();
	this->value = -1;
	this->entry = entry;
}

Token::~Token() {
	delete this->entry;
}

void Token::printToken(std::ofstream& out) {
	out << "Line: " << this->line << ' ';
	out << "Column: " << this->column << ' ';
	switch (this->type) {
	case 1:
		out << "Type: " << "\"Sign\"" << ' ';
		break;
	case 2:
		out << "Type: " << "\"Identifier\"" << ' ';
		break;
	case 3:
		out << "Type: " << "\"Integer\"" << ' ';
		break;
	case 4:
		out << "Type: " << "\"Assign\"" << ' ';
		break;
	case 5:
		out << "Type: " << "\"EqualColonEqual\"" << ' ';
		break;
	case 6:
		out << "Type: " << "\"Equal\"" << ' ';
		break;
	case 7:
		out << "Type: " << "\"Plus\"" << ' ';
		break;
	case 8:
		out << "Type: " << "\"SquareBracketLEFT\"" << ' ';
		break;
	case 9:
		out << "Type: " << "\"SquareBracketRIGHT\"" << ' ';
		break;
	case 10:
		out << "Type: " << "\"ParenthesesLEFT\"" << ' ';
		break;
	case 11:
		out << "Type: " << "\"ParenthesesRIGHT\"" << ' ';
		break;
	case 12:
		out << "Type: " << "\"BracesLEFT\"" << ' ';
		break;
	case 13:
		out << "Type: " << "\"BracesRIGHT\"" << ' ';
		break;
	case 14:
		out << "Type: " << "\"InequalitySignLEFT\"" << ' ';
		break;
	case 15:
		out << "Type: " << "\"InequalitySignRIGHT\"" << ' ';
		break;
	case 16:
		out << "Type: " << "\"Colon\"" << ' ';
		break;
	case 17:
		out << "Type: " << "\"Minus\"" << ' ';
		break;
	case 18:
		out << "Type: " << "\"Star\"" << ' ';
		break;
	case 19:
		out << "Type: " << "\"ExclamationMark\"" << ' ';
		break;
	case 20:
		out << "Type: " << "\"Semicolon\"" << ' ';
		break;
	case 21:
		out << "Type: " << "\"And\"" << ' ';
		break;
	case 22:
		out << "Type: " << "\"Keyword: If\"" << ' ';
		break;
	case 23:
		out << "Type: " << "\"Keyword: While\"" << ' ';
		break;
	case 24:
		out << "Type: " << "\"Keyword: Else\"" << ' ';
		break;
	case 25:
		out << "Type: " << "\"Keyword: Read\"" << ' ';
		break;
	case 26:
		out << "Type: " << "\"Keyword: Write\"" << ' ';
		break;
	case 27:
		out << "Type: " << "\"Keyword: Int\"" << ' ';
		break;
	case 28:
		out << "Type: " << "\"Error\"" << ' ';
		break;
	}
	if (this->value == -2) {
		out << "Value: invalid number" << '\n' << '\n';
	} else if (this->value != -1) {
		out << "Value: " << this->value << '\n' << '\n';
	} else {
		out << "Lexem: " << this->infokey << '\n' << '\n';
	}
	out.flush();

}

int Token::getLine() {
	return this->line;
}

int Token::getColumn() {
	return this->column;
}

int Token::getValue() {
	return this->value;
}

char* Token::getInfokey() {
	return this->infokey;
}

TokenType Token::gettype() {
	return this->type;
}
