/*
 * Buffer.h
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#ifndef BUFFER_H_
#define BUFFER_H_

class Buffer {
	char* buffer2;
	char* buffer1;
	const char* file;
	int fd;
	int pointer;
	char token;
	int stand1;
	int stand2;


public:
	Buffer(const char *pathname);
	virtual ~Buffer();
	char getchar();
	void ungetchar();

private:
	void fill(int buffer);
};

#endif /* BUFFER_H_ */
