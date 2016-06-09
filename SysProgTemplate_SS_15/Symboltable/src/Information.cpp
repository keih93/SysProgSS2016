/*
 * Information.cpp
 *
 *  Created on: May 15, 2016
 *      Author: quang
 */
#include "../includes/Information.h"

Info::Info(){
	this->name ='\0';
	this->typ = ze_ro;
}

void Info::setName(char* name){
	this->name = name;
}

char* Info::getName(){
	return this->name;
}

void Info::setTyp(TokenType typ){
	this->typ = typ;
}

TokenType Info::getTyp(){
	return this->typ;
}

bool Info::compareLex(char* lexem){
	char* tempname = this->name;
	while(lexem[0] != '\0' && tempname[0] != '\0'){
		if(lexem[0] != tempname[0]){
			return false;
		}
		lexem++;
		tempname++;
	}
	if(lexem[0] == tempname[0]){
		return true;
	}
	return false;
}
