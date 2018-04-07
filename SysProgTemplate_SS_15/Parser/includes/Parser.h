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
	 int isOP();
	 int isOP_EXP();
	int isIndex();
	int isEXP2();
	int isEXP();
	int isSTATEMENT();
	int isSTATEMENTS();
	int isARRAY();
	int isDECL();
	int isDECLS();
	int isPROG();
	void switchtoken();
};





#endif /* PARSER_H_ */
