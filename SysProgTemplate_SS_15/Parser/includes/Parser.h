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
#include "Node.h"
#include "ParseTree.h"
//#include "IParser.h"
//namespace Scanner { class Scanner; };
//namespace Token {class Token; };

class Parser {
private:
	Scanner* scanner;
	Token* tok;
	ParseTree* tree;
	std::string outCode;
public:
	Parser(Scanner* scan);
	virtual ~Parser();
	bool accept(TokenType T,Node* node);
	bool acceptDecl(TokenType T,Node* node);
	int expect(TokenType T);
	bool isOP(Node* node);
	bool isEXP(Node* node);
	bool isEXPS(Node* node);
	bool isSTATEMENT(Node* node);
	bool isSTATEMENTS(Node* node);
	bool isDECL(Node* node);
	bool isDECLS(Node* node);
	bool isINDEX(Node* node);
	bool isPROG();
	bool checkOP();
	bool writeOPCode(Token* tok,int toka,int tokb);
	void nextToken();
	void nextDeclToken();
	void printOutCode();
};

#endif /* PARSER_H_ */
