/*
 * Scanner.cpp
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#include "../includes/Scanner.h"
#include "../includes/IScanner.h"
#include "../../Automat/includes/Automat.h"
#include "../../Buffer/includes/Buffer.h"

Scanner::Scanner() {
	// TODO Auto-generated constructor stub

}

Scanner::~Scanner() {
	// TODO Auto-generated destructor stub
}

Scannerimpl::Scannerimpl() {
	Buffer* buf = new Buffer("test.txt");
	automat = new Automat();

}

Scannerimpl::~Scannerimpl() {

}

Token Scannerimpl::mkToken(TokenType tokent, int l, int c) {
	Token* token = new Token(l, c, tokent);
	return token;
}

Token Scannerimpl::nextToken() {
//	while(automat->stop()!=1){

}

