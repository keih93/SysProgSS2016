#include "../includes/Buffer.h"
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

int main(int argc, char **argv) {

	Buffer*  buffer;

	buffer = new Buffer("test.txt");
	//buffer->getchar();
	char testchar = buffer->getchar();
	char testchar2 = buffer->getchar();
	std::cout<<testchar;
	std::cout<<testchar2;



	//char* testbuffer = new char[512];
	//posix_memalign((void**)&testbuffer,512,1024);
	//int fd = open("test.txt",O_DIRECT);
	//int stand = read(fd,testbuffer,512);
	//std::cout<<fd;
	//std::cout<<stand;
	//std::cout<<testbuffer;

}
