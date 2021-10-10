//
// Created by bogdan on 04.05.2021.
//

#include "Biblioteca.h"
#include<string>
using namespace std;
Biblioteca::Biblioteca() {

}

Biblioteca::Biblioteca(string numeBiblioteca, string numeDirectorBiblioteca) {
    m_numeBiblioteca=numeBiblioteca;
    m_numeDirectorBiblioteca=numeDirectorBiblioteca;
}

Biblioteca::~Biblioteca() {

}
