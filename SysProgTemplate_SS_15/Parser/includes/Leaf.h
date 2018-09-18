/*
 * Leaf.h
 *
 *  Created on: 18.09.2018
 *      Author: nils
 */

#ifndef PARSER_SRC_LEAF_H_
#define PARSER_SRC_LEAF_H_
#include "Node.h"
#include "../../Symboltable/includes/Information.h"

class Leaf: public Node {
public:
	Leaf(Token* tok);
	virtual ~Leaf();
	void setTokenType(TokenType tokenType);
	TokenType getTokenType();
private:
	TokenType tokenType;
};

#endif /* PARSER_SRC_LEAF_H_ */
