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
#include <iostream>
#include <fstream>

Buffer::Buffer(const char *pathname) {
	token = '\0';
	file = pathname;
	posix_memalign((void**) &buffer1, 512, 512);
	posix_memalign((void**) &buffer2, 512, 512);
	fd = open(pathname, O_DIRECT);
	fill(1);


}

void Buffer::fill(int buffer){
	if (buffer == 1){
		stand1 = read(fd, buffer1, 512);
		pointer = 0;
		stand2 = 0;
	}
	if (buffer == 2){
		stand2 = read(fd, buffer2, 512);
		pointer = 512;
		stand1 = 0;
	}
}

Buffer::~Buffer() {
	close(fd);
}

char* Buffer::getBuffer2(){
	return this->buffer1;
}

char Buffer::getchar() {

	if (pointer < stand1) {
		token = buffer1[pointer];
		pointer++;
		return token;
	}

	else if (pointer >= 512 && pointer < 512 +stand2) {
		token = buffer2[pointer - 512];
		pointer++;
		return token;
	}

	else if (pointer == stand1) {
		fill(2);
		if (pointer >= 512 && pointer < 512 +stand2) {
				token = buffer2[pointer - 512];
				pointer++;
				return token;
		}
	}

	else if(pointer == 512 + stand2){
		fill(1);
		if (pointer < stand1) {
				token = buffer1[pointer];
				pointer++;
				return token;
		}
	}
	return '\0';
}

//*void Buffer::ungetchar() {}

