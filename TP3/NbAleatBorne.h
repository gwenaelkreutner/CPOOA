#pragma once

#include <iostream>
#include "NbAleat.h"

using namespace std;

class NbAleatBorne : public NbAleat {

private:

	int _binf;
	int _bsup;

	void copie(const NbAleatBorne& other) {
		_binf = other._binf;
		_bsup = other._bsup;
	}

protected:

	virtual NbAleat& setNb(int nb) {
		if (nb < _binf || nb > _bsup) { throw 1; }
		NbAleat::setNb(nb);
		return *this;
	}

	virtual ostream& affiche(ostream& os) const { // On pourrait du coup la mettre en protected pour ne pas laisser les autres classes externes a l'heritage y acceder
		os << "NbAleatBorne [";
		NbAleat::affiche(os);
		os << ", " << _binf << ", " << _bsup << "]";
		return os;
	}

public:

	NbAleatBorne() : NbAleat() {
		_binf = 0;
		_bsup = RAND_MAX;
	}

	NbAleatBorne(int binf, int bsup) : NbAleat() {
		if (binf > bsup || binf < 0) { throw 1; }
		_binf = binf;
		_bsup = bsup;
		reGen();
	}

	NbAleatBorne(const NbAleatBorne& other) : NbAleat(other) {
		copie(other);
	}

	NbAleatBorne(const NbAleat& other) : NbAleat(other) {
		_binf = 0;
		_bsup = RAND_MAX;
	}

	virtual ~NbAleatBorne() {}

	// Pas de operator= car pas de donnees dynamiques

	// Pas de methode valeur

	int getBinf() const {
		return _binf;
	}

	int getBsup() const {
		return _bsup;
	}

	NbAleatBorne& setBinf(int binf) {
		if (binf > _bsup || binf < 0) { throw 1; }
		_binf = binf;
		reGen();
	}

	NbAleatBorne& setBsup(int bsup) {
		if (_binf > bsup) { throw 1; }
		_bsup = bsup;
		reGen();
	}

	// Pas de operator int()

	virtual NbAleat& reGen() {
		return setNb(rand() % (_bsup - _binf + 1) + _binf);
	}

	virtual NbAleat* clone() const {
		return new NbAleatBorne(*this);
	}

	// Pas de operator<< et print

};
