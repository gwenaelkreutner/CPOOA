#pragma once

#include <iostream>
#include <random>
#include "time.h"

using namespace std;

class NbAleat {

private:

	int _nb;

protected:

	virtual NbAleat& setNb(int nb) {
		if (nb < 0 || nb > RAND_MAX) { throw 1; }
		_nb = nb;
		return *this;
	}

	virtual ostream& affiche(ostream& os) const { // On pourrait du coup la mettre en protected pour ne pas laisser les autres classes externes a l'heritage y acceder
		os << "NbAleat [" << _nb << "]";
		return os;
	}

public:

	static void init(unsigned int seed = (unsigned)time(NULL)) {
		srand(seed);
	}

	NbAleat() {
		_nb = rand();
	}

	NbAleat(const NbAleat& other) {
		_nb = other._nb;
	}

	virtual ~NbAleat() {}

	// Pas de operator= car pas de donnees dynamiques

	int valeur() const {
		return _nb;
	}

	operator int() const {
		return _nb;
	}

	virtual NbAleat& reGen() {
		_nb = rand();
		return *this;
	}

	virtual NbAleat* clone() const {
		return new NbAleat(*this);
	}

	// De cette maniere, on a plus qu'a redefinir affiche dans les classes filles
	friend ostream& operator<<(ostream& os, const NbAleat& nba);

	void print() const {
		affiche(cout);
	}

};

extern ostream& operator<<(ostream& os, const NbAleat& nba);