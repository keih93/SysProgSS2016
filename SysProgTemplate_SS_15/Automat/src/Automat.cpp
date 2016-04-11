/*
 * Automat.cpp
 *
 */

#include "../includes/Automat.h"

#include <stdlib.h>

State0* State0::theState = NULL;
State1* State1::theState = NULL;
State2* State2::theState = NULL;
State3* State3::theState = NULL;
State4* State4::theState = NULL;
State5* State5::theState = NULL;
State6* State6::theState = NULL;
State7* State7::theState = NULL;
State8* State8::theState = NULL;
State9* State9::theState = NULL;
State10* State10::theState = NULL;

State0::State0() {
}

State1::State1() {
}

State2::State2() {
}

State3::State3() {
}

State4::State4() {
}

State5::State5() {
}

State6::State6() {
}

State7::State7() {
}

State8::State8() {
}

State9::State9() {
}

State10::State10() {
}


State* State0::makeState() {
	if (State0::theState == NULL)
		State0::theState = new State0();
	return State0::theState;
}

State* State1::makeState() {
	if (State1::theState == NULL)
		State1::theState = new State1();
	return State1::theState;
}

State* State2::makeState() {
	if (State2::theState == NULL)
		State2::theState = new State2();
	return State2::theState;
}

State* State3::makeState() {
	if (State3::theState == NULL)
		State3::theState = new State3();
	return State3::theState;
}

State* State4::makeState() {
	if (State4::theState == NULL)
		State4::theState = new State4();
	return State4::theState;
}

State* State5::makeState() {
	if (State5::theState == NULL)
		State5::theState = new State5();
	return State5::theState;
}
State* State6::makeState() {
	if (State6::theState == NULL)
		State6::theState = new State6();
	return State6::theState;
}

State* State7::makeState() {
	if (State7::theState == NULL)
		State7::theState = new State7();
	return State7::theState;
}

State* State8::makeState() {
	if (State8::theState == NULL)
		State8::theState = new State8();
	return State8::theState;
}

State* State9::makeState() {
	if (State9::theState == NULL)
		State9::theState = new State9();
	return State9::theState;
}

State* State10::makeState() {
	if (State10::theState == NULL)
		State10::theState = new State10();
	return State10::theState;
}

void State0::read(char c, Automat* automat) {
	switch (c) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		automat->setState(State1::makeState()); //integer
		break;
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
		automat->setState(State2::makeState()); //identifier
		break;
	case '+':
	case '-':
	case '*':
	case '<':
	case '>':
	case '!':
	case ';':
	case '(':
	case ')':
	case '{':
	case '}':
	case '[':
	case ']':
		automat->setState(State3::makeState()); //einzelnes sign ohne : und =
		break;
	case ':':
		automat->setState(State4::makeState()); //einzelnes sign ohne : und =
		break;
	case '=':
		automat->setState(State6::makeState()); //einzelnes sign ohne : und =
		break;
	case '&':
		automat->setState(State9::makeState()); //einzelnes sign ohne : und =
		break;
	case ' ':
		automat->setState(State0::makeState()); //Leerzeichen hat keine Auswirkungen
		break;
	case '\0':
		automat->stop(); //Ende des Dokuments erreicht
		break;
	default:			//fehlerhaftes Zeichen
		automat->setState(State0::makeState());
		automat->error();
		break;
	}
}

void State1::read(char c, Automat* automat) {
	switch (c) {
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			automat->setState(State1::makeState()); //integer
			break;
		case ' ':
			automat->setState(State1::makeState()); //Leerzeichen hat keine Auswirkungen
			break;
		case '\0':
			//todo
			//ungetChar(1)
			//makeToken(CharArrayInScanner) --> integer
			automat->setState(State0::makeState());
			break;
		default:			//fehlerhaftes Zeichen
			automat->setState(State0::makeState());
			//todo
			//ungetChar(1)
			//makeToken(CharArrayInScanner) --> integer
			break;
	}
}

