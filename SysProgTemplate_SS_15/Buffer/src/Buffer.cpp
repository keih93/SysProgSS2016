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
	//text-file open
	fd = open(pathname, O_DIRECT);
	pointer = 0;
	stand = read(fd, buffer1, 512);

}

Buffer::~Buffer() {
	close(fd);
}

char Buffer::getchar() {

	if (pointer < stand) {
		token = buffer1[pointer];
		pointer++;
		return token;
	}

	else if (pointer > 512) {
		stand = read(fd,buffer1,3);
	}
	return 0;
}

