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
using namespace std;

int main(int argc, char **argv) {
	std::ofstream outfile;
//	outfile.open("out.txt", std::ofstream::out);
	outfile.open(argv[2], std::ofstream::out);
	Buffer* buf = new Buffer(argv[1]);
//	Buffer* buf = new Buffer("test.txt");
	Symboltable* sym = new Symboltable();
	Scanner* scanner = new Scanner(buf, sym);
	Token* token;
	fprintf(stderr, "processing...");
	while (scanner->getStop() == 0) {
		token = scanner->nextToken();
		if (token != NULL) {
			if (token->gettype() == Error) {
				fprintf(stderr,
						"\nunknown Token Line: %d Column: %d Symbol: %s\n",
						token->getLine(), token->getColumn(),
						token->getInfokey());
			}
			token->printToken(outfile);
		}
	}
	fprintf(stderr, "stop\n");
}

