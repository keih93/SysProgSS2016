/*
 * Scanner.h
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#ifndef SCANNER_H_
#define SCANNER_H_
#include "Token.h"

class Scanner {
private:

public:
	Scanner();
	virtual ~Scanner();
	Token* nextToken();
	void freeToken(Token token);

	void ungetChar(int index);
	void stop();
};

#endif /* SCANNER_H_ */
