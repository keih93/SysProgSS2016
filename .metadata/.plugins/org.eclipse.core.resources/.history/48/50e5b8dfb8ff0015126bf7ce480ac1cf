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
		automat->setState(State1::makeState());
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
		automat->setState(State2::makeState());
		break;
		}
}

void State1::read(char c, Automat* a) {
	switch

}

void State2::read(char c, Automat* a) {

}

void State3::read(char c, Automat* a) {

}

void State4::read(char c, Automat* a) {

}

Automat::Automat() {
	currentstate = State0::makeState();
}

Automat::~Automat() {

}

void Automat::handlerchar(char c) {
	this->currentstate->read(c, this);
}

void Automat::setState(State* s) {
	this->currentstate = s;
}

