//
// Created by Gwenaël KREUTNER on 07/10/2020.
//

#include "Pied.h"
#include "Meuble.h"

double Pied::getPrix(const Meuble &m) const {
    if(m.getLargeur() > 80){
     return 6*_prix;
    } else {
    return 4*_prix;
    }
}

