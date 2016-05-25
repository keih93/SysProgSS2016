/*
 * StringTabNode.cpp
 *
 *  Created on: May 15, 2016
 *      Author: quang
 */

#include "../includes/StringTabNode.h";
#include <stdio.h>

StringTabNode::StringTabNode() {
	this->vector = new char[512];
	this->next = NULL;
}

char* StringTabNode::getPointer() {
	return this->vector;
}

bool StringTabNode::hasNext(){
	if(this->next != NULL){
		return false;
	}
	return true;
}

StringTabNode* StringTabNode::makeNext() {
	this->next = new StringTabNode();
	return this->next;
}
StringTabNode* StringTabNode::getNext() {
	return this->next;
}
