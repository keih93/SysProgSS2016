/*
 * Node.cpp
 *
 *  Created on: Sep 17, 2018
 *      Author: mani1019
 */

#include "../includes/Node.h"

Node::Node(Token* tok) {
	this->token = tok;
}

Node::~Node() {
}

Node::NodeType Node::getType() {
	return this->type;
}

void Node::setType(NodeType type) {
	this->type = type;
}

Token* Node::getToken() {
	return this->token;
}

void Node::addNode(Node* node) {
	childNodes[nodeCount] = node;
	nodeCount++;
}
Node* Node::getNode(uint16_t i) {
	return childNodes[i];
}

