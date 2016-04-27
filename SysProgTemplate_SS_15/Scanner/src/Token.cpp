/*
 * Token.cpp
 *
 *  Created on: Apr 13, 2016
 *      Author: ngng1012
 */
#include "../includes/Token.h"


Token::Token(TokenType tokent, int l, int c,char* info){
	this->column = c;
	this->line = l;
	this->type = tokent;
	this->infokey = info;
	this->value = -1;
}

Token::Token(TokenType tokent, int l, int c,int value){
	this->column = c;
	this->line = l;
	this->type = tokent;
	this->infokey = 0;
	this->value = value;
}

Token::~Token(){

}

char Token::getType(){
	return 'F';
}




