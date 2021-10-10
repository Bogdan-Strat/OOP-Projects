//
// Created by bogdan on 04.05.2021.
//

#ifndef BIBLIOTECA_BIBLIOTECA_H
#define BIBLIOTECA_BIBLIOTECA_H
#include<iostream>
#include<string>

using namespace std;

class Biblioteca {
private:
    string m_numeBiblioteca;
    string m_numeDirectorBiblioteca;
public:
    Biblioteca();
    Biblioteca(string numeBiblioteca, string numeDirectorBiblioteca);

    virtual ~Biblioteca();
};


#endif //BIBLIOTECA_BIBLIOTECA_H
