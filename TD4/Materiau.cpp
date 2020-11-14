//
// Created by Gwenaël KREUTNER on 07/10/2020.
//

#include "Meuble.h"
#include "Materiau.h"

double Materiau::getPrix(const Meuble& meuble) const{
    return meuble.ElementCuisine::getPrix()*_majoration/100;
}