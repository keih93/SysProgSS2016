/*
 * Leaf.cpp
 *
 *  Created on: 18.09.2018
 *      Author: nils
 */

#include "../includes/Leaf.h"


Leaf::Leaf(Token* tok) {
	this->token = tok;
}

Leaf::~Leaf() {
}

TokenType Leaf::getTokenType() {
	return this->tokenType;
}

void Leaf::setTokenType(TokenType tokenType) {
	this->tokenType = tokenType;
}

