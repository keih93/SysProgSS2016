/*
 * Token.cpp
 *
 *  Created on: Apr 13, 2016
 *      Author: ngng1012
 */
#include "../includes/Token.h"

Token::Token(int l, int c, TokenType type){
	this->column = c;
	this->line = l;
	this->type = type;
}

Token::~Token(){

}



