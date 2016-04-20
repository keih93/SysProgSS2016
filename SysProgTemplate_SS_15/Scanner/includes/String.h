/*
 * String.h
 *
 *  Created on: Apr 20, 2016
 *      Author: ngng1012
 */

#ifndef SCANNER_INCLUDES_STRING_H_
#define SCANNER_INCLUDES_STRING_H_

class String {
private:
	// 'String' is represented internally as a plain C-style string.
	int size;
	char* str;
public:
	String();
	String(char c);
	String(const char *);
	String(const String&);
	~String();

	char& operator[](int index);
	String& operator=(String&);
	String& operator=(int i);
	String& operator+=(String&);

};

#endif /* SCANNER_INCLUDES_STRING_H_ */
