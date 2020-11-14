#include "Ordinateur.h"
#include <stdlib.h> 
#include <stdio.h> 
#include <iostream>
#include <time.h> 
#include <cstring> 

using namespace std;

Ordinateur::Ordinateur(const char* desc):
	 _description(strdup(desc)),
	 _nbComp(0){
		 _composants = new Composant* [_nbComp];
}

Ordinateur::Ordinateur(const Ordinateur & o):
	_description(strdup(o._description)), _nbComp(o._nbComp){
		_composants = new Composant* [_nbComp];
	for (int i =0; i<_nbComp; i++)
		_composants [i] = (o._composants [i])->clone ();
	}

Ordinateur::~Ordinateur() {
		delete _description;
		for (int i =0; i<_nbComp; i++)
			delete _composants [i];
		delete [] _composants;
}

const char*	Ordinateur::getDescription() const {
	return _description;
}

Ordinateur Ordinateur::operator+ (Composant * c) 
	{
		Ordinateur ord (_description);
		ord._nbComp = _nbComp+1;
		for (int i =0; i<_nbComp; i++){
			ord._composants [i] = (_composants [i])->clone ();
		}
		ord._composants[_nbComp] = (c)->clone ();

		return ord;
	}


Ordinateur & Ordinateur::Supprime(const int index) {
		if ((index < 0) || (index >= _nbComp))
			throw exTP1 ("Index hors limite"); //Construction de l'exception avec son message
		{
			// j'optimise le temps et pas la place mémoire
			// je ne change pas la taille du tableau en mémoire !
			for (int i = index; i < _nbComp-1; i++)
				_composants [i] = (_composants [i+1])->clone ();
		}

		_nbComp--;
		
		return *this;
	}

Composant * Ordinateur::getcomp (int i) const
	{
		if ((i < 0) || (i >= _nbComp))
			throw exTP1 ("Index hors limite");

		return _composants [i];
	}


double	Ordinateur::getPrix()	const {
	double prix = 0;

	for (int i=0; i<_nbComp; i++)
		prix += _composants [i]->getPrix();

	return prix;
}

bool Ordinateur::operator==(const Ordinateur& o) const {
	bool	egal = true;
	int		i = 0;

	if (_nbComp!=o._nbComp)
		return false;

	while (egal && (i<_nbComp))
		egal = egal && (*(_composants[i]) == *(o._composants[i]));

	return (egal && !strcmp (_description, o._description));
}

const Ordinateur& Ordinateur::operator=(const Ordinateur& o) {
	if (this == &o)
		return *this;

	delete _description;
	_description = strdup(o._description);
		
	_nbComp = o._nbComp;

	for (int i=0; i<_nbComp; i++)
		_composants [i] = (o._composants [i])->clone ();

	return *this;
}


 ostream& operator<<(ostream& os, const Ordinateur& o) {
	os << "Ordinateur :" << o._description << "; Prix =" << o.getPrix() << endl;
	for (int i=0; i<o._nbComp; i++)
		os << *(o._composants[i]) << endl;

	return os;
}
