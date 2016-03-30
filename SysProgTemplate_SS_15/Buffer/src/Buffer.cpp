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
		return buffer1[pointer];
		pointer++;
	}

	else if (stand > 512) {
		stand = read(fd, buffer2, 512);
	}

	else if (stand)

		while (stand > 512) {
			pointer = 0;
			stand = read(fd, buffer2, 512);

			//danach ein Zeichen von zweitem Buffer ausgeben
			while (pointer < stand) {
				return buffer2[pointer];
				pointer++;
			}
			pointer = 0;
			//nachdem zweiter Buffer voll ist
			//gehen wir zurück zu dem ersten Buffer und überschreiben den
			stand = read(fd, buffer1, 512);
			while (pointer < stand) {
				return buffer1[pointer];
				pointer++;
			}
		}		//while-loop beendet, wenn der File bis zum Ende gelesen wird
	return 0;
}

