/*
 * TestParser.cpp
 *
 *  Created on: Dec 22, 2017
 *      Author: parallels
 */

//#include "../../Scanner/includes/Scanner.h"
#include "../../Scanner/includes/Token.h"
#include "../../Buffer/includes/Buffer.h"
#include "../includes/Parser.h"
#include "../../Symboltable/includes/Symboltable.h"
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>
using namespace std;

int main(int argc, char **argv) {
	std::ofstream outfile;
	outfile.open("out.code", std::ofstream::out);
	//outfile.open(argv[2], std::ofstream::out);
//	Buffer* buf = new Buffer(argv[1]);
	Buffer* buf = new Buffer("test.txt");
	Symboltable* sym = new Symboltable();
	Scanner* scanner = new Scanner(buf, sym);
	Parser* parser = new Parser(scanner);
	fprintf(stderr, "Parsing code...\n");
	if (parser->isPROG(outfile)) {
		fprintf(stderr, "Generating code...\n");
		fprintf(stderr, "Finished successfully.\n");
	}

}

