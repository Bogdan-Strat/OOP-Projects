//
// Created by bogdan on 29.04.2021.
//

#include "Numeric.h"

Numeric::Numeric() {

}

Numeric::Numeric( unsigned int Numar){
    m_Numar=Numar;
}

const map<int, Numeric> &Numeric::getMMapId() const {
    return m_mapId;
}

const map<string, Numeric> &Numeric::getMMapAlias() const {
    return m_mapAlias;
}

ostream &operator<<(ostream &os, const Numeric &numeric) {
    os<< " Numarul: " << numeric.m_Numar;
    return os;
}

bool Numeric::operator==(const Numeric &rhs) const {
    return m_Numar == rhs.m_Numar;
}

Numeric Numeric::operator+(const Numeric &obj) {
    Numeric Rezultat;
    Rezultat.m_Numar=m_Numar+obj.m_Numar;
    return Rezultat;
}

void Numeric::adaugareInformatiiNumerice(unsigned int Numar, string Alias) {
    Informatii i;
    Numeric numarNatural(Numar);
    int a=i.getId();
    int ok=0;
    if(Alias!="") {
        for (auto x: m_mapAlias) {
            if(x.first==Alias){
                ok = 1;
                break;
            }

        }

        if (ok == 1) {
            m_mapAlias[Alias] = m_mapAlias[Alias] + numarNatural;
        } else {
            m_mapAlias[Alias] = numarNatural;

        }
    }
    if(ok==0)
        m_mapId[a]=numarNatural;
}

void Numeric::stergereInformatiiId(int Id) {
    for(auto x: m_mapId){
        if(x.first==Id){
            m_mapId.erase(x.first);
            break;
        }
    }
}

void Numeric::stergereInformatiiAlias(string Alias) {
    map<string, Numeric> mp;
    for(auto x:m_mapAlias){
        if(x.first!=Alias){
            mp[x.first]=m_mapAlias[x.first];
        }
    }
    m_mapAlias=mp;
}

bool Numeric::regasireInformatiiId(int Id) {
    for(auto x: m_mapId){
        if(x.first==Id)
            return true;
    }
    return false;
}

bool Numeric::regasireInformatiiAlias(string Alias) {
    for(auto x: m_mapAlias){
        if(x.first==Alias)
            return true;
    }
    return false;
}

bool Numeric::cautareInformatiiNumerice(const Numeric &numarNatural) {
    for(auto x: m_mapId){
        if(x.second==numarNatural){
            return true;
        }
    }
    return false;
}





