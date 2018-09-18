/*
 * ParseTree.h
 *
 *  Created on: Sep 17, 2018
 *      Author: mani1019
 */

#ifndef PARSER_SRC_PARSETREE_H_
#define PARSER_SRC_PARSETREE_H_
#include "Node.h"

class ParseTree {
public:
	ParseTree();
	virtual ~ParseTree();
	Node* getProg();
	void setProg(Node * prog);

private:
	Node* prog;
};

#endif
