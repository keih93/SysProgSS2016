#include "../includes/Symboltable.h"
#include <iostream>
using namespace std;

int main(int argc, char **argv) {

	Symboltable* symboltable;

	symboltable = new Symboltable();
	symboltable->initSymbols();
	char* firsttyp = new char[5];
		firsttyp[0] = 'a';
		firsttyp[1] = 'b';
		firsttyp[2] = 'c';
		firsttyp[3] = 'd';
		firsttyp[4] = 'f';
	symboltable->insert(firsttyp);
	}
