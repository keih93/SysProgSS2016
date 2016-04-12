/*
 * Scanner.h
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#ifndef SCANNER_H_
#define SCANNER_H_

class Scanner {
public:
	Scanner();
	virtual ~Scanner();
	Token nextToken();
	void freeToken(Token token);
};

class ISScanner {
public:
	ISScanner();
	virtual ~ISScanner();
	mkToken(Tokentype tktype);
	ungetChar(int index);
	stop();
};

#endif /* SCANNER_H_ */