void State2::read(char c, Automat* automat) {
	switch (c) {
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		case 'a':
		case 'b':
		case 'c':
		case 'd':
		case 'e':
		case 'f':
		case 'g':
		case 'h':
		case 'i':
		case 'j':
		case 'k':
		case 'l':
		case 'm':
		case 'n':
		case 'o':
		case 'p':
		case 'q':
		case 'r':
		case 's':
		case 't':
		case 'u':
		case 'v':
		case 'w':
		case 'x':
		case 'y':
		case 'z':
		case 'A':
		case 'B':
		case 'C':
		case 'D':
		case 'E':
		case 'F':
		case 'G':
		case 'H':
		case 'I':
		case 'J':
		case 'K':
		case 'L':
		case 'M':
		case 'N':
		case 'O':
		case 'P':
		case 'Q':
		case 'R':
		case 'S':
		case 'T':
		case 'U':
		case 'V':
		case 'W':
		case 'X':
		case 'Y':
		case 'Z':
			automat->setState(State2::makeState()); //identifier
			break;
		case ' ':
			automat->setState(State2::makeState()); //Leerzeichen hat keine Auswirkungen
			break;
		case '\0':
			//todo
			//ungetChar(1)
			//makeToken(CharArrayInScanner) -->identifier
			automat->setState(State0::makeState());
			break;
		default:				//fehlerhaftes Zeichen
			automat->setState(State0::makeState());
			//todo
			//ungetChar(1)
			//makeToken(CharArrayInScanner) -->identifier
			break;
	}
}

void State3::read(char c, Automat* automat) {
	//todo
	//ungetChar(1)
	//makeToken(CharArrayInScanner) -->sign
	automat->setState(State0::makeState());
}

void State4::read(char c, Automat* automat) {
	switch (c) {
		case '=':
			automat->setState(State5::makeState());
			break;
		case ' ':
			automat->setState(State4::makeState()); //Leerzeichen hat keine Auswirkungen
			break;
		case '\0':
			//todo
			//ungetChar(1)
			//makeToken(CharArrayInScanner) --> :
			automat->setState(State0::makeState());
			break;
		default:				//fehlerhaftes Zeichen
			automat->setState(State0::makeState());
			//todo
			//ungetChar(1)
			//makeToken(CharArrayInScanner) --> :
			break;
	}
}

void State5::read(char c, Automat* automat) {
	//todo
	//ungetChar(1)
	//makeToken(CharArrayInScanner) --> :=
	automat->setState(State0::makeState());
}

void State6::read(char c, Automat* automat) {
	switch (c) {
		case ':':
			automat->setState(State7::makeState());
			break;
		case ' ':
			automat->setState(State6::makeState()); //Leerzeichen hat keine Auswirkungen
			break;
		case '\0':
			//todo
			//ungetChar(1)
			//makeToken(CharArrayInScanner) --> =
			automat->setState(State0::makeState());
			break;
		default:				//fehlerhaftes Zeichen
			automat->setState(State0::makeState());
			//todo
			//ungetChar(1)
			//makeToken(CharArrayInScanner) --> =
			break;
	}
}

void State7::read(char c, Automat* automat) {
	switch (c) {
		case '=':
			automat->setState(State8::makeState());
			break;
		case ' ':
			automat->setState(State7::makeState()); //Leerzeichen hat keine Auswirkungen
			break;
		case '\0':
			//todo
			//ungetChar(2)
			//makeToken(CharArrayInScanner) --> =
			automat->setState(State0::makeState());
			break;
		default:				//fehlerhaftes Zeichen
			automat->setState(State0::makeState());
			//todo
			//ungetChar(2)!
			//makeToken(CharArrayInScanner) --> =
			break;
	}
}

void State8::read(char c, Automat* automat) {
	//todo
	//ungetChar(1)
	//makeToken(CharArrayInScanner) --> =:=
	automat->setState(State0::makeState());
}

void State9::read(char c, Automat* automat) {
	switch (c) {
		case '&':
			automat->setState(State10::makeState());
			break;
		case ' ':
			automat->setState(State9::makeState()); //Leerzeichen hat keine Auswirkungen
			break;
		case '\0':
			//todo
			//ungetChar(1)
			//makeToken(CharArrayInScanner) --> FehlerToken
			automat->error();
			automat->setState(State0::makeState());
			break;
		default:				//fehlerhaftes Zeichen
			automat->setState(State0::makeState());
			//todo
			//ungetChar(1)
			//makeToken(CharArrayInScanner) --> FehlerToken
			automat->error();
			break;
	}
}

void State10::read(char c, Automat* automat) {
	//todo
	//ungetChar(1)
	//makeToken(CharArrayInScanner) --> &&
	automat->setState(State0::makeState());
}



Automat::Automat() {
	State* currentState = State0::makeState();
}

Automat::~Automat() {

}

void Automat::handleChar(char c) {
	this->currentState->read(c, this);
}

void Automat::setState(State* s) {
	this->currentState = s;
}

void Automat::error() {
	//todo
}

void Automat::stop() {
	//todo
}

