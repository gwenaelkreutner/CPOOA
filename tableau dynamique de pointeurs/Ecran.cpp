#include "Ecran.h"
#include <stdlib.h> 
#include <stdio.h> 
#include <iostream>
#include <time.h> 
#include <cstring> 

using namespace std;

Ecran::Ecran():
    Composant(), _format(_VGA), _taille(27), _pitch (0.02){
		
	}

Ecran::Ecran(const char* desc, const int f, const int t, const double p):
	Composant(desc), _format(f), _taille(t), _pitch(p) {
}

Ecran::Ecran(const Ecran& e):
	Composant(e), _format(e._format), _taille(e._taille), _pitch(e._pitch) {
}


Ecran::~Ecran() {
}

const int Ecran::getFormat() const {
	return _format;
}

const int Ecran::getTaille() const {
	return _taille;
}

const double Ecran::getPitch() const {
	return _pitch;
}

double	Ecran::getPrix() const {
	if (_format==_VGA)
		return _taille*50+150*_pitch;
	if (_format==_SVGA)
		return _taille*60+180*_pitch;

	return _taille*80+200*_pitch;
}

const Ecran& Ecran::operator=(const Ecran& e) {
	if (this != &e) {
		Composant::operator=(e);
		_format = e._format;
		_taille = e._taille;
		_pitch = e._pitch;
	}
	return *this;
}

bool Ecran::operator==(const Ecran& e)	const {
	return Composant::operator==(e) && (_format==e._format) && (_taille==e._taille) && (_pitch==e._pitch);
}

ostream& operator<<(ostream& os, const Ecran& e) {
	os << "Ecran : ";
	e.Affiche();
	os << ";format=" << e._format << ";taille=" << e._taille << ";pitch=" << e._pitch << endl;

	return os;
}