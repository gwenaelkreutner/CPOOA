//
// Created by Gwenaël KREUTNER on 07/10/2020.
//

#ifndef TD4_PIED_H
#define TD4_PIED_H

#include "Option.h"

class Pied : public Option{
public:
    Pied(const std::string &designation, double prix) : Option(designation) {
        _prix = prix;
    }

    Pied(const Pied& p) : Option(p.getDesignation()){
        _prix = p._prix;
    }

    Option * clone() const override{
        return new Pied(*this);
    }

    double getPrix(const Meuble &m) const override;

private:
    double _prix;
};
#endif //TD4_PIED_H
