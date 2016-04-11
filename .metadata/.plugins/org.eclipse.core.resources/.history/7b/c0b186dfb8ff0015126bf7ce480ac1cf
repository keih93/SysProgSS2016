/*
 * Automat.h
 *
 *  Created on: Jul 5, 2012
 *      Author: knad0001
 */

#ifndef Automat_H_
#define Automat_H_

class State;

class Automat {
public:
	Automat();
	virtual ~Automat();
	void handlerchar(char c);
	void setState(State* s);
private:
	State* currentstate;
};

class State {
public:
	virtual void read(char c, Automat* a) = 0;
	virtual ~State();
};

class State0: public State {

private:
	static State0* theState;
	State0();

public:
	void read(char c, Automat* a);
	static State* makeState();
	virtual ~State0();

};

class State1: public State {

private:
	static State1* theState;
	State1();

public:
	void read(char c, Automat* a);
	static State* makeState();
	virtual ~State1();
};

class State2: public State {

private:
	static State2* theState;
	State2();

public:

	void read(char c, Automat* a);
	static State* makeState();
	virtual ~State2();
};
class State3: public State {

private:
	static State3* theState;
	State3();

public:
	void read(char c, Automat* a);
	State* makeState();
	virtual ~State3();
};

class State4: public State {

private:
	static State4* theState;
	State4();

public:
	void read(char c, Automat* a);
	State* makeState();
	virtual ~State4();
};

#endif /* Automat_H_ */
