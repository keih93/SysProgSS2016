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
public:
	Parser(Scanner* scan);
	virtual ~Parser();
	int accept(TokenType T);
	int expect(TokenType T);
	int isOP();
	int isEXP();
	int isSTATEMENT();
	int isSTATEMENTS();
	int isDECL();
	int isDECLS();
	int isPROG();
	void nextToken();
};

#endif /* PARSER_H_ */
