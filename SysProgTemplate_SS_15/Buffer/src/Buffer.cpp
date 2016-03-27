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
	//text-file open
	fd = open(pathname, O_DIRECT);

}

Buffer::~Buffer() {
	delete[] buffer1;
	delete[] buffer2;
}

char* Buffer::getchar() {
	//lesen .txt file in dem ersten Buffer
	int stand = read(fd, buffer1, 512);
	int i = 0;
	//jedes Mal getchar aufrufen wird, einen Zeichen ausgeben
	while (i < stand) {
		return buffer1[i];
		i++;
	}
	//wenn quellcode langer als 512 ist,
	//lesen wir den file in dem zweiten Buffer
	while (stand > 512) {
		i = 0;
		stand = read(fd, buffer2, 512);

		//danach ein Zeichen von zweitem Buffer ausgeben
		while (i < stand) {
			return buffer2[i];
			i++;
		}
		i = 0;
		//nachdem zweiter Buffer voll ist
		//gehen wir zurück zu dem ersten Buffer und überschreiben den
		stand = read(fd, buffer1, 512);
		while (i < stand) {
			return buffer1[i];
			i++;
		}
	}		//while-loop beendet, wenn der File bis zum Ende gelesen wird

	return 0;

}

