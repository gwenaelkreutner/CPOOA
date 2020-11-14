#include <iostream>
#include "TabAleat.h"
#include "TabAleatStl.h"
#include "NbAleat.h"
#include "NbAleatBorne.h"

using namespace std;

int main() {
	// Tests primaires de NbAleat et NbAleatBornes
	cout << "Tests de NbAleat et NbAleatBornes" << endl;
	NbAleat::init();

	NbAleat n1;
	NbAleatBorne* n2 = new NbAleatBorne(n1);
	cout << n1 << endl;
	cout << *n2 << endl;

	cout << "Regen de n2" << endl;
	n2->reGen();
	cout << *n2 << endl;

	NbAleatBorne n3(*n2);
	cout << n3 << endl;

	NbAleatBorne n4(5, 10);
	cout << n4 << endl << endl;

	// Tests primaires de TabAleat
	cout << "Tests de TabAleat" << endl;
	TabAleat t1(7);
	cout << t1 << endl;

	cout << "Ajout de n1" << endl;
	t1 += n1;
	cout << t1 << endl;
	cout << "Ajout de n2" << endl;
	t1 += *n2;
	cout << t1 << endl;

	TabAleat* t2 = new TabAleat(17, 1, 20);
	cout << *t2 << endl;

	cout << "Regen de t2" << endl;
	t2->reGen();
	cout << *t2 << endl << endl;

	// Tests primaires de TabAleatStl
	cout << "Tests de TabAleatStl" << endl;
	TabAleatStl ts1(t1);
	cout << ts1 << endl;

	cout << "Ajout de n1" << endl;
	ts1 += n1;
	cout << ts1 << endl;
	cout << "Ajout de n2" << endl;
	ts1 += *n2;
	cout << ts1 << endl;

	TabAleatStl* ts2 = new TabAleatStl(17, 1, 20);
	cout << *ts2 << endl;

	cout << "Regen de ts2" << endl;
	ts2->reGen();
	cout << *ts2 << endl;

	delete n2;
	delete t2;
	delete ts2;
}
