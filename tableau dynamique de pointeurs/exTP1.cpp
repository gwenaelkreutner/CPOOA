#include "exTP1.h"

/**
Fonction de surcharge pour l'affichage <<
*/
ostream & operator << (ostream &s, const exTP1 &e)
{
	s << e.getMsg ();
	return s;
}

