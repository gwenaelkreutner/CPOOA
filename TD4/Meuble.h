//
// Created by Gwenaël KREUTNER on 07/10/2020.
//

#ifndef TD4_MEUBLE_H
#define TD4_MEUBLE_H

#include <vector>
#include <algorithm>

#include "ElementCuisine.h"
#include "Option.h"

class Meuble : public ElementCuisine{
public:
    Meuble(const std::string &designation, double prix, double largeur, double hauteur, double profondeur)
            : ElementCuisine(designation, prix) {
        _largeur = largeur;
        _hauteur = hauteur;
        _profondeur = profondeur;
    }

    Meuble(const Meuble& meuble) : ElementCuisine(meuble.getDesignation(), meuble.ElementCuisine::getPrix()){
        _largeur = meuble.getLargeur();
        _hauteur = meuble.getHauteur();
        _profondeur = meuble.getProfondeur();
        _listOption = meuble.getListOption();
    }

    ~Meuble(){
        for(Option* o: _listOption){
            free(o);
        }
    }

    Meuble* clone() const{
        return new Meuble(*this);
    }

    double getLargeur() const {
        return _largeur;
    }

    Meuble& setLargeur(double largeur) {
        _largeur = largeur;
        return *this;
    }

    double getHauteur() const {
        return _hauteur;
    }

    Meuble& setHauteur(double hauteur) {
        _hauteur = hauteur;
        return *this;
    }

    double getProfondeur() const {
        return _profondeur;
    }

    Meuble& setProfondeur(double profondeur) {
        _profondeur = profondeur;
        return *this;
    }

    const std::vector<Option*> &getListOption() const {
        return _listOption;
    }

    void ajouterOption(const Option* option){
        _listOption.push_back(option->clone());
    }

    double getPrix() const override{
        double prixTotale = ElementCuisine::getPrix();
        for(Option* option : _listOption){
            prixTotale += option->getPrix(*this);
        }

        return prixTotale;
    }

    friend std::ostream& operator <<(std::ostream& s, const Meuble& m);

private:
    double _largeur;
    double _hauteur;
    double _profondeur;
    std::vector<Option*> _listOption; // Des pointeur sur option car on peut aussi avoir des dérivés d'option
};

inline std::ostream& operator <<(std::ostream& s, const Meuble& m) {
    s << "Meuble :" << m.getDesignation() << "( " << m._largeur << " " << m._hauteur << " " << m._profondeur << std::endl;
    s << "Options :";
    for (Option* o : m.getListOption()) {
        s << " " << o->getDesignation();
    }
    s << std::endl;
    s << "Prix : " << m.getPrix() << std::endl;
    return s;
}

#endif //TD4_MEUBLE_H
