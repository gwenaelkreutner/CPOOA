//
// Created by Gwenaël KREUTNER on 07/10/2020.
//

#ifndef TD4_ILOT_H
#define TD4_ILOT_H

#include <string>
#include <vector>

#include "Meuble.h"

class Ilot{
public :
    Ilot(const std::string &designation){
        _designation = designation;
    }

    ~Ilot(){
        for(Meuble* m: _assemblageMeuble){
            delete m;
        }


    }

    double getPrix() const{
        double prixTotale = 0;
        for(auto meuble : _assemblageMeuble){
            prixTotale += meuble->getPrix();
        }

        return prixTotale;
}

    void ajouterMeuble(const Meuble* meuble){
        _assemblageMeuble.push_back(meuble->clone());
}

    friend std::ostream& operator <<(std::ostream& s, const Ilot& i) {
        s << "Ilot :" << i._designation << std::endl;
        s << "Options :";
        for (Meuble* o : i._assemblageMeuble) {
            s << *o;
        }
        s << std::endl;
        s << "Prix totale : " << i.getPrix() << std::endl;
        return s;
    }
private :
    std::string _designation;
    std::vector<Meuble*> _assemblageMeuble;
};

#endif //TD4_ILOT_H
