//
// Created by Gwenaël KREUTNER on 07/10/2020.
//

#ifndef TD4_POIGNEE_H
#define TD4_POIGNEE_H

#include <ostream>
#include "Option.h"

class Poignee : public Option{

public:
    Poignee(double prix, const std::string &designation) : Option(designation) {
        _prix = prix;
    }

    Poignee(const Poignee& p) : Option(p.getDesignation()){
        _prix = p._prix;
    }

    Option * clone() const override{
        return new Poignee(*this);
    }

    double getPrix(const Meuble &m) const override;

private :
    double _prix;
};

#endif //TD4_POIGNEE_H
