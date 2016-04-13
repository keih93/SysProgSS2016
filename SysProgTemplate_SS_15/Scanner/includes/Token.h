/*
 * Token.h
 *
 *  Created on: Apr 13, 2016
 *      Author: ngng1012
 */

#ifndef SCANNER_INCLUDES_TOKEN_H_
#define SCANNER_INCLUDES_TOKEN_H_

enum TokenType {
	Identifier,
	Integer,
	Assign,
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
};

class Token {
private:
	TokenType type;
	int line;
	int column;
	Token(int line, int column, TokenType type);
	virtual ~Token();
};




#endif /* SCANNER_INCLUDES_TOKEN_H_ */
