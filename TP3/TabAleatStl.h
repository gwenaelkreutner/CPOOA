#pragma once

#include <iostream>
#include <vector>
#include "TabAleat.h"
#include "NbAleat.h"
#include "NbAleatBorne.h"

using namespace std;

class TabAleatStl {

private:

	vector<NbAleat*> _tab;

	TabAleatStl& copie(const TabAleatStl& other) {
		for (unsigned int i = 0; i < _tab.size(); i++) {
			_tab.push_back(other._tab[i]->clone());
		}
	}

	void destruction() {
		for (unsigned int i = 0; i < _tab.size(); i++) {
			delete _tab[i];
		}
		_tab.clear();
	}

protected:

	virtual ostream& affiche(ostream& os) const {
		os << "TabAleat [";
		os << _tab.size() << "," << endl;
		for (vector<NbAleat*>::const_iterator it = _tab.begin(); it != _tab.end(); it++) {
			os << "\t";
			os << *(*it); // it = iterateur, *it = NbAleat*, **it = valeur pointee par le pointeurNbAleat*
			os << endl;
		}
		os << "]";
		return os;
	}

public:

	TabAleatStl() {}

	TabAleatStl(int nb) {
		if (nb < 0) { throw 1; }
		for (int i = 0; i < nb; i++) {
			_tab.push_back(new NbAleat());
		}
	}

	TabAleatStl(int nb, int binf, int bsup) {
		if (nb < 0) { throw 1; }
		try {
			for (int i = 0; i < nb; i++) {
				_tab.push_back(new NbAleatBorne(binf, bsup));
			}
		} catch (int) {
			throw 2;
		}
	}

	TabAleatStl(const TabAleatStl& other) {
		copie(other);
	}

	TabAleatStl(const TabAleat& other) {
		for (int i = 0; i < other.getTabSize(); i++) {
			_tab.push_back(other[i]->clone());
		}
	}

	virtual ~TabAleatStl() {
		destruction();
	}

	TabAleatStl& operator=(const TabAleatStl& other) {
		if (this != &other) {
			destruction();
			copie(other);
		}
		return *this;
	}

	TabAleatStl& ajouter(const NbAleat& nba) {
		_tab.push_back(nba.clone());
		return *this;
	}

	TabAleatStl& operator+=(const NbAleat& nba) {
		return ajouter(nba);
	}

	const NbAleat* operator[](unsigned int i) const {
		if (i < 0 || i > _tab.size()) { throw 1; }
		return _tab[i];
	}

	NbAleat* operator[](unsigned int i) {
		if (i < 0 || i > _tab.size()) { throw 1; }
		return _tab[i];
	}

	TabAleatStl& reGen() {
		for (vector<NbAleat*>::const_iterator it = _tab.begin(); it != _tab.end(); it++) {
			(*it)->reGen();
		}
		return *this;
	}

	// De cette maniere, on a plus qu'a redefinir affiche dans les classes filles
	friend ostream& operator<<(ostream& os, const TabAleatStl& tabA);

	void print() const {
		affiche(cout);
	}

};

extern ostream& operator<<(ostream& os, const TabAleatStl& tabA);