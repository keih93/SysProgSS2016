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

Buffer::Buffer(const char *pathname) {
	
	buffer1 = new char[512];
	buffer2 = new char[512];
	fd = open(pathname, O_DIRECT);
		
}

Buffer::~Buffer() {
	delete[] buffer1;
	delete[] buffer2;
}

char* Buffer::getchar() {
	stand = read(fd, buffer1, 512);
	int i = 0;
	while(i<stand){
	return buffer1[i];
	i++;
	}
	while(stand>512){
	i = 0;
	stand = read(fd,buffer2, 512);
	while(i<stand){
		return buffer2[i];
		i++;
	}
	i=0;
	stand = read(fd,buffer1, 512);
	while(i<stand){
	return buffer1[i];
	i++;
	}
	}
		
}

