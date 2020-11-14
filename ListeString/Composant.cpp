#include "Composant.h"
#include <stdlib.h> 
#include <stdio.h> 
#include <iostream>
#include <time.h> 
#include <cstring> 

using namespace std;

Composant::Composant () :
    _description("C1"){ 
}

Composant::Composant(const Composant& c): 
	_description(c._description) {
}

Composant::Composant(const string & desc) :
	 _description(desc) {
}

Composant::~Composant() {
	
}

const string & Composant::getDescription()	const {
	return _description;
}

void Composant::setDescription(const string & desc) {
	if (_description!=desc) {
		_description = desc;
	}
}


const Composant& Composant::operator=(const Composant& c) {
	if (this != &c) {
		setDescription(c._description);
	}
	return *this;
}

bool	Composant::operator==(const Composant& c)	const {
	return (_description == c._description);
}

ostream& operator<<(ostream& os, const Composant& c) {
	os << "Composant :" << c._description << endl;
	return os;
}
void Composant::Affiche() const {
	cout << _description << endl;
}