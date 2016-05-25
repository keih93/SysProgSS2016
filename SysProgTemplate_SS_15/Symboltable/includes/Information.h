/*
 jj * Information.h
 *
 *  Created on: May 12, 2016
 *      Author: quang
 */

#ifndef SYMBOLTABLE_INCLUDES_INFORMATION_H_
#define SYMBOLTABLE_INCLUDES_INFORMATION_H_

typedef enum {
	TOKENWHILE, TOKENIF, INT, NOTYP
}Typ;

class Information {
public:
	bool compareLex(char* lexem);
	void setName(char* name);
	char* getName();
	Typ getTyp();
	void setTyp(Typ typ);
};

class Info: public Information {
public:
	Info();
	bool compareLex(char* lexem);
	void setName(char* name);
	char* getName();
	Typ getTyp();
	void setTyp(Typ typ);
private:
	Typ typ;
	char* name;
};

#endif /* SYMBOLTABLE_INCLUDES_INFORMATION_H_ */
