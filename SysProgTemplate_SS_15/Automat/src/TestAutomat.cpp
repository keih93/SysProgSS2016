#include "../includes/Automat.h"
#include "../../Scanner/includes/IScanner.h"

#include <stdlib.h>

class TestScanner: public IScanner {
public:
	void ungetChar(int i);
	int stop();
	 ~TestScanner();
};

void TestScanner::ungetChar(int i) {

}

int TestScanner::stop() {
}

int main(int argc, char* argv[]) {

	Automat* automat;
	IScanner* scanner = new TestScanner();

	automat = new Automat(scanner);
	automat->handleChar('=');
	automat->handleChar(':');
	automat->handleChar('=');

}
