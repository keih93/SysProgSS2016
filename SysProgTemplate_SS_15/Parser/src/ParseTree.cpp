/*
 * ParseTree.cpp
 *
 *  Created on: Sep 17, 2018
 *      Author: mani1019
 */

#include "../includes/ParseTree.h"

ParseTree::ParseTree() {

}

ParseTree::~ParseTree() {

}

Node* ParseTree::getProg() {
	return this->prog;
}

void ParseTree::setProg(Node* prog) {
	this->prog = prog;
}

