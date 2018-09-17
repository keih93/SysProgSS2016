/*
 * ParseTree.h
 *
 *  Created on: Sep 17, 2018
 *      Author: mani1019
 */

#ifndef PARSER_SRC_PARSETREE_H_
#define PARSER_SRC_PARSETREE_H_

class ParseTree {
public:
	ParseTree(Node* prog);
	virtual ~ParseTree();
	Node* getProg();

private:
	Node* prog;
};

#endif
