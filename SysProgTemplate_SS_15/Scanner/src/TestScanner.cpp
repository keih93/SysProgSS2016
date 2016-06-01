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
	//std::cout<<'T';
	Scanner* scanner;
	Buffer* buf = new Buffer("test.txt");
	Symboltable* sym = new Symboltable();
	scanner = new Scanner(buf, sym);
	int i = 0;
	Token* token1;
	while(i<36){
		token1=scanner->nextToken();
		token1->printToken();
		i++;
	}
	std::cout << '\n';

	token1=scanner->nextToken();


}

