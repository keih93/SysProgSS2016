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
	void setName(char* name);
	char* getName();
	char* getTyp();
	void setTyp(char* typ);
};

class Info: public Information {
public:
	Info(char* name, char* typ);
	bool compareLex(char* lexem);
	void setName(char* name);
	char* getName();
	char* getTyp();
	void setTyp(char* typ);
private:
	char* typ;
	char* name;
};

#endif /* SYMBOLTABLE_INCLUDES_INFORMATION_H_ */
