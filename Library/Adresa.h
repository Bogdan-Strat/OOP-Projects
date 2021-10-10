//
// Created by bogdan on 29.04.2021.
//

#ifndef BIBLIOTECA_ADRESA_H
#define BIBLIOTECA_ADRESA_H

#include <ostream>
#include "Informatii.h"

using namespace std;

class Adresa: public Informatii {
private:
    string m_Tara, m_Judet, m_Oras, m_Strada;
    int m_Numar;
    map<int, Adresa> m_mapIdAdresa;
    map<string, Adresa> m_mapAliasAdresa;
public:
    Adresa();
    Adresa(string Tara, string Judet, string Oras, string Strada, int Numar);

    const map<int, Adresa> &getMapIdAdresa() const;
    const map<string, Adresa> &getMapAliasAdresa() const;

    friend ostream &operator<<(ostream &os, const Adresa &adresa);
    bool operator==(const Adresa &rhs) const;

    bool adaugareInformatiiAdresa(string Tara, string Judet, string Oras, string Strada, int Numar, string Alias="");

    void stergereInformatiiId(int Id) override;
    void stergereInformatiiAlias(string Alias) override;

    bool regasireInformatiiId(int Id) override;
    bool regasireInformatiiAlias(string Alias) override;

    bool cautareInformatiiAdresa(const Adresa& Adresa);
};


#endif //BIBLIOTECA_ADRESA_H
