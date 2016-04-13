/*
 * Automat.h
 *
 *  Created on: Jul 5, 2012
 *      Author: knad0001
 */

#ifndef Automat_H_
#define Automat_H_


class State;

class Automat{
public:
	Automat();
	virtual ~Automat();
	void handleChar(char c);
	void setState(State* s);
	void error();
	void stop();
private:
	int eof;
	State* currentState;
};

class State {
private:
	//State();
public:
	State();
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
	static State* makeState();
	virtual ~State3();
};

class State4: public State {

private:
	static State4* theState;
	State4();

public:
	void read(char c, Automat* a);
	static State* makeState();
	virtual ~State4();
};

class State5: public State {

private:
	static State5* theState;
	State5();

public:
	void read(char c, Automat* a);
	static State* makeState();
	virtual ~State5();
};

class State6: public State {

private:
	static State6* theState;
	State6();

public:
	void read(char c, Automat* a);
	static State* makeState();
	virtual ~State6();
};

class State7: public State {

private:
	static State7* theState;
	State7();

public:
	void read(char c, Automat* a);
	static State* makeState();
	virtual ~State7();
};

class State8: public State {

private:
	static State8* theState;
	State8();

public:
	void read(char c, Automat* a);
	static State* makeState();
	virtual ~State8();
};

class State9: public State {

private:
	static State9* theState;
	State9();

public:
	void read(char c, Automat* a);
	static State* makeState();
	virtual ~State9();
};


class State10: public State {

private:
	static State10* theState;
	State10();

public:
	void read(char c, Automat* a);
	static State* makeState();
	virtual ~State10();
};

class State11: public State{
private:
	static State11* theState;
	State11();
public:
	void read(char c, Automat* a);
	static State* makeState();
	virtual ~State11();
};

class State12: public State{
private:
	static State12* theState;
	State12();
public:
	void read(char c, Automat* a);
	static State* makeState();
	virtual ~State12();
};

#endif /* Automat_H_ */
