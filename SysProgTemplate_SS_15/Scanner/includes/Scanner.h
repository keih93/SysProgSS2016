/*
 * Scanner.h
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#ifndef SCANNER_H_
#define SCANNER_H_
#include "IScanner.h"
#include "Token.h"

class Scanner {
private:

public:
	Scanner();
	virtual ~Scanner();
	Token nextToken();
	void freeToken(Token token);
};

class Scannerimpl: public Scanner, IScanner {
private:
	Automat* automat;
public:
	Scannerimpl();
	virtual ~Scannerimpl();
	Token nextToken();
	void freeToken(Token token);
	Token mkToken(TokenType token,int l, int c);
	void ungetChar(int index);
	void stop();
};
#endif /* SCANNER_H_ */
