/*
 * Token.cpp
 *
 *  Created on: Apr 13, 2016
 *      Author: ngng1012
 */
#include "../includes/Token.h"
#include "../includes/String.h"


Token::Token(TokenType tokent, int l, int c){
	this->column = c;
	this->line = l;
	this->type = tokent;
}

Token::~Token(){

}



