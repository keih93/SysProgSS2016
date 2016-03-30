/*
 * Buffer.cpp
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#include "../includes/Buffer.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

Buffer::Buffer(const char *pathname) {

	file = pathname;
	buffer1 = new char[512];
	buffer2 = new char[512];
	posix_memalign((void**) &buffer1, 512, 1024);
	posix_memalign((void**) &buffer2, 512, 1024);
	fd = open(pathname, O_DIRECT);
	pointer = 0;
	stand1 = read(fd, buffer1, 512);
	stand2 = read(fd, buffer2, 512);

}

Buffer::~Buffer() {
	close(fd);
}

char Buffer::getchar() {
	if (stand1 < 512) {
		buffer1[stand1] = '\0';
	}

	if (stand2 < 512) {
		buffer2[stand2] = '\0';
	}

	if (pointer < 512) {
		token = buffer1[pointer];
		pointer++;
		return token;
	}

	if (pointer >= 512 && pointer < 1024) {
		token = buffer2[pointer - 512];
		pointer++;
		return token;
	}

	if (pointer == 1024) {
		pointer = 0;
		stand1 = read(fd, buffer1, 512);
		stand2 = read(fd, buffer2, 512);
		return this->getchar();
	}

	return 0;
}

