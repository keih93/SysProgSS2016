/*
 * Automat.cpp
 *
 */

#include "../includes/Automat.h"
#include "../../Scanner/includes/Scanner.h"
#include "../../Scanner/includes/Token.h"
#include "../../Scanner/includes/String.h"

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
State11* State11::theState = NULL;
State12* State12::theState = NULL;

State::State() {
}

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

State11::State11() {
}

State12::State12() {
}

State::~State() {

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

State* State11::makeState() {
	if (State11::theState == NULL)
		State11::theState = new State11();
	return State11::theState;
}

State* State12::makeState() {
	if (State12::theState == NULL)
		State12::theState = new State12();
	return State12::theState;
}

void State0::read(char c, Automat* automat) {
	automat->setTokenPosition();
	automat->tokenfound(0);
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
		automat->setValue(c);
		automat->countcolumn(1);
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
		automat->countcolumn(1);
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
		automat->setTokenType(c, 3);
		automat->countcolumn(1);
		automat->setState(State3::makeState()); //einzelnes sign ohne : und =
		break;
	case ':':
		automat->countcolumn(1);
		automat->setState(State4::makeState()); //:=
		break;
	case '=':
		automat->countcolumn(1);
		automat->setState(State6::makeState()); //=,=:=
		break;
	case '&':
		automat->countcolumn(1);
		automat->setState(State9::makeState()); //&&
		break;
	case ' ':
		automat->countcolumn(1);
		automat->setState(State0::makeState()); //Leerzeichen hat keine Auswirkungen
		break;
	case '\0':
		automat->stop(); //Ende des Dokuments erreicht
		break;
	case '\n':
		automat->countline(1);
		automat->resetcolumn();
		automat->setState(State0::makeState());
		break;
	case '\t':
		automat->countcolumn(8);
		automat->setState(State0::makeState());
		break;
	default:			//fehlerhaftes Zeichen
		automat->tokenfound(1);
		automat->error();
		automat->setState(State0::makeState());
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
		automat->setValue(c);
		automat->countcolumn(1);
		automat->setState(State1::makeState()); //integer
		break;
	case ' ':
		automat->tokenfound(1);
		automat->setTokenType(c, 1);
		automat->countcolumn(1);
		automat->setState(State0::makeState()); //Leerzeichen hat keine Auswirkungen
		break;
	case '\0':
		//TODO
		automat->ungetChar(1);
		automat->tokenfound(1);
		automat->setTokenType(c, 1);
		automat->setState(State0::makeState());
		break;
	case '\n':
		automat->tokenfound(1);
		automat->setTokenType(c, 1);
		automat->countline(1);
		automat->resetcolumn();
		automat->setState(State0::makeState());

		break;
	case '\t':
		automat->tokenfound(1);
		automat->setTokenType(c, 1);
		automat->countcolumn(8);
		automat->setState(State0::makeState());
		break;
	default: //fehlerhaftes Zeichen wird an Status 0 weitergeleitet
		automat->ungetChar(1);
		automat->tokenfound(1);
		automat->setTokenType(c, 1);
		automat->setState(State0::makeState()); //Statuswechsel erst nach makeToken damit man durch currentState weiß welcher Tokentyp erzeugt werden muss
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
		automat->tokenfound(1);
		automat->countcolumn(1);
		automat->setState(State2::makeState()); //identifier
		break;
	case ' ':
		automat->tokenfound(1);
		automat->setTokenType(c, 2);
		automat->countcolumn(1);
		automat->setState(State0::makeState()); //Leerzeichen hat keine Auswirkungen
		break;
	case '\n':
		automat->tokenfound(1);
		automat->setTokenType(c, 2);
		automat->countline(1);
		automat->resetcolumn();
		automat->setState(State0::makeState());
		break;
	case '\t':
		automat->tokenfound(1);
		automat->setTokenType(c, 2);
		automat->countcolumn(8);
		automat->setState(State0::makeState());
		break;
	case '\0':
		//TODO
		automat->ungetChar(1);
		automat->tokenfound(1);
		automat->setTokenType(c, 2);
		automat->setState(State0::makeState());
		break;
	default: //fehlerhaftes Zeichen wird an Status 0 weitergeleitet
		automat->ungetChar(1);
		automat->setTokenType(c, 2);
		automat->setState(State0::makeState()); //Statuswechsel erst nach makeToken damit man durch currentState weiß welcher Tokentyp erzeugt werden muss
		break;
	}
}

void State3::read(char c, Automat* automat) {
	//todo
	//fehlerhaftes Zeichen wird an Status 0 weitergeleitet
	automat->ungetChar(1);
	//makeToken(CharArrayInScanner) --> sign
	automat->tokenfound(1);
	automat->setState(State0::makeState()); //Statuswechsel erst nach makeToken damit man durch currentState weiß welcher Tokentyp erzeugt werden muss
}

