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

	Buffer* buffer;

	buffer = new Buffer("test.txt");
	char a;
	int i;
	while (i < 2710) {
		a = buffer->getchar();
		std::cout << a;
		i++;
	}

	//buffer->getchar();
	//buffer->getchar();

	//char* testbuffer = new char[512];
	//posix_memalign((void**)&testbuffer,512,1024);
	//int fd = open("test.txt",O_DIRECT);
	//int stand = read(fd,testbuffer,512);
	//std::cout<<fd;
	//std::cout<<stand;
	//std::cout<<testbuffer;

}
