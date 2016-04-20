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
	//IScanner();
	//virtual ~IScanner();
	//Token mkToken(TokenType tktype);
	virtual void ungetChar(int index) = 0;
	virtual void stop() = 0;
};
#endif /* SCANNER_INCLUDES_ISCANNER_H_ */
