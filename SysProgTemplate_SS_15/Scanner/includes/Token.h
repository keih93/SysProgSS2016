/*
 * Token.h
 *
 *  Created on: Apr 13, 2016
 *      Author: ngng1012
 */

#ifndef SCANNER_INCLUDES_TOKEN_H_
#define SCANNER_INCLUDES_TOKEN_H_


enum TokenType {
	ze_ro, //default bzw, Kommentar, was kein Token ist
	Sign, //allgemein
	Identifier,
	Integer,
	Assign, //:=
	EqualColonEqual, //=:=
	Equal, // =
	Plus, // +
	SquareBracket, // [ ]
	Parentheses, // ( )
	Braces,  //  { }
	InequalitySign,  // < >
	Colon,  //:
	Minus,  //-
	Star, //*
	ExclamationMark,  //!
	Semicolon,  //;
	And, //&&
	Error //Fehlertoken
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
	char getType();
	Token(TokenType tokent, int l, int c, char* info);
	Token(TokenType tokent, int l, int c, int value);
	virtual ~Token();
};

#endif /* SCANNER_INCLUDES_TOKEN_H_ */
