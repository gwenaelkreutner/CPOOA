//
// Created by Gwenaël KREUTNER on 07/10/2020.
//

#ifndef TD4_MATERIAU_H
#define TD4_MATERIAU_H

#include <ostream>
#include "Option.h"

class Materiau : public Option{
public :
    Materiau(const std::string &designation, double majoration) : Option(designation){
        _majoration = majoration;
    }

    Materiau(const Materiau& m) : Option(m.getDesignation()){
        _majoration = m._majoration;
    }

    Option * clone() const override{
        return new Materiau(*this);
    }

    double getMajoration() const {
        return _majoration;
    }

    void setMajoration(double majoration) {
        _majoration = majoration;
    }

    double getPrix(const Meuble& meuble) const override;

private :
    double _majoration;
};

#endif //TD4_MATERIAU_H
