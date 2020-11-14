#ifndef ORDINATEUR
#define ORDINATEUR

#include "exTP1.h"
#include "Composant.h"

class Ordinateur {

private:
	char* _description;
    Composant ** _composants; //tableau dynamique de pointeurs
	int _nbComp;

public:
	Ordinateur(const char*);
	Ordinateur(const Ordinateur &);
	~Ordinateur();

	const char*	getDescription() const;

	Ordinateur operator+ (Composant *);
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
