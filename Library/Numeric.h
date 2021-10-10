//
// Created by bogdan on 29.04.2021.
//

#ifndef BIBLIOTECA_NUMERIC_H
#define BIBLIOTECA_NUMERIC_H

#include <ostream>
#include "Informatii.h"

class Numeric: public Informatii {
private:
    unsigned int m_Numar;
    map<int, Numeric> m_mapId;
    map<string, Numeric> m_mapAlias;
public:
    Numeric();
    Numeric(unsigned int Numar);
    //Numeric(string Alias,unsigned int Numar);

    const map<int, Numeric> &getMMapId() const;
    const map<string, Numeric> &getMMapAlias() const;

    friend ostream &operator<<(ostream &os, const Numeric &numeric);
    Numeric operator+(Numeric const &obj);
    bool operator==(const Numeric &rhs) const;

    void adaugareInformatiiNumerice(unsigned int Numar, string Alias="") override;

    void stergereInformatiiId(int Id) override;
    void stergereInformatiiAlias(string Alias) override;

    bool regasireInformatiiId(int Id) override;
    bool regasireInformatiiAlias(string Alias) override;

    bool cautareInformatiiNumerice(const Numeric& numarNatural);



};


#endif //BIBLIOTECA_NUMERIC_H
