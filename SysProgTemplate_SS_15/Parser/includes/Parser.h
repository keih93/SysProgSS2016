/*
 * Parser.h
 *
 *  Created on: Dec 6, 2017
 *      Author: Quang
 */

#ifndef PARSER_H_
#define PARSER_H_
#include "../../Scanner/includes/Scanner.h"
#include "../../Scanner/includes/Token.h"
#include <list>
//#include "IParser.h"
//namespace Scanner { class Scanner; };
//namespace Token {class Token; };

class Parser {
private:
	Scanner* scanner;
	Token* tok;
	int parenthesesCounter;
public:
	Parser(Scanner* scan);
	virtual ~Parser();
	int accept(TokenType T);
	int expect(TokenType T);
	bool isOP();
	bool isEXP();
	bool isEXPS();
	bool isSTATEMENT();
	bool isSTATEMENTS();
	bool isDECL();
	bool isDECLS();
	bool isPROG();
	void nextToken();
};

#endif /* PARSER_H_ */
