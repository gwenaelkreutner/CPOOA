//
// Created by Gwenaël KREUTNER on 07/10/2020.
//

#ifndef TD4_OPTION_H
#define TD4_OPTION_H

#include <string>
class Meuble;

class Option{
public :
    Option(const std::string &designation){
        _designation = designation;
}

    Option(const Option& option){
        _designation = option._designation;
}

    virtual Option* clone() const = 0;

    const std::string &getDesignation() const {
        return _designation;
    }

    void setDesignation(const std::string &designation) {
        _designation = designation;
    }

    virtual double getPrix(const Meuble&) const = 0;

private :
    std::string _designation;
};

#endif //TD4_OPTION_H
