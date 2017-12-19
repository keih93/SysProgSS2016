/*
 * Parser.cpp
 *
 *  Created on: Dec 6, 2017
 *      Author: Quang
 */

#include "../includes/Parser.h"
#include "../../Scanner/includes/IScanner.h"
#include "../../Scanner/includes/Scanner.h"
#include "../../Scanner/includes/Token.h"
#include "../../Automat/includes/Automat.h"
#include "../../Buffer/includes/Buffer.h"
#include "../../Symboltable/includes/Symboltable.h"


Parser::~Parser(){
}

Parser::Parser(Scanner* scan){
		this->scanner = scan;
		this->tok = scan->nextToken();
	}
int Parser::isPROG(){
 if((this->isDECLS()&& this->isSTATEMENTS())|this->isSTATEMENTS()){
	 return 1;
 }
	return 0;
}

int Parser::isDECLS(){
	if(this->isDECL()){
		return 1;
	}
	return 0;
}

int Parser::isSTATEMENTS(){
	if(this->isSTATEMENT()){
		return 1;
	}
	return 0;
}

int Parser::isDECL(){
	if(this->scanner->nextToken()->){

	}
	return 0;
}

