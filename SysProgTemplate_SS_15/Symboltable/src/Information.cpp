/*
 * Information.cpp
 *
 *  Created on: May 15, 2016
 *      Author: quang
 */
#include "../includes/Information.h"

Info::Info(char* name, char* typ){
	this->name = name;
	this->typ = typ;
}

char* Info::getName(){
	return this->name;
}

void Info::setTyp(char* typ){
	this->typ = typ;
}

char* Info::getTyp(){
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
