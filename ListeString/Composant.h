#ifndef COMPOSANT_H_
#define COMPOSANT_H_
#include <vector>
#include	<iostream>
using namespace std;

class Composant {
private:
	string	_description;

public:
    Composant(); 
	Composant(const Composant&); 
	Composant(const string &);
	virtual ~Composant(); 

	const string &	getDescription() const;
	void setDescription(const string &);

	virtual double	getPrix()	const= 0; 

	const Composant& operator=(const Composant&);

	bool operator==(const Composant&) const;
	bool operator!=(const Composant& c) const {	return !(*this == c);}

	friend	ostream& operator << (ostream&, const Composant&);
	void Affiche() const;
};
extern ostream & operator << (ostream &, const Composant &);
#endif
