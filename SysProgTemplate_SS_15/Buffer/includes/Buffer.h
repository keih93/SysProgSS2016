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
	int fd;

public:
	Buffer(const char *pathname);
	virtual ~Buffer();
	char* getchar();
	char* ungetchar();
};

#endif /* BUFFER_H_ */
