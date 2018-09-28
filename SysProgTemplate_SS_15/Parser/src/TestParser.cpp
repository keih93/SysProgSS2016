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
	outfile.open("out.txt", std::ofstream::out);
	Buffer* buf = new Buffer("test.txt");
	Symboltable* sym = new Symboltable();
	Scanner* scanner = new Scanner(buf, sym);
	try {
		Parser* parser = new Parser(scanner);
		if (parser->isPROG()) {
			cout << "It is a Program" << "\n";
			parser->printOutCode();
		} else {
			cout << "It is not a Program" << "\n";
		}
	} catch (...) {
		cout << "It is not a Program" << "\n";
	}

}

