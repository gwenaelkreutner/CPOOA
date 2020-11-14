#include	"Ecran.h"
#include 	"DisqueDur.h"
#include 	"Ordinateur.h"

int main(int argc, char **argv) {
	DisqueDur	dd("Disque SATA RH15000A",1,15000);
	cout << "Description de dd : " << dd.getDescription() << endl;
	cout << "Capacité de stockage de dd : " << dd.getCapacite() << endl;
	cout << "Vitesse de dd : " << dd.getVitesse() << endl;
	cout << "Prix de dd : " << dd.getPrix() << endl;

	Ecran	*ptr_ecr = new Ecran("Ecran TFT", Ecran::_QSXGA, 27, 0.21);
	cout << *ptr_ecr << " - Prix : " << ptr_ecr->getPrix() << " €" << endl;

	//cout << endl;

	Ordinateur	ordi("Configuration bureautique");
	Ordinateur ordi1 = ordi + &dd;
	cout << ordi1 << endl;
	cout << "out" << endl;
	Ordinateur ordi2 = ordi1 + ptr_ecr;

	cout << "ordi2 : "<< ordi2 << endl;
	cout << "prix :" << ordi2.getPrix() << endl;
	
	Composant * c = ordi2.getcomp(0);
	cout << "c:"<< *c << endl;
	cout <<"prix_c :"<< c->getPrix() << " €" << endl;

	ordi2.Supprime(0);
	cout << ordi2 << endl;
}
