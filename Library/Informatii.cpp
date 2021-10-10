//
// Created by bogdan on 29.04.2021.
//

#include "Informatii.h"

Informatii::Informatii() {
    m_Id=++m_nextId;
    m_Alias="";
}

int Informatii::m_nextId = 0;
/*Informatii::Informatii(const Informatii& orig) {
    m_Id = orig.m_Id;
}

Informatii& Informatii::operator=(const Informatii& orig) {
    m_Id = orig.m_Id;

    return(*this);
}*/


//Informatii::Informatii() {
//    //m_Id=Id;
//    m_Alias= "";
//}

Informatii::Informatii( string Alias) {
   // m_Id=Id;
    m_Alias=Alias;
}

int Informatii::getId() const {
    return m_Id;
}

string Informatii::getAlias() const{
    return m_Alias;
}

int Informatii::setId(int Id) {
    m_Id=Id;
}

string Informatii::setAlias(string Alias) {
    m_Alias=Alias;
}

void Informatii::adaugareInformatiiMatematice(float Real, float Imaginar, string Alias) {

}

void Informatii::stergereInformatiiAlias(string Alias) {

}

void Informatii::stergereInformatiiId(int Id) {

}

bool Informatii::regasireInformatiiId(int Id) {

}

bool Informatii::regasireInformatiiAlias(string Alias) {

}

void Informatii::adaugareInformatiiNumerice(unsigned int Numar, string Alias) {

}


