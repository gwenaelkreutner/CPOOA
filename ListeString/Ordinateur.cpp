#include "Ordinateur.h"
#include <stdlib.h> 
#include <stdio.h> 
#include <iostream>
#include <time.h> 
#include <cstring> 
#include <vector>

using namespace std;


Ordinateur::Ordinateur(const string& desc):
	 _description(desc)
	 {
}

Ordinateur::Ordinateur(const Ordinateur & o):
	_description(o._description){
	for (int i (0); i< _composants.size(); i++)
		_composants [i] = o._composants [i];
	}

Ordinateur::~Ordinateur() {
		
}

const string &	Ordinateur::getDescription() const {
	return _description;
}

Ordinateur Ordinateur::operator+ (Composant * c) 
	{
		Ordinateur ord (_description);
		
		ord._composants = _composants;
	
		ord._composants.push_back(c);

		return ord;
	}


Ordinateur & Ordinateur::Supprime(const int index) {
		if ((index < 0) || (index >= _composants.size()))
			throw exTP1 ("Index hors limite"); 
		{
			vector<Composant*>::iterator it = _composants.begin() + index;
			_composants.erase(it);
		}
		
		return *this;
	}

Composant* Ordinateur::getcomp (int i) const
	{
		if ((i < 0) || (i >= _composants.size()))
			throw exTP1 ("Index hors limite");

		return _composants [i];
	}


double	Ordinateur::getPrix()	const {
	double prix = 0;

	for (int i(0); i < _composants.size(); i++)
		prix += _composants [i]->getPrix();

	return prix;
}

bool Ordinateur::operator==(const Ordinateur& o) const {

bool result = std::equal(_composants.begin(), _composants.end(), o._composants.begin());
return (result && (_description == o._description));
}

const Ordinateur& Ordinateur::operator=(const Ordinateur& o) {
	if (this == &o)
		return *this;

	_description = o._description;
		
	_composants = o._composants;

	return *this;
}


 ostream& operator<<(ostream& os, const Ordinateur& o) {
	os << "Ordinateur :" << o._description << "; Prix =" << o.getPrix() << endl;
	for(vector<Composant*>:: const_iterator it= o._composants.begin(); it!= o._composants.end(); ++it)
	
	{
		os << *it << " ";
	}

	return os;
}
