//
// Created by bogdan on 29.04.2021.
//

#include "Matematic.h"

using namespace std;

Matematic::Matematic() {

}

Matematic::Matematic(float Real, float Imaginar){
    m_Real=Real;
    m_Imaginar=Imaginar;
}

/*Matematic::Matematic(float Real, float Imaginar, string Alias=""):Informatii(Alias) {
    m_Real=Real;
    m_Imaginar=Imaginar;
}*/

void Matematic::adaugareInformatiiMatematice(float Real, float Imaginar, string Alias) {
    Informatii i;
    Matematic numarComplex(Real, Imaginar);
    string s;
    int a=i.getId();
    int ok=0;
    if(Alias!=""){
        for(auto x: m_mapAlias){
                if(x.first==Alias){
                    ok=1;
                    s=Alias;
                    break;
                }

        }
        if(ok==1){
            m_mapAlias[Alias]=m_mapAlias[Alias]+numarComplex;
        }
        else{
            m_mapAlias[Alias]=numarComplex;
        }
    }
    if(ok==0)
        m_mapId[a]=numarComplex;

}

//vector<int> Matematic::adaugareInformatiiMatematice(float Real, float Imaginar, string Alias) {
//    Informatii i;
//    Matematic numarComplex(Real, Imaginar);
//    string s;
//    vector<int> v;
//    int a=i.getId();
//    m_mapId[a]=numarComplex;
//
//    return v;
//    int ok=0;
//    if(Alias!=""){
//        for(auto x: m_mapAlias){
//                if(x.first==Alias){
//                    ok=1;
//                    s=Alias;
//                    break;
//                }
//
//        }
//        if(ok==1){
//            m_mapAlias[Alias]=m_mapAlias[Alias]+numarComplex;
//        }
//        else{
//            m_mapAlias[Alias]=numarComplex;
//        }
//    }
//    if(m_mapAlias.size()>0){
//        for(auto x: m_mapAlias)
//            cout<<"Alias: "<<x.first<<" "<<x.second<<'\n';
//    }

ostream &operator<<(ostream &os, const Matematic &matematic) {
    os << " Partea reala: " << matematic.m_Real << " Partea imaginara: "<< matematic.m_Imaginar;
    return os;
}

Matematic Matematic::operator+(const Matematic &obj) {
        Matematic res;
        res.m_Real = m_Real + obj.m_Real;
        res.m_Imaginar = m_Imaginar + obj.m_Imaginar;
        return res;

}

const map<int, Matematic> &Matematic::getMMapId() const {
    return m_mapId;
}

const map<string, Matematic> &Matematic::getMMapAlias() const {
    return m_mapAlias;
}

void Matematic::stergereInformatiiAlias(string Alias) {
    map<string, Matematic> mp;
    for(auto x:m_mapAlias){
        if(x.first!=Alias){
            mp[x.first]=m_mapAlias[x.first];
        }
    }
    m_mapAlias=mp;
}

void Matematic::stergereInformatiiId(int Id) {
        for(auto x: m_mapId){
            if(x.first==Id){
                m_mapId.erase(x.first);
                break;
            }
        }



//for(auto x: m_mapAlias)
//    cout<<"Alias: "<<x.first<<" "<<x.second<<'\n';
}

bool Matematic::regasireInformatiiId(int Id) {
    for(auto x: m_mapId){
        if(x.first==Id)
            return true;
    }
    return false;
}

bool Matematic::regasireInformatiiAlias(string Alias) {
    for(auto x: m_mapAlias){
        if(x.first==Alias)
            return true;
    }
    return false;
}

bool Matematic::cautareInformatiiMatematice(const Matematic& numarComplex) {
    for(auto x: m_mapId){
        if(x.second==numarComplex){
            return true;
        }
    }
    return false;
}

bool Matematic::operator==(const Matematic &rhs) const {
    return  m_Real == rhs.m_Real &&  m_Imaginar == rhs.m_Imaginar;
}

bool Matematic::operator!=(const Matematic &rhs) const {
    return !(rhs == *this);
}




