/*
 * StringTabNode.h
 *
 *  Created on: May 12, 2016
 *      Author: quang
 */

#ifndef SYMBOLTABLE_INCLUDES_STRINGTABNODE_H_
#define SYMBOLTABLE_INCLUDES_STRINGTABNODE_H_

class StringTabNode {
public:
	StringTabNode();
	bool hasNext();
	StringTabNode* makeNext();
	StringTabNode* getNext();
	char* getPointer();
private:
	StringTabNode* next;
	char* vector;
};

#endif /* SYMBOLTABLE_INCLUDES_STRINGTABNODE_H_ */
