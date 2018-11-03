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
#include "string.h"
//#include "IParser.h"
//namespace Scanner { class Scanner; };
//namespace Token {class Token; };

class Parser {
private:
	Scanner* scanner;
	Token* tok;
	ParseTree* tree;
	int labelCounter;
	int index;
	Token* indexToken[512];
	int indexCounter;
public:
	Parser(Scanner* scan);
	virtual ~Parser();
	bool accept(TokenType T, Node* node);
	bool acceptDecl(TokenType T, Node* node);
	int expect(TokenType T);
	bool isOP(Node* node, std::ofstream& out);
	bool isEXP(Node* node, std::ofstream& out, bool isIndex);
	bool isEXPS(Node* node, std::ofstream& out, bool isIndex);
	bool isSTATEMENT(Node* node, std::ofstream& out);
	bool isSTATEMENTS(Node* node, std::ofstream& out);
	bool isDECL(Node* node, std::ofstream& out);
	bool isDECLS(Node* node, std::ofstream& out);
	bool isINDEX(Node* node, std::ofstream& out);
	bool isPROG(std::ofstream& out);
	bool checkOP(Token* token);
	bool writeOPCode(Token* tok, int toka, int tokb, std::ofstream& out);
	void nextToken();
	void nextDeclToken();
	void printCode(std::ofstream& out, const char* code);
	void printIntCode(std::ofstream& out, int code);
	bool isIndexEXPS(std::ofstream& out);
	bool isIndexEXP(std::ofstream& out);
	bool acceptIndex(TokenType T);
	bool isIndexOP(std::ofstream& out);
	bool isIndexINDEX(std::ofstream& out);
};

#endif /* PARSER_H_ */
