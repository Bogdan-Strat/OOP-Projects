//
// Created by bogdan on 29.04.2021.
//

#ifndef BIBLIOTECA_MATEMATIC_H
#define BIBLIOTECA_MATEMATIC_H
#include <iostream>
#include <map>
#include<vector>
#include <string>
#include "Informatii.h"

using namespace  std;

class Matematic: public Informatii{
private:
    float m_Real,m_Imaginar;
    map<int, Matematic> m_mapId;
    map<string, Matematic> m_mapAlias;
public:
    Matematic();
    Matematic(float Real, float Imaginar);
    //Matematic(float Real, float Imaginar,string Alias);

    const map<int, Matematic> &getMMapId() const;
    const map<string, Matematic> &getMMapAlias() const;

    friend ostream &operator<<(ostream &os, const Matematic &matematic);
    Matematic operator + (Matematic const &obj);
    bool operator==(const Matematic &rhs) const;
    bool operator!=(const Matematic &rhs) const;

    void adaugareInformatiiMatematice(float Real, float Imaginar, string Alias="") override;
//    vector<int> adaugareInformatiiMatematice(float Real, float Imaginar, string Alias="");

    void stergereInformatiiId(int Id) override;
    void stergereInformatiiAlias(string Alias) override;

    bool regasireInformatiiId(int Id) override;
    bool regasireInformatiiAlias(string Alias) override;

    bool cautareInformatiiMatematice(const Matematic& numarComplex);

};


#endif //BIBLIOTECA_MATEMATIC_H
