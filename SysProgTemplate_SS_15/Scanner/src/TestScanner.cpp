#include "../includes/Scanner.h"
#include "../includes/Token.h"
#include "../../Buffer/includes/Buffer.h"
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

int main(int argc, char **argv) {
	std::ofstream outfile;
	outfile.open(argv[2], std::ofstream::out);
	Buffer* buf = new Buffer(argv[1]);
	Symboltable* sym = new Symboltable();
	Scanner* scanner = new Scanner(buf, sym);
	Token* token1;
	while (scanner->getStop() == 0) {
		token1 = scanner->nextToken();
		token1->printToken(outfile);
	}
	outfile.flush();
	outfile.close();

}

