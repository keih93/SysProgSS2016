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
	while (i < 31869) {
		a = buffer->getchar();
		std::cout << a;
		i++;
	}
	//std::cout<< buffer->getBuffer2();



}
