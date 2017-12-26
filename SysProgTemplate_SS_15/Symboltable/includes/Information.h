/*
 jj * Information.h
 *
 *  Created on: May 12, 2016
 *      Author: quang
 */

#ifndef SYMBOLTABLE_INCLUDES_INFORMATION_H_
#define SYMBOLTABLE_INCLUDES_INFORMATION_H_

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
	KeywordIF,
	KeywordWHILE,
	KeywordELSE,
	KeywordREAD,
	KeywordWRITE,
	Error //Fehlertoken
};

class Information {
public:
	bool compareLex(char* lexem);
	void setName(char* name);
	char* getName();
	TokenType getTyp();
	void setTyp(TokenType typ);
};

class Info: public Information {
public:
	Info();
	bool compareLex(char* lexem);
	void setName(char* name);
	char* getName();
	TokenType getTyp();
	void setTyp(TokenType typ);
private:
	TokenType typ;
	char* name;
};

#endif /* SYMBOLTABLE_INCLUDES_INFORMATION_H_ */
