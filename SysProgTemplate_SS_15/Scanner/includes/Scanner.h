/*
 * Scanner.h
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#ifndef SCANNER_H_
#define SCANNER_H_
#include "Token.h"
#include "IScanner.h"
#include "../../Automat/includes/Automat.h"
#include "../../Buffer/includes/Buffer.h"


class Scanner :public IScanner {
private:
	Buffer* buf;
	Automat* automat;
	char* buffer;
	int pointer;
	char* mkLexem();
	int end;
public:
	Scanner(Buffer* bufe);
	virtual ~Scanner();
	Token* nextToken();
	void freeToken(Token token);
	Token* mkToken(TokenType t, int l, int c, char* info);
	Token* mkToken(TokenType tokent, int l, int c, int value);
	void ungetChar(int index);
	void copyChar();
	void stop();
};

#endif /* SCANNER_H_ */