void State4::read(char c, Automat* automat) {
	switch (c) {
	case '*':
		automat->countcolumn(1);
		automat->setState(State11::makeState());
		break;
	case '=':
		automat->countcolumn(1);
		automat->setState(State5::makeState());
		break;
	case ' ':
		automat->tokenfound(1);
		automat->setTokenType(c, 4);
		automat->countcolumn(1);
		automat->setState(State0::makeState());
		break;
	case '\0':
		//TODO
		automat->ungetChar(1);
		automat->tokenfound(1);
		automat->setTokenType(c, 4);
		automat->setState(State0::makeState());
		break;
	case '\n':
		automat->tokenfound(1);
		automat->setTokenType(c, 4);
		automat->countline(1);
		automat->resetcolumn();
		automat->setState(State0::makeState());
		break;
	case '\t':
		automat->tokenfound(1);
		automat->setTokenType(c, 4);
		automat->countcolumn(8);
		automat->setState(State0::makeState());
		break;
	default: //fehlerhaftes Zeichen wird an Status 0 weitergeleitet
		automat->ungetChar(1);
		automat->tokenfound(1);
		automat->setTokenType(c, 4);
		automat->setState(State0::makeState()); //Statuswechsel erst nach makeToken damit man durch currentState weiß welcher Tokentyp erzeugt werden muss
		break;
	}
}

void State5::read(char c, Automat* automat) {
	//fehlerhaftes Zeichen wird an Status 0 weitergeleitet
	automat->ungetChar(1);
	//set token type --> :=
	automat->tokenfound(1);
	automat->setTokenType(c, 5);
	automat->setState(State0::makeState()); //Statuswechsel erst nach makeToken damit man durch currentState weiß welcher Tokentyp erzeugt werden muss
}

void State6::read(char c, Automat* automat) {
	switch (c) {
	case ':':
		automat->countcolumn(1);
		automat->setState(State7::makeState());
		break;
	case ' ':
		//set token type --> =
		automat->tokenfound(1);
		automat->setTokenType(c, 6);
		automat->countcolumn(1);
		automat->setState(State0::makeState());
		break;
	case '\0':
		//TODO
		automat->ungetChar(1);
		//set token type --> =
		automat->tokenfound(1);
		automat->setTokenType(c, 6);
		automat->setState(State0::makeState());
		break;
	case '\n':
		//set token type --> =
		automat->tokenfound(1);
		automat->setTokenType(c, 6);
		automat->countline(1);
		automat->resetcolumn();
		break;
	case '\t':
		//set token type --> =
		automat->tokenfound(1);
		automat->setTokenType(c, 6);
		automat->countcolumn(8);
		break;
	default: //fehlerhaftes Zeichen wird an Status 0 weitergeleitet
		automat->ungetChar(1);
		//set token type --> =
		automat->tokenfound(1);
		automat->setTokenType(c, 6);
		automat->setState(State0::makeState()); //Statuswechsel erst nach makeToken damit man durch currentState weiß welcher Tokentyp erzeugt werden muss
		break;
	}
}

void State7::read(char c, Automat* automat) {
	switch (c) {
	case '=':
		automat->countcolumn(1);
		automat->setState(State8::makeState());
		break;
	case ' ':
		automat->ungetChar(2);
		automat->tokenfound(1);
		automat->setTokenType(c, 6);
		automat->countcolumn(1);
		automat->setState(State0::makeState()); //bleibt in State7
		break;
	case '\0':
		//todo
		automat->ungetChar(2);
		//set token type --> =
		automat->tokenfound(1);
		automat->setTokenType(c, 6);
		automat->setState(State0::makeState());
		break;
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
	case ':':
	case '&':
		//todo
		automat->ungetChar(2);
		//set token type --> =
		automat->tokenfound(1);
		automat->setTokenType(c, 6);
		automat->setState(State0::makeState());
		break;
	case '\n':
		//todo
		automat->ungetChar(2);
		//set token type --> =
		automat->tokenfound(1);
		automat->setTokenType(c, 6);
		automat->countline(1);
		automat->resetcolumn();
		automat->setState(State0::makeState());
		break;
	case '\t':
		//todo
		automat->ungetChar(2);
		//set token type --> =
		automat->tokenfound(1);
		automat->setTokenType(c, 6);
		automat->countcolumn(8);
		automat->setState(State0::makeState());
		break;
	default:
		//todo
		//fehlerhaftes Zeichen wird an Status 0 weitergeleitet
		//error();
		automat->ungetChar(2);
		//set token type --> =
		automat->tokenfound(1);
		automat->setTokenType(c, 6);
		automat->setState(State0::makeState()); //Statuswechsel erst nach makeToken damit man durch currentState weiß welcher Tokentyp erzeugt werden muss
		break;
	}
}

void State8::read(char c, Automat* automat) {
	//fehlerhaftes Zeichen wird an Status 0 weitergeleitet
	automat->ungetChar(2);
	//set token type--> =:=
	automat->tokenfound(1);
	automat->setTokenType(c, 8);
	automat->setState(State0::makeState()); //Statuswechsel erst nach makeToken damit man durch currentState weiß welcher Tokentyp erzeugt werden muss

}

