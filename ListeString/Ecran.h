#ifndef ECRAN_H_
#define ECRAN_H_

#include "Composant.h"

class Ecran : public Composant {
public:
	static const int	_VGA = 1;
	static const int	_SVGA = 2;
	static const int	_QSXGA = 3;

private:
	int		_format;
	int		_taille;	// en pouces
	double	_pitch;	// en mm

public:
    Ecran();
	Ecran(const string &, const int, const int, const double);
	Ecran(const Ecran&);
	~Ecran();

	const int	getFormat()	const;
	const int	getTaille()	const;
	const double getPitch() const;

	double getPrix() const;

	const Ecran& operator=(const Ecran&);
	bool operator==(const Ecran&) const;

	friend	ostream& operator << (ostream&, const Ecran& ) ;

};
extern ostream & operator << (ostream &, const Ecran &);
#endif 
