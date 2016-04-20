/*
 * Token.h
 *
 *  Created on: Apr 13, 2016
 *      Author: ngng1012
 */

#ifndef SCANNER_INCLUDES_TOKEN_H_
#define SCANNER_INCLUDES_TOKEN_H_


enum TokenType {
	ze_ro,
	Identifier,
	Integer,
	Assign,
	EqualSemicolonEqual,
	Equal,
	Plus,
	SquareBracket,
	Parentheses,
	Braces,
	Chevrons,
	Colon,
	Minus,
	Star,
	ExclamationMark,
	Semicolon,
	And,
	Error
};

class Token {
private:
	TokenType type;
	int line;
	int column;
	char* infokey;
	int value;

public:
	Token();
	Token(TokenType tokent, int l, int c, char* info);
	Token(TokenType tokent, int l, int c, int value);
	virtual ~Token();
};

#endif /* SCANNER_INCLUDES_TOKEN_H_ */
