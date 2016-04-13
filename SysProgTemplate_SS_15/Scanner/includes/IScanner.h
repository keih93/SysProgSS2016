/*
 * IScanner.h
 *
 *  Created on: Apr 13, 2016
 *      Author: ngng1012
 */

#ifndef SCANNER_INCLUDES_ISCANNER_H_
#define SCANNER_INCLUDES_ISCANNER_H_
#include "Token.h"

class IScanner {
public:
	IScanner();
	virtual ~IScanner();
	Token mkToken(TokenType tktype);
	void ungetChar(int index);
	void stop();
};
#endif /* SCANNER_INCLUDES_ISCANNER_H_ */
