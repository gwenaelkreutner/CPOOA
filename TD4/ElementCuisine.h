//
// Created by Gwenaël KREUTNER on 07/10/2020.
//

#ifndef TD4_ELEMENTCUISINE_H
#define TD4_ELEMENTCUISINE_H

#include <iostream>

class ElementCuisine{
public:
    ElementCuisine(const std::string &designation, double prix) {
        _designation = designation;
        _prix = prix;
    }

    const std::string &getDesignation() const {
        return _designation;
    }

    ElementCuisine& setDesignation(const std::string &designation) {
        ElementCuisine::_designation = designation;
        return *this;
    }

    virtual double getPrix() const {
        return _prix;
    }

    ElementCuisine& setPrix(double prix) {
        ElementCuisine::_prix = prix;
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &os, const ElementCuisine &cuisine) {
        os << "_designation: " << cuisine._designation << " _prix: " << cuisine._prix;
        return os;
    }

private :
    std::string _designation;
protected:
    double _prix;
};


#endif //TD4_ELEMENTCUISINE_H
