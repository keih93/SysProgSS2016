/*
 * Token.h
 *
 *  Created on: Apr 13, 2016
 *      Author: ngng1012
 */

#ifndef SCANNER_INCLUDES_TOKEN_H_
#define SCANNER_INCLUDES_TOKEN_H_

#include <fstream>

enum TokenType {
	ze_ro, //default bzw, Kommentar, was kein Token ist
	Sign, //allgemein
	Identifier,
	Integer,
	Assign, //:=
	EqualColonEqual, //=:=
	Equal, // =
	Plus, // +
	SquareBracketLEFT, // [
	SquareBracketRIGHT, // ]
	ParenthesesLEFT, // (
	ParenthesesRIGHT, //  )
	BracesLEFT,  //  {
	BracesRIGHT,  //   }
	InequalitySignLEFT,  // <
	InequalitySignRIGHT,  //  >
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
	void printToken(std::ofstream& out);
	char getType();
	Token(TokenType tokent, int l, int c, char* info);
	Token(TokenType tokent, int l, int c, int value);
	void typeToString(TokenType typ);
	virtual ~Token();
};

#endif /* SCANNER_INCLUDES_TOKEN_H_ */
