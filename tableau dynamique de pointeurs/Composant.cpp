#include "Composant.h"
#include <stdlib.h> 
#include <stdio.h> 
#include <iostream>
#include <time.h> 
#include <cstring> 

using namespace std;

Composant::Composant () :
    _description(strdup("C1")){ 
}

Composant::Composant(const Composant& c): 
	_description(strdup(c._description)) {
}

Composant::Composant(const char* desc) :
	 _description(strdup(desc)) {
}

Composant::~Composant() {
	delete _description;
}

const char*	Composant::getDescription()	const {
	return _description;
}

void Composant::setDescription(const char* desc) {
	if (_description!=desc) {
		delete _description;
		_description = strdup(desc);
	}
}


const Composant& Composant::operator=(const Composant& c) {
	if (this != &c) {
		setDescription(c._description);
	}
	return *this;
}

bool	Composant::operator==(const Composant& c)	const {
	return !strcmp(_description, c._description);
}

ostream& operator<<(ostream& os, const Composant& c) {
	os << "Composant :" << c._description << endl;

	return os;
}
void Composant::Affiche() const {
	cout << _description << endl;
}