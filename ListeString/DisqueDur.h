#ifndef DISQUEDUR_H_
#define DISQUEDUR_H_

#include "Composant.h"

class DisqueDur : public Composant {
private:
	double _capacite;
	int _vitesse;

public:
	DisqueDur(const string &, const double, const int);
	DisqueDur(const DisqueDur&);
	~DisqueDur();

	const double getCapacite() const;
	const int getVitesse() const;

	double	getPrix() const;

	const DisqueDur& operator=(const DisqueDur&);
	bool operator==(const DisqueDur&) const;
	
	friend	ostream& operator << (ostream&, const DisqueDur&) ;

};
extern ostream & operator << (ostream &, const DisqueDur &);
#endif /* DISQUEDUR_H_ */