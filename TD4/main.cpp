#include <iostream>
#include "Ilot.h"
#include "Materiau.h"
#include "Pied.h"

int main()
{
    Ilot* bar = new Ilot("BX 160");

    Meuble* m1 = new Meuble("FA 80", 49, 80, 70, 56);
    Materiau* materiauM1 = new Materiau("Chene", 10);
    Pied* piedM1 = new Pied("Pieds Inox", 5);
    m1->ajouterOption(materiauM1);
    m1->ajouterOption(piedM1);

    Meuble* m2 = new Meuble(*m1);

    bar->ajouterMeuble(m1);
    bar->ajouterMeuble(m2);

    std::cout << *bar;

}
