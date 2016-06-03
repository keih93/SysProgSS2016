#include "../includes/Symboltable.h"
#include <iostream>
using namespace std;

int main(int argc, char **argv) {

	Symboltable* symboltable;

	symboltable = new Symboltable();
	symboltable->initSymbols();
	char* first = new char[5];
	first[0] = 'a';
	first[1] = 'b';
	first[2] = 'c';
	first[3] = 'd';
	first[4] = 'f';
	char* second = new char[5];
	second[0] = 'a';
	second[1] = 'b';
	second[2] = 'c';
	second[3] = 'q';
	second[4] = 'q';
	int f = symboltable->hashFunc(first);
	int s = symboltable->hashFunc(second);
	std::cout<<f<<' '<<s<<'\n';
	symboltable->insert(second);
	symboltable->insert(first);
	symboltable->insert(second);
}
