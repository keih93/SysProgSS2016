/*
 * Node.h
 *
 *  Created on: Sep 17, 2018
 *      Author: mani1019
 */

#ifndef PARSER_SRC_NODE_H_
#define PARSER_SRC_NODE_H_

#include <stdint.h>
#include <stdio.h>
#include "../../Scanner/includes/Token.h"

class Node {
public:
	enum NodeType {
		Prog, //see slide 11 for grammar
		Decls,
		Decl,
		Array,
		Statments,
		Statement,
		Exp,
		Exp2,
		Index,
		Op_exp,
		Op
	};

	Node(Token* tok);
	Node();
	virtual ~Node();
	NodeType getType();
	void setType(NodeType type);
	Token* getToken();
	void addNode(Node* node);
	Node* getNode(uint16_t i);
	Token* token;
private:
	NodeType type;
	Node* childNodes[8];
	uint16_t nodeCount;
};

#endif /* PARSER_SRC_NODE_H_ */