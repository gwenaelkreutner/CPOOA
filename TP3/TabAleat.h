#pragma once

#include <iostream>
#include "NbAleatBorne.h"
#include "NbAleat.h"

using namespace std;

class TabAleat {

private:

	int _n;
	int _nMax; // On va partir sur le principe qu'on augmente la taille en puissance de 2 pour "gagner" du temps
	NbAleat** _tab;

	int findNextPowerOfTwo(int nb) {
		int power = 1;
		while (power < nb) { power *= 2; }
		return power;
	}

	TabAleat& copie(const TabAleat& other) {
		_n = other._n;
		_nMax = other._nMax;
		_tab = new NbAleat*[_nMax];
		for (int i = 0; i < _n; i++) {
			_tab[i] = other._tab[i]->clone();
		}
	}

	void destruction() {
		for (int i = 0; i < _n; i++) {
			delete _tab[i];
		}
		delete _tab;
	}

protected:

	virtual ostream& affiche(ostream& os) const {
		os << "TabAleat [";
		os << _n << ", " << _nMax << "," << endl;
		for (int i = 0; i < _n; i++) {
			os << "\t";
			os << *(_tab[i]);
			os << endl;
		}
		os << "]";
		return os;
	}

public:

	TabAleat() {
		_n = 0;
		_nMax = 1;
		_tab = new NbAleat*[_nMax];
	}

	TabAleat(int nb) {
		if (nb < 0) { throw 1; }
		_n = nb;
		_nMax = findNextPowerOfTwo(nb);
		_tab = new NbAleat*[_nMax];
		for (int i = 0; i < nb; i++) {
			_tab[i] = new NbAleat();
		}
	}

	TabAleat(int nb, int binf, int bsup) {
		if (nb < 0) { throw 1; }
		_n = nb;
		_nMax = findNextPowerOfTwo(nb);
		_tab = new NbAleat*[_nMax];
		try {
			for (int i = 0; i < nb; i++) {
				_tab[i] = new NbAleatBorne(binf, bsup);
			}
		} catch (int) {
			throw 2;
		}
	}

	TabAleat(const TabAleat& other) {
		copie(other);
	}

	virtual ~TabAleat() {
		destruction();
	}

	TabAleat& operator=(const TabAleat& other) {
		if (this != &other) {
			destruction();
			copie(other);
		}
		return *this;
	}

	TabAleat& ajouter(const NbAleat& nba) {
		if (_n == _nMax) { 
			_nMax *= 2;
			NbAleat** _tabTemp = new NbAleat*[_nMax];
			for (int i = 0; i < _n; i++) {
				_tabTemp[i] = _tab[i];
			}
			delete[] _tab;
			_tab = _tabTemp;
		}
		_tab[_n] = nba.clone();
		_n++;
		return *this;
	}

	TabAleat& operator+=(const NbAleat& nba) {
		return ajouter(nba);
	}

	const NbAleat* operator[](int i) const {
		if (i < 0 || i > _n) { throw 1; }
		return _tab[i];
	}

	NbAleat* operator[](int i) {
		if (i < 0 || i > _n) { throw 1; }
		return _tab[i];
	}

	TabAleat& reGen() {
		for (int i = 0; i < _n; i++) {
			_tab[i]->reGen();
		}
		return *this;
	}

	int getTabSize() const {
		return _n;
	}

	NbAleat** getTab() const {
		return _tab;
	}

	// De cette maniere, on a plus qu'a redefinir affiche dans les classes filles
	friend ostream& operator<<(ostream& os, const TabAleat& tabA);

	void print() const {
		affiche(cout);
	}

};

extern ostream& operator<<(ostream& os, const TabAleat& tabA);