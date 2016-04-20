


#include "String.h"


String::String() {
	size = 0;
	str = new char[1];
	str[0] = '\0';
}


String::String(char c) {
	size = 1;
	str = new char[2];
	str[0] = c;
	str[1] = '\0';
}

String::String(const char *s) {
	//array zählen
	while (*s != '\0') {
		s++;
		size++;
	}
	//zeiger züruck auf dem 1.Stelle
	s = s - size;
	str = new char[size + 1];
	//jede Zeichen kopieren
	for (int i = 0; i < size; i++) {
		str[i] = s[i];
	}

}


String::String(const String& s) {
	//size kopieren
	this->size = s.size;
	str = new char[size];
	//char array kopieren
	this->str = s.str;
}



String::~String() { delete[] str; }

char& String::operator[](int index) {
	return str[index];
}

String& String::operator=(String& s) {

	if (this != &s) {
		delete[] str;
		size = s.size;
		str = new char[size];
		for (int i = 0; i < size; i++) {
		str[i] = s.str[i];
	}
	}
	return *this;
}


String& String::operator+=(String& s) {
	//Zwischen speichern
	int osize = size;
	char* temp = new char[osize];

	for (int i = 0; i < osize; i++) {
		temp[i] = str[i];
	}

	size += s.size;

	delete[] str;

	str = new char[size];

	for (int i = 0; i < osize; i++) {
		str[i] = temp[i];
	}

	for (int i = 0; i < s.size; i++) {
		str[osize + i] = s.str[i];
	}

	return *this;
}
