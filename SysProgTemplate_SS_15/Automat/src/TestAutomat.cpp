#include "../includes/Automat.h"
#include "../../Scanner/includes/IScanner.h"

#include <stdlib.h>
#include <iostream>
#include <fstream>

class TestScanner: public IScanner {
public:
	void ungetChar(int i);
	void stop();
	~TestScanner();
};

void TestScanner::ungetChar(int i) {

}

void TestScanner::stop() {
}

int main(int argc, char* argv[]) {

	Automat* automat;
	IScanner* scanner = new TestScanner();

	automat = new Automat(scanner);
	automat->handleChar('-');
	automat->handleChar('1');
	automat->handleChar(' ');
//	automat->handleChar('7');
//	automat->handleChar('4');
//	automat->handleChar('8');
//	automat->handleChar('3');
//	automat->handleChar('6');
//	automat->handleChar('4');
//	automat->handleChar('8');
	long i = automat->getValue();
	std::cout << i;


}
