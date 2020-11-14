#ifndef ORDINATEUR_H_
#define ORDINATEUR_H_
#include "exTP1.h"
#include "Composant.h"


class Ordinateur {
public:
	

private:
	string _description;
    vector<Composant*> _composants ; //tableau de composants

public:
	Ordinateur(const string &);
	Ordinateur(const Ordinateur &);
	~Ordinateur();

	const string &	getDescription() const;

	Ordinateur operator+ (Composant*);
	Composant* getcomp (int) const;
	Ordinateur & Supprime(const int);

	double getPrix() const;

	bool operator==(const Ordinateur&)const;
	bool operator!=(const Ordinateur& o) const { return !(*this==o); }

	const Ordinateur& operator=(const Ordinateur&);

	friend ostream&	operator<<(ostream&, const Ordinateur &);
};
extern ostream & operator << (ostream &, const Ordinateur &);
#endif
