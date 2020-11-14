#include "DisqueDur.h"
#include <stdlib.h> 
#include <stdio.h> 
#include <iostream>
#include <time.h> 
#include <cstring> 

using namespace std;

DisqueDur::DisqueDur(const string & desc, const double c, const int v):
	Composant(desc), _capacite(c), _vitesse(v) {
}

DisqueDur::DisqueDur(const DisqueDur& d):
	Composant(d), _capacite(d._capacite), _vitesse(d._vitesse) {
}


DisqueDur::~DisqueDur() {
}

const double DisqueDur::getCapacite() const {
	return _capacite;
}

const int DisqueDur::getVitesse() const {
	return _vitesse;
}

double DisqueDur::getPrix() const {
	return _capacite*98*_vitesse/12000;
}

const DisqueDur& DisqueDur::operator=(const DisqueDur& d) {
	if (this != &d) {
		Composant::operator=(d);
		_capacite = d._capacite;
		_vitesse = d._vitesse;
	}
	return *this;
}

bool DisqueDur::operator==(const DisqueDur& d)	const {
	return Composant::operator==(d) && (_vitesse==d._vitesse) && (_capacite==d._capacite);
}

ostream& operator<<(ostream& os, const DisqueDur& d) {
	os << "DisqueDur : ";
	d.Affiche();
	os << ";capacité=" << d._capacite << ";vitesse=" << d._vitesse <<endl;

	return os;
}