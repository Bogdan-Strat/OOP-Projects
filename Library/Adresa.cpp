//
// Created by bogdan on 29.04.2021.
//

#include "Adresa.h"

Adresa::Adresa() {

}

Adresa::Adresa(string Tara, string Judet, string Oras, string Strada, int Numar) {
    m_Tara=Tara;
    m_Judet=Judet;
    m_Oras=Oras;
    m_Strada=Strada;
    m_Numar=Numar;
}

const map<int, Adresa> &Adresa::getMapIdAdresa() const {
    return m_mapIdAdresa;
}

const map<string, Adresa> &Adresa::getMapAliasAdresa() const {
    return m_mapAliasAdresa;
}

ostream &operator<<(ostream &os, const Adresa &adresa) {
    os<< " Tara: " << adresa.m_Tara << " Judetul: " << adresa.m_Judet
       << " Orasul: " << adresa.m_Oras << " Strada: " << adresa.m_Strada << " Numarul: " << adresa.m_Numar;
    return os;
}

bool Adresa::operator==(const Adresa &rhs) const {
    return m_Tara == rhs.m_Tara &&
           m_Judet == rhs.m_Judet &&
           m_Oras == rhs.m_Oras &&
           m_Strada == rhs.m_Strada &&
           m_Numar == rhs.m_Numar;
}

bool Adresa::adaugareInformatiiAdresa(string Tara, string Judet, string Oras, string Strada, int Numar, string Alias) {
    Adresa Adresa(Tara, Judet, Oras, Strada, Numar);
    int ok=0;

    if(Alias!=""){
        for(auto x: m_mapAliasAdresa){
            if(x.first==Alias){
                ok=1;
                break;
            }
        }
        if(ok==1){
            return false;
        }
        else{
            m_mapAliasAdresa[Alias]=Adresa;
        }
    }
    if(ok==0){
        Informatii i;
        int a=i.getId();
        m_mapIdAdresa[a]=Adresa;
    }

    return true;
}

void Adresa::stergereInformatiiId(int Id) {
    for(auto x: m_mapIdAdresa){
        if(x.first==Id){
            m_mapIdAdresa.erase(x.first);
            break;
        }
    }
}

void Adresa::stergereInformatiiAlias(string Alias) {
    map<string, Adresa> mp;
    for(auto x:m_mapAliasAdresa){
        if(x.first!=Alias){
            mp[x.first]=m_mapAliasAdresa[x.first];
        }
    }
    m_mapAliasAdresa=mp;
}

bool Adresa::regasireInformatiiId(int Id) {
    for(auto x: m_mapIdAdresa){
        if(x.first==Id)
            return true;
    }
    return false;
}

bool Adresa::regasireInformatiiAlias(string Alias) {
    for(auto x: m_mapAliasAdresa){
        if(x.first==Alias)
            return true;
    }
    return false;
}

bool Adresa::cautareInformatiiAdresa(const Adresa &Adresa) {
    for(auto x: m_mapIdAdresa){
        if(x.second==Adresa){
            return true;
        }
    }
    return false;
}
