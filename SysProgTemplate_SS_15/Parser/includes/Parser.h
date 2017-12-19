/*
 * Parser.h
 *
 *  Created on: Dec 6, 2017
 *      Author: Quang
 */

#ifndef PARSER_INCLUDES_PARSER_H_
#define PARSER_INCLUDES
#include "../../Scanner/includes/IScanner.h"
#include "../../Scanner/includes/Scanner.h"
#include "../../Scanner/includes/Token.h"
#include "../../Automat/includes/Automat.h"
#include "../../Buffer/includes/Buffer.h"
#include "../../Symboltable/includes/Symboltable.h"

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
};





#endif /* PARSER_INCLUDES_PARSER_H_ */
