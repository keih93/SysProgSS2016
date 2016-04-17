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
public:
	Token();
	Token(TokenType tokent, int l, int c);
	virtual ~Token();
};




#endif /* SCANNER_INCLUDES_TOKEN_H_ */
