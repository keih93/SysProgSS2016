/*
 * Information.cpp
 *
 *  Created on: May 15, 2016
 *      Author: quang
 */
#include "../includes/Information.h"

Info::Info(){
	this->name ='\0';
	this->typ = NOTYP;
}

void Info::setName(char* name){
	this->name = name;
}

char* Info::getName(){
	return this->name;
}

void Info::setTyp(Typ typ){
	this->typ = typ;
}

Typ Info::getTyp(){
	return this->typ;
}

bool Info::compareLex(char* lexem){
	char* tempname = this->name;
	while(lexem != "\0" && tempname != "\0"){
		if(lexem != tempname){
			return false;
		}
		lexem++;
		tempname++;
	}
	if(lexem == tempname){
		return true;
	}
	return false;
}
