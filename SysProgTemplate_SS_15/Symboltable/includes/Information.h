/*
 jj * Information.h
 *
 *  Created on: May 12, 2016
 *      Author: quang
 */

#ifndef SYMBOLTABLE_INCLUDES_INFORMATION_H_
#define SYMBOLTABLE_INCLUDES_INFORMATION_H_

class Information {
public:
	bool compareLex(char* lexem);
	char* getName();
	void setName();
	char* getLexem();
	void setLexem();
	char* getTyp();
	void setTyp();
private:
	char* lexem;
	char* typ;
	char* name;
};

//class Info: public Information {
//public:
//	bool compareLex(char* lexem);
//	char* getName();
//	void setName();
//	char* getLexem();
//	void setLexem();
//	char* getTyp();
//	void setTyp();
//private:
//	char* lexem;
//	char* typ;
//	char* name;
//};

#endif /* SYMBOLTABLE_INCLUDES_INFORMATION_H_ */
