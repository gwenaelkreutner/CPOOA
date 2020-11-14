#ifndef COMPOSANT_H_
#define COMPOSANT_H_

#include	<iostream>
using namespace std;

/*Classe mère*/

class Composant {
private:
	char*	_description;

public:
    Composant(); 
	Composant(const Composant&); 
	Composant(const char*);
	virtual ~Composant(); 
	
	//virtual copy constructor
	virtual Composant* clone() const = 0;

	const char*	getDescription() const;
	void setDescription(const char*);

	virtual double	getPrix()	const= 0; 

	const Composant& operator=(const Composant&);

	bool operator==(const Composant&) const;
	bool operator!=(const Composant& c) const {	return !(*this == c);}

	friend	ostream& operator << (ostream&, const Composant&);
	void Affiche() const;
	
	
};
extern ostream & operator << (ostream &, const Composant &);
#endif
