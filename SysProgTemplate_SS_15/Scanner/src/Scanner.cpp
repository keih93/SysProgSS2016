/*
 * Scanner.cpp
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#include "../includes/Scanner.h"
#include "../includes/Token.h"
#include "../../Automat/includes/Automat.h"
#include "../../Buffer/includes/Buffer.h"

Scanner::~Scanner() {
	// TODO Auto-generated destructor stub
}

Scanner::Scanner() {
	Buffer* buf = new Buffer("test.txt");
}


Token* Scanner::nextToken() {
//	while(automat->stop()!=1){
	return 0;
}