void State9::read(char c, Automat* automat) {
	switch (c) {
	case '&':
		automat->countcolumn(1);
		automat->setState(State10::makeState());
		break;
	case ' ':
		//Vorherige & als Fehler bearbeiten
		automat->error();
		automat->countcolumn(1);
		automat->setState(State0::makeState());
		break;
	case '\n':
		//Vorherige & als Fehler bearbeiten
		automat->error();
		automat->countline(1);
		automat->resetcolumn();
		automat->setState(State0::makeState());
		break;
	case '\t':
		//Vorherige & als Fehler bearbeiten
		automat->error();
		automat->countcolumn(8);
		automat->setState(State0::makeState());
		break;
	case '\0':
		//Vorherige & als Fehler bearbeiten
		automat->error();
		automat->setState(State0::makeState());
		break;
	default:
		//Vorherige & als Fehler bearbeiten
		automat->error();
		automat->setState(State0::makeState());
		//& ist fehlerhaftes Zeichen
		break;
	}
}

void State10::read(char c, Automat* automat) {
	//fehlerhaftes Zeichen wird an Status 0 weitergeleitet
	automat->ungetChar(1);
	//set token type --> &&
	automat->tokenfound(1);
	automat->setTokenType(c, 10);
	automat->setState(State0::makeState());
}

void State11::read(char c, Automat* automat) {
	switch (c) {
	case '*':
		automat->countcolumn(1);
		automat->setState(State12::makeState());
		break;
	case '\n':
		automat->countline(1);
		automat->resetcolumn();
		automat->setState(State0::makeState());
		break;
	case '\t':
		automat->countcolumn(8);
		automat->setState(State0::makeState());
		break;
	case '\0':
		//todo
		automat->setState(State0::makeState());
		automat->stop();
		break;
	default: //alle ASCII Zeichen im Kommentar erlaubt
		automat->countcolumn(1);
		automat->setState(State11::makeState());
		break;
	}
}

void State12::read(char c, Automat* automat) {
	switch (c) {
	case ':':
		automat->countcolumn(1);
		automat->setState(State0::makeState());
		break;
	case '\n':
		automat->countline(1);
		automat->resetcolumn();
		automat->setState(State0::makeState());
		break;
	case '\t':
		automat->countcolumn(8);
		automat->setState(State0::makeState());
		break;
	case '\0':
		//todo
		automat->setState(State0::makeState());
		automat->stop();
		break;
	default: //alle ASCII Zeichen im Kommentar erlaubt
		automat->countcolumn(1);
		automat->setState(State11::makeState());
		break;
	}
}

Automat::Automat(IScanner* scanner) {
	this->scanner = scanner;
	this->type = ze_ro;
	this->tokenFound = 0;
	this->currentState = State0::makeState();
	this->tokenline = 1;
	this->tokencolumn = 1;
	this->currentline = 1;
	this->currentcolumn = 1;
	this->value = -1;
	}

Automat::~Automat() {

}

void Automat::resetcolumn() {
	this->currentcolumn = 0;
}

void Automat::countline(int c) {
	this->currentline += c;
}

void Automat::countcolumn(int c) {
	this->currentcolumn += c;
}

void Automat::setTokenPosition() {
	this->tokencolumn = this->currentcolumn;
	this->tokenline = this->currentline;
}

void Automat::setTokenType(char c, int i) {
	if (i == 1) {
		this->type = Integer;
	} else if (i == 2) {
		this->type = Identifier;
	} else if (i == 3) {
		switch (c) {
		case '+':
			this->type = Plus;
			break;
		case '-':
			this->type = Minus;
			break;
		case '*':
			this->type = Star;
			break;
		case '<':
		case '>':
			this->type = Chevrons;
			break;
		case '!':
			this->type = ExclamationMark;
			break;
		case ';':
			this->type = Semicolon;
			break;
		case '(':
		case ')':
			this->type = Parentheses;
			break;
		case '{':
		case '}':
			this->type = Braces;
			break;
		case '[':
		case ']':
			this->type = SquareBracket;
			break;
		}
	} else if (i == 4) {
		this->type = Colon;
	} else if (i == 5) {
		this->type = Assign;
	} else if (i == 6) {
		this->type = Equal;
	} else if (i == 8) {
		this->type = EqualSemicolonEqual;
	} else if (i == 10) {
		this->type = And;
	} else {
		this->type = Error;
	}
}

void Automat::ungetChar(int i){
	scanner->ungetChar(i);
}


void Automat::stop(){
	scanner->stop();
}


void Automat::setValue(char c) {
	int i = c;
	this->value = (this->value) * 10 + i;
}

TokenType Automat::getTokenType() {
	return this->type;
}

int Automat::getValue() {
	return this->value;
}

int Automat::getLine() {
	return this->tokenline;
}

int Automat::getColumn() {
	return this->tokencolumn;
}

void Automat::tokenfound(int i) {
	this->tokenFound = i;
}

int Automat::handleChar(char c) {
	this->currentState->read(c, this);
	return this->tokenFound;
}

void Automat::setState(State* s) {
	this->currentState = s;
}

void Automat::error() { //muss Fehlertoken erzeugen aus CharArrayInScanner
}


