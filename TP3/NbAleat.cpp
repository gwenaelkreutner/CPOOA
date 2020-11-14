#include "NbAleat.h"

ostream& operator<<(ostream& os, const NbAleat& nba) {
	return nba.affiche(os);
}
